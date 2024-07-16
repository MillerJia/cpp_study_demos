#include "templateClass.h"

int main() {
  Env env;
  int value1;
  bool value2;
   env.getValue("12", value1, 3);
   std::cout << value1 << std::endl;
   env.getValue("12",value2, true);
   std::cout << value2 << std::endl;
  //std::cout << atoi("12");
}