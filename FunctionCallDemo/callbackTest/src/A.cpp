#include "../include/A.h"
#include "../include/B.h"

void A::doTask()
{
    pB = std::make_unique<B>();
    pB->setCallback(std::bind(&A::doneWork,this));
    pB->doLongTask();
}
