#include "thread_pool_use_wrapper.h"
#include <iostream>

// ThreadPool::ThreadPool(int threadNum) :thread_pool_done_(false) {
//   try {
//     for (int i=0; i < threadNum; i++) {
//     threads_.push_back(std::thread(&ThreadPool::Worker, this));
//     }
//   } catch(const std::exception& e) {
//     thread_pool_done_.store(true);;
//     printf("exception happened, msg:%s\n", e.what());
//   }
// }

// void ThreadPool::Submit(Task&& task) {
//   task_queue_.Push(task);
// }

// void ThreadPool::EndWork() {
//   thread_pool_done_.store(true);
//   for (int i=0; i < threads_.size();i++) {
//     if (threads_[i].joinable()) {
//       threads_[i].join();
//     }
//   }
// }

// ThreadPool::~ThreadPool() {
//   if (!thread_pool_done_) {
//     EndWork();
//   }
// }

// void ThreadPool::Worker() {
//   while(!thread_pool_done_) {
//     Task task;
//     if (task_queue_.Pop(task)) {
//       task();
//     } else {
//       std::this_thread::yield();
//     }
//   }
//   printf("thread id:%d, end work\n", std::this_thread::get_id());
// }

void test() {
  std::cout << "test" << std::endl;
}
int main()
{
  FunctionWrapper wrapeer = test; 
  FunctionWrapper wrapper2;
  wrapper2 = test;
  wrapeer();
  wrapper2();
}