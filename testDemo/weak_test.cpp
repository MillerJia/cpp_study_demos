#include <memory>
#include <iostream>

using namespace std;

class A;

void func(std::weak_ptr<A> a);

class A : public enable_shared_from_this<A> {
  public:
  void show() {
    func(shared_from_this());
  }
};

void func(std::weak_ptr<A> a) {
  std::cout << a.use_count() << std::endl;  
}

int main()
{
  std::shared_ptr<A> a = std::make_shared<A>();
  a->show();
}