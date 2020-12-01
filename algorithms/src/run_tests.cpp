#include "test_binary_search.hpp"
#include "test_heap_sort.hpp"
#include "test_merge_sort.hpp"
#include "test_quick_sort.hpp"

int main()
{
  cheetah::test_binary_search();
  cheetah::test_heap_sort();
  cheetah::test_merge_sort();
  cheetah::test_quick_sort();
}