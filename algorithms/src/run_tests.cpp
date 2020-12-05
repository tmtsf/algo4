#include "test_binary_search.hpp"
#include "test_heap_sort.hpp"
#include "test_merge_sort.hpp"
#include "test_quick_sort.hpp"
#include "test_graph.hpp"
#include "test_stack.hpp"
#include "test_bag.hpp"
#include "test_queue.hpp"
#include "test_expression_evaluation.hpp"
#include "test_union_find.hpp"

const char* TINY_GRAPH = "/home/si/Documents/Program/random_cpp/algorithms/src/tiny_graph.txt";
const char* MEDIUM_GRAPH = "/home/si/Documents/Program/random_cpp/algorithms/src/medium_graph.txt";
const char* TINY_DG = "/home/si/Documents/Program/random_cpp/algorithms/src/tiny_directed_graph.txt";
const char* ROUTES = "/home/si/Documents/Program/random_cpp/algorithms/src/routes.txt";
const char* MOVIES = "/home/si/Documents/Program/random_cpp/algorithms/src/movies.txt";
const char* JOBS = "/home/si/Documents/Program/random_cpp/algorithms/src/jobs.txt";
const char* TINY_UF = "/home/si/Documents/Program/random_cpp/algorithms/src/tiny_union_find.txt";
const char* MEDIUM_UF = "/home/si/Documents/Program/random_cpp/algorithms/src/medium_union_find.txt";
const char* LARGE_UF = "/home/si/Documents/Program/random_cpp/algorithms/src/large_union_find.txt";

int main()
{
  // cheetah::test_binary_search();
  // cheetah::test_heap_sort();
  // cheetah::test_merge_sort();
  // cheetah::test_quick_sort();

  // std::cout << "**********************************************\n";
  // cheetah::test_stack();
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_bag();
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_queue();
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_expression_evaluation();
  // std::cout << "**********************************************\n\n";

  // cheetah::test_make_graph(TINY_GRAPH);
  // cheetah::test_graph_dfs(TINY_GRAPH);
  // cheetah::test_graph_bfs(TINY_GRAPH);
  cheetah::test_undirected_graph_connected_components(MEDIUM_UF);
  // cheetah::test_graph_dfs_path(TINY_GRAPH);
  // cheetah::test_graph_bfs_path(TINY_GRAPH);
  // cheetah::test_topologial_sort(JOBS, "/");
  // cheetah::test_strong_components(TINY_DG);
  cheetah::test_quick_find_union_find(MEDIUM_UF);
  cheetah::test_quick_union_union_find(MEDIUM_UF);
  cheetah::test_weighted_quick_union_union_find(MEDIUM_UF);
  cheetah::test_weighted_quick_union_union_find(LARGE_UF);
}