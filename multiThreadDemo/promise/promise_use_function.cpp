#include <iostream>
#include <thread>
#include <functional>
#include <future>

// 运行时决定执行什么函数，函数通过promise由另一个线程传递
using Func = std::function<void(int, int, int&)>;

void func1(int a, int b, int& c) {
  c = a + b + 1;
}

void func2(int a, int b, int& c) {
  c = a +b + 2;
}

void Decider_Thread(std::promise<Func> &p) {
  p.set_value(func1);
}

int main() {
  std::promise<Func> func;
  auto resFunc = func.get_future();
  int result = 0;
  std::thread t1(Decider_Thread, std::ref(func));
  t1.detach();
  resFunc.get()(1, 2, result);
  std::cout << result;
}