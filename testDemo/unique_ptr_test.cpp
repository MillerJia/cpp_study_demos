#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  A() {
    m_data = new int(10);
  }
  void print() {
    std::cout << "address:" << m_data << " data:" << *m_data << std::endl;
  }

private:
  int* m_data;
};

int main() {
  std::unique_ptr<A> PA1 = std::unique_ptr<A>(new A());
  PA1->print();
  std::vector<std::unique_ptr<A> > PA2;
  PA2.emplace_back(std::move(PA1));
  if (PA1 == nullptr) {
    std::cout << "empty" << std::endl;
  }
  PA2[0]->print();
  PA1 = std::move(PA2[0]);
  PA1->print();
}
