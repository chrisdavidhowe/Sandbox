//
// Created by Chris Howe on 8/26/20.
//

#include <string>
#include <memory>
#include "stddef.h"

using namespace std;


void copyWithoutTemp(int& x, int& y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}

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
        output += hex[(array[i] >> 4) & 0xF];
        output += hex[(array[i] & 0xF)];
        output += ":";
    }

    output += hex[(array[size-1] >> 4) & 0xF];
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


/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct this is embedded in.
 * @member:	the name of the member within the struct.
 *
 */
    // struct s address = <address of struct variable> - <offset of that variable in the struct>

    // To get the OFFSET of that variable in the containing struct
    // we create a zeroed struct ( i.e., a temp struct with the address 0x0 )
    // so the addresses of any variables in the struct corresponds to the offset of that variable.
    // a zeroed struct of the correct type with address at zero


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

//Perfect Forwarding, use case for RValue Referencing
template<typename T, typename Arg>
shared_ptr<T> factory(Arg&& arg)
{
    return shared_ptr<T>(new T(std::forward<Arg>(arg)));
}

void reverseWordsInPlace(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }

    i = 0;
    j = 0;
    int n = 0;
    for (int k = 0; k < s.length(); ++k)
    {
        if (s[k] == ' ')
        {
            j = k - 1;
            while (i < j)
            {
                swap(s[i++], s[j--]);
            }
            i = k + 1;
            n = i;
        }
    }

    j = s.length() - 1;
    while (n < j)
    {
        swap(s[n++], s[j--]);
    }
}