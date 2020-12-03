#include <iostream>
#include <vector>
#include <cassert>
#include "stack.hpp"

namespace cheetah
{
  void test_stack()
  {
    cheetah::stack<int> s;

    std::vector<int> v = {1,2,3,4,5};
    for (int num : v)
      s.push(num);

    for (int num : s)
      std::cout << num << "\n";
    std::cout << "\n";

    while (!s.empty())
    {
      std::cout << s.top() << "  " << s.size() << "\n";
      s.pop();
    }

    std::cout << "\n";

    assert(s.size() == 0);
    assert(s.empty());
  }
}