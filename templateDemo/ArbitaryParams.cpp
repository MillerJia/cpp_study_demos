// 学习函数模板，其中参数类型为任意大小

#include <iostream>
#include <functional>

// 一个很有意思的作用，这个函数模板可以作为一个wrapper，例如执行函数之前打印一些信息
template<typename Func, typename ...Args>
void CallFunc(Func func, Args&& ...args) {
  std::cout << "call from wrapper" << std::endl;
  func(std::forward<Args>(args)...);
}

struct Adder {
  void operator() (int a, int b) {
    std::cout << a + b << std::endl;
  }
};

class AdderClass {
public:
  void operator() (int a, int b) {
    std::cout << a + b << std::endl;
  }
};

void AddFunc(int a, int b) {
  std::cout << a + b << std::endl;
}

int main()
{
  CallFunc(AddFunc,1,2);
  Adder adder;
  CallFunc(adder, 1 ,2);
  AdderClass adder_class;
  CallFunc(adder_class, 1, 2);
}