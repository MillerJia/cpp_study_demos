#include <iostream>

class X {
public:
  X(int pMoney):money(pMoney) {
  }
  friend void ShowMoney(X& x);
  friend std::ostream& operator<<(std::ostream& os, X x);
private:
  int money;
};

void ShowMoney(X& x) {
  std::cout << x.money;
}

std::ostream& operator<<(std::ostream& os, X x) {
  os << x.money << ", xx" << std::endl;
  return os;
}

int main() {
  X x(4);
  std::cout << x;
}
