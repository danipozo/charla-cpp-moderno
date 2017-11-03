#include <iostream>
#include <algorithm>
#include <vector>

auto map = [](auto c, auto f) {
  decltype(c) ret;
  std::transform(std::begin(c), std::end(c),
		 std::back_inserter(ret), f);

  return ret;
};

int main()
{
  std::vector<int> v = {1,2,3,4};

  auto v2 = map(v, [](int a){ return a*a; });

  for(auto i : v2)
    std::cout << i << std::endl;
  
  return 0;
}
