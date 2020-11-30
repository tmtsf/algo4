#include <iostream>
#include <algorithm>
#include <cassert>
#include "merge_sort.hpp"

int main()
{
  std::vector<int> v = {3, 5, 1, -2, -7, 9, 4, 6, 1, -1};
  std::vector<int> c = v;

  cheetah::merge_sort(v);
  std::sort(c.begin(), c.end());

  for (int num : v)
    std::cout << num << "  ";
  std::cout << "\n";

  assert(std::equal(v.cbegin(), v.cend(), c.cbegin()));

  v = {3, 5, 1, -2, -7, 9, 4, 6, 1, -1};
  c = v;

  cheetah::merge_sort(v, std::greater<int>());
  std::sort(c.begin(), c.end(), std::greater<int>());

  for (int num : v)
    std::cout << num << "  ";
  std::cout << "\n";

  assert(std::equal(v.cbegin(), v.cend(), c.cbegin()));

  return 0;
}