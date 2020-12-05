#include <iostream>

#include "union_find.hpp"

namespace cheetah
{
  void test_quick_find_union_find(const char* filename,
                                  const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    cheetah::quick_find_union_find(filename, separator);
    std::cout << "**********************************************\n\n";
  }

  void test_quick_union_union_find(const char* filename,
                                  const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    cheetah::quick_union_union_find(filename, separator);
    std::cout << "**********************************************\n\n";
  }

  void test_weighted_quick_union_union_find(const char* filename,
                                  const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    cheetah::weighted_quick_union_union_find(filename, separator);
    std::cout << "**********************************************\n\n";
  }
}