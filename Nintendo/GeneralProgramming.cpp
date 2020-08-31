//
// Created by Chris Howe on 8/26/20.
//

#include <string>
#include <memory>
#include "stddef.h"

using namespace std;

string byteArrayToString(int* array, int size)
{
    char output[size * 10];

    for (int i = 0; i < size; ++i)
    {
        sprintf(output + strlen(output), "%d ", array[i]);
    }

    printf("Byte Output %s\n", output);
    return output;
}

string hexArrayToString(uint8_t* array, int size)
{
    string output = "";
    const string hex = "0123456789ABCDEF";

    for (int i = 0; i < size - 1; ++i)
    {
        //second nibble
        output += hex[(array[i] >> 4) & 0xF];
        //first nibble
        output += hex[(array[i] & 0xF)];
        output += ":";
    }

    //second nibble
    output += hex[(array[size-1] >> 4) & 0xF];
    //first nibble
    output += hex[(array[size-1] & 0xF)];

    printf("Hex Output %s\n", output.c_str());
    return output;
}


void checkEndian()
{
    int x = 1;
    char* cp = (char*)(&x);
    if ( cp[0] )
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("BIG Endian\n");
    }
}

// returns the address of a parent structure from
// a member of the structure
// implements the following
// struct s address = <address of struct variable> - <offset of that variable in the struct>

struct DLL_Node {
    int value = 1;
    DLL_Node* prev = nullptr;
    DLL_Node* next = nullptr;
};

void* container_of(void* p, void* t, void* m)
{
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
    //struct s address = <address of struct variable> - <offset of that variable in the struct>
    //To get the OFFSET of that variable in the containing struct
    // we create a zeroed struct ( i.e., a temp struct with the address 0x0 )
    // so the addresses of any variables in the struct corresponds to the offset of that variable.
    //a zeroed struct of the correct type with address at zero
    //typeof(((t*)0)->member) *member_ptr = p;
    //return (t*) ( (char*)member_ptr - offsetof(t, m);
}

#define offsetof(type, member) ((size_t) &((type*)0)->member)

#define container_of(ptr, type, member) \
const typeof( ((type *)0)->member ) *member_ptr = (ptr); \
return (type *)( (char *)member_ptr - offsetof(type, member) );

void myMemMove(void* src, void* dest, size_t size)
{
    char* char_src = (char*)src;
    char* char_dest = (char*)dest;

    for (int i = 0; i < size; ++i)
    {
        char_dest[i] = char_src[i];
    }
}