//
// Created by Chris Howe on 8/26/20.
//

#include <memory>
#include <vector>
#include <mutex>

#define ARENA_START
#define ARENA_SIZE 500
#define METADATA_SIZE sizeof(struct MemoryMetadata)
char MALLOC_POOL[ARENA_SIZE];
mutex memory_access_lock;

struct MemoryMetadata
{
    uint32_t size {0};
    bool free {0};
    MemoryMetadata* next {nullptr};
    void* ptr;
};

void* memory;
MemoryMetadata* memoryHead;

void memorySplit(MemoryMetadata* current, size_t s)
{
    MemoryMetadata* newBlock = (MemoryMetadata*)((char*)current + s);
    newBlock->size = (current->size) - s;
    newBlock->free = 1;
    newBlock->next = current->next;

    current->size = s;
    current->free = 0;
    current->next = newBlock;
}

void memoryCombine()
{
    //combines empty adjacent memory blocks
    MemoryMetadata* currentBlock = memoryHead;
    while (currentBlock->next != nullptr)
    {
        if ( (currentBlock->free) && (currentBlock->next->free) )
        {
            currentBlock->size += (currentBlock->next->size);
            currentBlock->next = currentBlock->next->next;
        } else {
            currentBlock = currentBlock->next;
        }
    }
}

void myMallocInit(int s)
{
    memory = MALLOC_POOL;
    memoryHead = (MemoryMetadata*)(memory);
    memoryHead->next = nullptr;
    memoryHead->size = s;
    memoryHead->free = 1;
}

void* myMalloc(size_t s)
{
    memory_access_lock.lock();
    if (memoryHead == nullptr)
    {
        printf("First time MyMalloc has been called : Initializing with %d maximum bytes\n", ARENA_SIZE);
        myMallocInit(sizeof(MALLOC_POOL));
    }

    MemoryMetadata* currentBlock;
    currentBlock = memoryHead;

    while ((currentBlock->free == 0) || (currentBlock->size < s) && (currentBlock->next != nullptr))
    {
        currentBlock = currentBlock->next;
    }

    if (currentBlock->size == s)
    {
        currentBlock->free = 0;
        currentBlock->size = s;
        currentBlock->ptr = (void*)(currentBlock + METADATA_SIZE);
        printf("Allocating Memory Block %p \n", currentBlock->ptr);
    }
    else if (currentBlock->size > s)
    {
        memorySplit(currentBlock, s);
        currentBlock->ptr = (void*)(currentBlock + METADATA_SIZE);
        printf("Allocating Memory Block %p \n", currentBlock->ptr);
    }
    else
    {
        printf("NOT ENOUGH MEMORY AVAILABLE IN VIRTUAL HEAP!\n");
        return nullptr;
    }

    memory_access_lock.unlock();
    return currentBlock->ptr;
}

void myFree(void* p)
{
    memory_access_lock.lock();
    MemoryMetadata* currentBlock = move( (MemoryMetadata*)p - METADATA_SIZE);
    currentBlock->free = 1;
    memset(currentBlock + METADATA_SIZE, 'x', sizeof(char) * currentBlock->size);
    printf("Freeing Memory Block %p \n", currentBlock);
    memoryCombine();
    memory_access_lock.unlock();
}