#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Foo {
  int bar = 42;
  std::string s;

public:
  Foo(std::string s) : s(s)
  {
    std::cout << s << std::endl;
  }
};

Foo operator""_foo(const char* literal, size_t l)
{
  std::string s;
  for(int i=0; i<l; i++)
    s.push_back(literal[i]);

  return Foo(s);
}

int main()
{
  Foo f = "1234"_foo;

  return 0; 
}
