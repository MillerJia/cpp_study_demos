#include <iostream>
#include <functional>

// 假定有个需求，老函数传入两个参数，t1,t2，按照顺序处理，但是现在我希望传入参数保持不变，但是处理顺序改变
// 这里可以利用 std::bind的性质，改造函数 
void func(int a, int b) {
  std::cout << "Step1: " << a << std::endl;
  std::cout << "Step2: " << b << std::endl;
}

int main()
{
  auto func2 = std::bind(func,std::placeholders::_2, std::placeholders::_1);
  func(1,2);
  func2(1, 2);
}

