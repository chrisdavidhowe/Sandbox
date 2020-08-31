//
// Created by Chris Howe on 8/26/20.
//

#include "Queue.h"

using namespace Nintendo;

void Queue::enqueue(int val)
{
    if (s1.size() <= size_) {

        while (!s1.empty())
        {
            s2.push(s1.top() );
            s1.pop();
        }

        s1.push(val);

        while (!s2.empty())
        {
            s1.push(s2.top() );
            s2.pop();
        }
    }
    else
    {
        printf("Queue reached max!");
    }
}

int Queue::size()
{
    return s1.size();
}

int Queue::dequeue()
{
    int x = s1.top();
    s1.pop();
    return x;
}

