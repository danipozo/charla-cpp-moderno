#include <iostream>
#include <thread>

thread_local int tl;

void do_stuff(int i)
{
  tl = i;
  
  std::cout << tl << std::endl;
}

int main()
{
  int num_threads = 40;
  std::thread ts[num_threads];

  for(int i=0; i<num_threads; i++)
    ts[i] = std::thread(do_stuff, i);

  for(int i=0; i<num_threads; i++)
    ts[i].join();

  return 0;
}
