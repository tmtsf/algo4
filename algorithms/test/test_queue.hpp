#include <iostream>
#include <vector>
#include <cassert>
#include "queue.hpp"

namespace cheetah
{
  void test_queue()
  {
    cheetah::queue<int> s;

    std::vector<int> v = {1,2,3,4,5};
    for (int num : v)
      s.push(num);

    for (int num : s)
      std::cout << num << "\n";
    std::cout << "\n";

    while (!s.empty())
    {
      std::cout << s.front() << "  " << s.size() << "\n";
      s.pop();
    }

    std::cout << "\n";

    assert(s.size() == 0);
    assert(s.empty());
  }
}