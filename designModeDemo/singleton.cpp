#include <iostream>

template<typename T>
class Singleton{
  public:
  static T& getInstance() {
    static T instance_;
    return instance_;
  }
  Singleton(const Singleton&) = delete;
  Singleton& operator= (const Singleton &) = delete;
  Singleton(Singleton&&) = delete;
  ~Singleton() {
    std::cout << "destruct" << std::endl;
  }
  protected:
    Singleton(){
      std::cout << "construct";
    }
};

class A : public Singleton<A>{
public:
void show() {
  std::cout << "show" << std::endl;
}
friend class Singleton<A>;
private:
 A() = default;

};

int main()
{
 Singleton<A>::getInstance().show();
}