#include "include/A.h"
#include "include/B.h"
#include <iostream>

/**
 *  主体功能 : 实现C++回调函数demo
 *  类A: 完成某项任务，但是该任务存在一些耗时的工作，于是转交给类B做“累活”，并传递回调函数
 *  类B: 负责做耗时工作，完成后调用回调函数，通知调用方
 **/
int main()
{
    A a;
    a.doTask();
    std::cout<<"Hello"<<std::endl;
}
 