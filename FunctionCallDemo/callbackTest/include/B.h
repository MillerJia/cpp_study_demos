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

void B::doAsync()
{
    std::cout<<"B is doing job..."<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"B finished the job~"<<std::endl;
    {
        // 涉及到线程共享变量  需要锁
        std::lock_guard<std::mutex> guard(mMutex);
        if(mCallback)
        {
            mCallback();
        }
    }
    
}

#endif