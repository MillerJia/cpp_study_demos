#include <iostream>
#include <memory>

class X : public std::enable_shared_from_this<X> 
{
public:
  void ShowX();
  std::shared_ptr<X> getPtr() {return shared_from_this();}
private:
  int data_;
};

void X::ShowX() {
}

int main()
{
  std::shared_ptr<X> b0 = std::make_shared<X>();
  std::shared_ptr<X> b1 = b0->getPtr();
  std::cout << b1.use_count();
}