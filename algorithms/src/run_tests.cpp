#include "test_binary_search.hpp"
#include "test_heap_sort.hpp"
#include "test_merge_sort.hpp"
#include "test_quick_sort.hpp"
#include "test_graph.hpp"

int main()
{
  cheetah::test_binary_search();
  cheetah::test_heap_sort();
  cheetah::test_merge_sort();
  cheetah::test_quick_sort();
  cheetah::test_graph_dfs("/home/si/Documents/Program/random_cpp/algorithms/src/tiny_graph.txt");
  cheetah::test_graph_bfs("/home/si/Documents/Program/random_cpp/algorithms/src/medium_graph.txt");
  cheetah::test_graph_connected_components("/home/si/Documents/Program/random_cpp/algorithms/src/tiny_graph.txt");
}