//
// Created by Chris Howe on 9/3/20.
//

#ifndef SANDBOX_SINGLETON_H
#define SANDBOX_SINGLETON_H

class Singleton
{
public:
    Singleton* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton;
        }
        return instance;
    }

    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

#endif //SANDBOX_SINGLETON_H
