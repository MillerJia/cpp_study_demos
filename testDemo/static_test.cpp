#include <iostream>

class A {
public:
  A() {
    if (s_data == nullptr) {
      s_data = new int (5);
      std::cout << "sdata:" << *s_data;
    }
  }
  static int* s_data;
};

int* A::s_data = nullptr;

int main()
{
  A a1;
  A a2;
}