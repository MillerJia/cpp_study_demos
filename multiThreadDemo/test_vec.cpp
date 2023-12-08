#include <vector>

#include <iostream>

int main()
{
  std::vector<std::vector<int>> v;
  v.push_back({1,2,3});
  v.push_back({4});
  std::cout << v.size();
}