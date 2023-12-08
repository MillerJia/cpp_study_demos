#include "thread_safe_queue.h"
#include <chrono>
#include <thread>
#include <iostream>

void AddData(ThreadSafeQueue<int>& queue) {
  for (int i=0;i<=10;i++) {
    queue.Push(i);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void ReadData(ThreadSafeQueue<int>& queue) {
  while(true) {
    if (queue.Size() > 0) {
      int data;
      queue.Pop(data);
      std::cout << data << "," << std::endl;
    }
  }
}

int main()
{
  ThreadSafeQueue<int> queue;
  std::thread t1(AddData, std::ref(queue));
  std::thread t2(ReadData, std::ref(queue));
  t1.join();
  t2.join();
}