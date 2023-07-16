#include <future>
#include <iostream>
#include <thread>

// 父线程向子线程传递数据的时候除了初始化的时候将参数就准备好，还有可能数据不是在创建的时候就准备好，需要在未来传递过来

// 子线程执行的函数，参数不是在一开始
int add_one_func(std::future<int>& f) {
  std::cout << "child add func" << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  int param = f.get();
  std::cout << "get param" << param << std::endl;
  return param + 1;
}

int main() {
  std::promise<int> promise_param; //创建一个承诺，我会在未来兑现，将参数设置进去
  std::future<int> param = promise_param.get_future();
  
  std::future<int> res = std::async(std::launch::async, add_one_func, std::ref(param));

  // std::this_thread::sleep_for(std::chrono::seconds(3));
 // promise_param.set_value(2); // 兑现承诺
  // std::cout << res.get() << " main res" << std::endl; // 获取结果
}

