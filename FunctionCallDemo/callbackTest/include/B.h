#pragma once
#ifndef _B_H_
#define _B_H_
#include <functional>
#include <thread>
#include <iostream>
#include <mutex>

class B
{
public:
    void doLongTask();
    void setCallback(const std::function<void(void)> &cb){
        // 涉及到线程共享变量  需要锁
        std::lock_guard<std::mutex> guard(mMutex);
        mCallback = cb;
    }
    ~B();
private:
    void doAsync();
    std::thread mThread;
    std::function<void(void)> mCallback = NULL;
    std::mutex mMutex;
};


#endif