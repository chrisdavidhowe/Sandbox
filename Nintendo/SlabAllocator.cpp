//
// Created by Chris Howe on 9/1/20.
//


//N is some arbitrary compile time constant Implement these O(1) space & time functions:

#define N 100

struct T {
    int data;
    char *ptr;
} storage[N];

T* alloc()
{
    int i = 0;
    char* ptr = storage[0].ptr;
    while (ptr != nullptr)
    {
        ++i;
    }

}
void free(T *t) {
    int i = 0;
    while (&storage[i] != t)
    {
        ++i;
    }
    storage[i].ptr = nullptr;
    storage[i].data = 0;
}