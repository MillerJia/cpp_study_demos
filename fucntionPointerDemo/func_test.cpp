#include <iostream>

typedef int (*func)(int ,int);

int add(int a,int b) {
  return a+b;
}

int sub(int a,int b) {
  return a - b;
}

int main()
{
  func myfun;
  myfun = add;
  std::cout << myfun(1, 2);
  myfun = sub;
  std::cout << myfun(1, 2);
}