// 学习函数模板，其中参数类型为任意大小

#include <iostream>
#include <functional>

template<typename Func, typename ...Args>
void CallFunc(Func func, Args&& ...args) {
  std::cout << "call from wrapper" << std::endl;
 // std::invoke(func, std::forward<Args>(args)...); // std 17，支持传入成员函数
  std::bind(func, std::forward<Args>(args)...)(); // 方法2 使用std::bind
}

class AdderClass {
public:
  void Sub(int a, int b) {
    std::cout << a - b << std::endl;
  }  
};

int main()
{
  AdderClass adder_class;
  CallFunc(&AdderClass::Sub, &adder_class, 1, 2);
}