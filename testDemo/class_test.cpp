// class测试
#include <iostream>
#include <memory>

class B {

};

class A {
public:
  A() {
    std::cout << "default constructor" << std::endl;
    resoure_ = std::make_unique<int>(-1);
  }
  A(const A&) = delete;
  A(A&& otherA) {
    std::cout << "move consturctor" << std::endl;
    resoure_ = std::move(otherA.resoure_);
  }
  A& operator=(const A& otherA) {
    std::cout << "operator = " << std::endl;
    return *this;
  }
  std::unique_ptr<int> resoure_;
};

int main()
{
  A a;
  std::cout<< "-" << *(a.resoure_) << std::endl;
  A b(std::move(a));
  b = a;

  std::cout<< "-" << *(b.resoure_) << std::endl;
}