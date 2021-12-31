#include "../include/A.h"
#include "../include/B.h"

void A::doTask()
{
    pB = std::make_unique<B>();
    pB->setCallback(std::bind(&A::doneWork,this));
    pB->doLongTask();
}

void A::doneWork()
{
    std::cout<<"A 已收到 B做完工作的通知"<<std::endl;
}
