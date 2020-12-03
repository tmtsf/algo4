#include <iostream>
#include <vector>
#include <cassert>
#include "bag.hpp"

namespace cheetah
{
  void test_bag()
  {
    cheetah::bag<int> s;

    std::vector<int> v = {1,2,3,4,5};
    for (int num : v)
      s.push(num);

    for (int num : s)
      std::cout << num << "\n";
    std::cout << "\n";

    assert(s.size() == v.size());
    assert(!s.empty());
  }
}