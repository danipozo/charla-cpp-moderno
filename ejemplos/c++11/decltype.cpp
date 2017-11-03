#include <iostream>

int main()
{
  int a = 42;
  decltype(a) b = a; // int
  decltype((a)) c = a; // int&

  c = 43;

  std::cout << a << std::endl;
  
  return 0;
}
