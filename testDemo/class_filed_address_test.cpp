#include <memory>
#include <iostream>

class Human {
public:
  Human() = default;
  void ShowFiledAddress();

private:
  int head;
  double neck;
  int body;
  long leg;
};

void Human::ShowFiledAddress() {
  std::cout << "head: " << &head << std::endl;
  std::cout << "neck: " << &neck << std::endl;
  std::cout << "body: " << &body << std::endl;
  std::cout << "leg: " << &leg << std::endl;
}

int main() {
  Human human;
  std::cout << "sizeofhuman :" << sizeof(Human) << std::endl;
  human.ShowFiledAddress();

  int a =5;
  a==4 ? human.ShowFiledAddress() : (void());
}