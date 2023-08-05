// 当一个线程需要的数据来源于另一个线程，并且只有当数据刷新时才执行，此时可以考虑promise
// 数据传输甚至是可以传递函数

#include <thread>
#include <future>
#include <iostream>

using Func = std::function<void(int,int,int&)>;

void func(int a, int b, int& c) {
  c = a + b;
  std::cout << "c=" << a + b;
}

void thread_func_provider(std::promise<Func>&& p) {
  std::this_thread::sleep_for(std::chrono::seconds(2));
  p.set_value(func);
}

// 执行者，它的输入是未来才知道的，在启动时并不知道，由provider提供
template<typename F, typename ...Args>
void thread_func_user(std::future<F>& future, Args&& ...args) {
  auto f = future.get();
  f(std::forward<Args>(args)...);
}

int main() {
  std::promise<Func> p;
  int c;
  std::future<Func> fu1 = p.get_future();
  std::thread t1(thread_func_provider, std::move(p));
  std::thread t2(thread_func_user<Func, int, int , int &>, std::ref(fu1), 2,3 ,std::ref(c));
  t1.join();
  t2.join();
}