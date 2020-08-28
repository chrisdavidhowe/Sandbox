//
// Created by Chris Howe on 8/26/20.
//

#include <memory>
#include <vector>
#include <mutex>
#include "cmath"

#define MALLOC_MAX_BYTES 500
#define METADATA_SIZE sizeof(struct MemoryMetadata)
char MALLOC_POOL[MALLOC_MAX_BYTES];
mutex memory_access_lock;

int nextPowerOfTwo(int x)
{
    return pow(2, ceil( log(x) / log(2) ) );
}

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
    MemoryMetadata* newBlock = (MemoryMetadata*)(current + s);
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
        printf("First time MyMalloc has been called : Initializing with %d maximum bytes\n", MALLOC_MAX_BYTES);
        myMallocInit(sizeof(MALLOC_POOL));
    }

    MemoryMetadata* currentBlock;
    void* mem_ptr;
    currentBlock = memoryHead;

    while ((currentBlock->free == 0) || (currentBlock->size < s) && (currentBlock->next != nullptr))
    {
        currentBlock = currentBlock->next;
    }

    if (currentBlock->size == s)
    {
        currentBlock->free = 0;
        currentBlock->size = s;
        mem_ptr = (void*)(currentBlock + METADATA_SIZE);
        printf("Allocating Memory Block %p \n", mem_ptr);
    }
    else if (currentBlock->size > s)
    {
        memorySplit(currentBlock, s);
        mem_ptr = (void*)(currentBlock + METADATA_SIZE);
        printf("Allocating Memory Block %p \n", mem_ptr);
    }
    else
    {
        printf("NOT ENOUGH MEMORY AVAILABLE IN VIRTUAL HEAP!\n");
        return nullptr;
    }

    memory_access_lock.unlock();

    return mem_ptr;
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
