#include <map>
#include <string>
#include <iostream>
#include <type_traits>

class Env {
public:
  template<typename T>
  void getValue(const char* key, T& value, const T defualtValue);

  Env();
private:
  std::map<std::string , const char*> data;
};

template<typename T>
void Env::getValue(const char* key, T& value, const T defualtValue)
{
  f()
  a
  a
  if (std::is_same<T, int>::value) {
    value = atoi(data[key]);
  } else if (std::is_same<T, bool>::value) {
    value = true;
  } 
}