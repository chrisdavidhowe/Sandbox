//
// Created by Chris Howe on 8/26/20.
//

#pragma once

#include <stack>

namespace Nintendo {
    class Queue {
    public:

        Queue(int size) : size_(size) {};
        void enqueue(int val);
        int dequeue();
        int size();

    private:
        std::stack<int> s1;
        std::stack<int> s2;
        int size_ {0};
    };
}