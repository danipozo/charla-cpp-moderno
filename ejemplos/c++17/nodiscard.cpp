#include <iostream>
#include <memory>
#include <thread>
#include <chrono>


void f(int ms)
{
  std::cout << "Empieza f" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  std::cout << "Termina f" << std::endl;
}

[[nodiscard]]
auto foo()
{
  return std::make_unique<std::thread>(f, 200);
}

int main()
{
  std::unique_ptr<std::thread> f[5];
  for(int i=0; i<5; i++)
  {
    /*
     * La línea comentada y la no comentada resultan en
     * ejecuciones muy distintas del programa.
     */
    // foo();
    f[i] = foo(); 
  }

  for(auto& i : f)
    i->join();
  
  std::cout << "Termina main" << std::endl;
  
  return 0;
}
