#include <iostream>
#include <future>
#include <thread>

// 负责完成承诺的线程
void SetPromise(std::promise<int>& p) {
  p.set_value(10);
}

int main() {
  std::promise<int> p; // 需要一个线程来完成这个承诺
  std::future<int> res = p.get_future();

  std::thread t(SetPromise, std::ref(p));
  t.detach();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << res.get();
  
}