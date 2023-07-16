#include <thread>
#include <iostream>

void some_func() {
  std::cout << "do some func" << std::endl;
}

int main() {
  std::thread t1;
  std::cout << ( t1.get_id() == std::thread::id() );
}