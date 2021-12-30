#pragma once
#ifndef _A_H_
#define _A_H_
#include <memory>
#include "./B.h"
#include <iostream>

class A
{
public:
    void doTask();
private:
    void doneWork(); // 工作完成时调用
    std::unique_ptr<B> pB{nullptr};
};

void A::doneWork()
{
    std::cout<<"A 已收到 B做完工作的通知"<<std::endl;
}

#endif