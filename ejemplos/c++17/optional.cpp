#include <iostream>
#include <optional>

auto map_opt = [](auto f, auto o)
{
  return o ? std::make_optional(f(o.value())) : std::nullopt;
};

auto curried_map_opt = [](auto f){
  return [=](auto o){
    return map_opt(f,o);
  };
};

auto flat_map_opt = [](auto f, auto o)
{
   return o ? f(o.value()) : std::nullopt;
};

auto curried_flat_map_opt = [](auto f){
  return [=](auto o){
    return flat_map_opt(f,o);
  };
};


auto f(int a)
{
  return a>=0 ? a-1 : 0;
}

auto f2(int a)
{
  return a>=0 ? std::make_optional(a-1) : std::nullopt;
}

auto compose_mon2 = [](auto f1, auto f2)
{
  return [=](auto a)
  {
    return flat_map_opt(f1, flat_map_opt(f2, std::make_optional(a)));
  };
};


template<class F1, class F2>
auto compose_mon(F1 f1, F2 f2)
{
  return compose_mon2(f1, f2);
}

template<class F1, class F2, typename... Args>
auto compose_mon(F1 f1, F2 f2, Args... args)
{
  return compose_mon(compose_mon2(f1, f2), args...);
}

int main()
{
  std::optional<int> a(38);
  
  for(int i=0; i<40; i++)
    a = flat_map_opt(f2, a);

  auto f3 = compose_mon(f2, f2, f2, f2, [](bool b){ return std::make_optional(42); });
  
  std::optional b(42);
  b = f3(true);
  // Use variadic template to compose

  std::cout << "b: " << b.value() << std::endl;

  if(a)
    std::cout << "Valor de a: " << a.value() << std::endl;
  else
    std::cout << "a no tiene valor" << std::endl;
  
  return 0;
}
