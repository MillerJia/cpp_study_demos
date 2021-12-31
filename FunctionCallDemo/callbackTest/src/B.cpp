#include "../include/B.h"

void B::doLongTask()
{
    mThread = std::thread(&B::doAsync,this);
}

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

B::~B()
{
    if(mThread.joinable())
    {
        mThread.join();
    }
}
