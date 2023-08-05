#include <thread>
#include <atomic>
#include <iostream>

class SpinLock {
public:
  SpinLock(): flag_(ATOMIC_FLAG_INIT) {
  }
  void lock() {
   while (flag_.test_and_set(std::memory_order_acquire)); // 如果flag_被设置过，此值返回为true，阻塞执行，直到当前线程获取到，然后设值
  }
  void unlock() {
    flag_.clear(std::memory_order_release);
  }
  private:
  std::atomic_flag flag_;
};

int main() {
  SpinLock lock;
  std::thread t1([&lock](){
    std::cout << "t1 ask lock" << std::endl;
    lock.lock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "t1 end work" << std::endl;
    lock.unlock();
  });
  std::cout << "main ask lock" << std::endl;
  lock.lock();
  std::cout << "main get lock" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << " main end work" << std::endl;
  lock.unlock();
  t1.join();
}