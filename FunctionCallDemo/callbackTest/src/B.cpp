#include "../include/B.h"

void B::doLongTask()
{
    mThread = std::thread(&B::doAsync,this);
}

B::~B()
{
    if(mThread.joinable())
    {
        mThread.join();
    }
}
