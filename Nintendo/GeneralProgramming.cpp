//
// Created by Chris Howe on 8/26/20.
//

#include <string>
#include <memory>

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

void container_of(void* ptr, void* type, void* member)
{
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */

}

void myMemMove(void* src, void* dest, size_t size)
{
    char* char_src = (char*)src;
    char* char_dest = (char*)dest;

    for (int i = 0; i < size; ++i)
    {
        char_dest[i] = char_src[i];
    }
}