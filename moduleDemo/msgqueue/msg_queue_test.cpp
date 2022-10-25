#include "msg_queue.h"

int main()
{
    MsgQueue<int> msgQueue;
    msgQueue.Push(1);
    msgQueue.Push(2);
    msgQueue.Pop();
    msgQueue.Pop();
}