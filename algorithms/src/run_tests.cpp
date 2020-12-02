#include "test_binary_search.hpp"
#include "test_heap_sort.hpp"
#include "test_merge_sort.hpp"
#include "test_quick_sort.hpp"
#include "test_graph.hpp"

const char* TINY_GRAPH = "/home/si/Documents/Program/random_cpp/algorithms/src/tiny_graph.txt";
const char* MEDIUM_GRAPH = "/home/si/Documents/Program/random_cpp/algorithms/src/medium_graph.txt";

int main()
{
  cheetah::test_binary_search();
  cheetah::test_heap_sort();
  cheetah::test_merge_sort();
  cheetah::test_quick_sort();
  // cheetah::test_graph_dfs(TINY_GRAPH);
  // cheetah::test_graph_bfs(MEDIUM_GRAPH);

  cheetah::graph<int> g = cheetah::make_undirected_graph<int>(TINY_GRAPH);

  std::cout << "**********************************************\n";
  cheetah::test_graph_connected_components(g);
  std::cout << "**********************************************\n\n";

  std::cout << "**********************************************\n";
  cheetah::test_graph_dfs_path(g, 3);
  std::cout << "**********************************************\n\n";

  std::cout << "**********************************************\n";
  cheetah::test_graph_bfs_path(g, 3);
  std::cout << "**********************************************\n\n";
}