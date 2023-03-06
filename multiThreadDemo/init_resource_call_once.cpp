#include <mutex>
#include <iostream>
#include <memory>

std::once_flag init_resource_flag;

struct Y {
  void operator() () {
    std::cout << "override y ()" << std::endl;
  }
};

class X {
public:
  void dealSomeData() {
    std::call_once(init_resource_flag, &X::initResource, this); // 用于确保处理资源之前，资源已经初始化，且只初始化一次（支持多线程）
    // std::call_once(init_resource_flag, y1);
    std::cout << "deal data" << *(resource_id_ptr_.get()) << std::endl;
  }
private:
  void initResource() {
    std::cout << "init" << std::endl;
    resource_id_ptr_ = std::make_shared<int>(1);
  }
private:
  std::shared_ptr<int> resource_id_ptr_ = nullptr;
};

int main() {
  X x;
  x.dealSomeData();
  x.dealSomeData();
}