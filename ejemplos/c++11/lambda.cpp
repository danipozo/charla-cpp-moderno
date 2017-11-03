#include <iostream>

int main()
{
  // Las variables globales pueden usarse sin ser capturadas
  auto f = [](){ std::cout << "foobar" << std::endl; };
  auto curried_sum = [](int x){
  return [=](int y) { return x+y; };
  };

  f();

  auto sum_3 = curried_sum(3);
  std::cout << sum_3(4) << std::endl;
  
  return 0;
}
