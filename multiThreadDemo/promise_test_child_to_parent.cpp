#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include <condition_variable>

// 父线程从子线程拿数据的方式

// 优雅的方式一
// int add(int a, int b) {
//   std::this_thread::sleep_for(std::chrono::seconds(2));
//   return a + b;
// }

// int main() {
//   std::future<int> res = std::async(std::launch::async, add, 1, 2);
//   std::cout << "get result:" << res.get(); 
// }

/// 方式二

std::condition_variable res_is_ok;
std::mutex mu;
bool work_done = false;

void add(int a, int b, int& res) {
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::lock_guard<std::mutex> lg(mu);
  res = a + b;
  work_done = true;
  res_is_ok.notify_one();
}

int main() {
  int res;
  std::thread t1(add, 1, 2, std::ref(res));
  std::unique_lock<std::mutex> res_lock(mu);
  res_is_ok.wait(res_lock, [](){
    return work_done;
  });
  t1.join();
  std::cout << "main get res:" << res;
}