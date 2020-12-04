#include "test_binary_search.hpp"
#include "test_heap_sort.hpp"
#include "test_merge_sort.hpp"
#include "test_quick_sort.hpp"
#include "test_graph.hpp"
#include "test_stack.hpp"
#include "test_bag.hpp"
#include "test_queue.hpp"
#include "test_expression_evaluation.hpp"
#include "union_find.hpp"

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

  cheetah::graph<int> g1 = cheetah::make_undirected_graph<int>(MEDIUM_UF);

  std::cout << "**********************************************\n";
  cheetah::test_graph_connected_components(g1);
  std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_dfs_path(g1, 10);
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_bfs_path(g1, 10);
  // std::cout << "**********************************************\n\n";

  // cheetah::graph<int> g2 = cheetah::make_directed_graph<int>(TINY_DG);

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_dfs_path(g2, 2);
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_bfs_path(g2, 2);
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // std::cout << "The directed graph is "
  //           << (cheetah::is_dag(g2) ? "" : "not ")
  //           << "acyclic.\n";
  // std::cout << "**********************************************\n\n";

  // cheetah::graph<std::string> g3 = cheetah::make_directed_graph<std::string>(JOBS, "/");

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_dfs_path<std::string>(g3, "Algorithms");
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // cheetah::test_graph_bfs_path<std::string>(g3, "Algorithms");
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // std::cout << "The directed graph is "
  //           << (cheetah::is_dag(g3) ? "" : "not ")
  //           << "acyclic.\n";
  // std::cout << "**********************************************\n\n";

  // std::cout << "**********************************************\n";
  // std::vector<std::string> result = cheetah::topological_sort(g3);
  // for (const auto& course : result)
  //   std::cout << course << "\n";
  // std::cout << "**********************************************\n\n";

  // cheetah::graph<std::string> g4 = cheetah::make_directed_graph<std::string>(TINY_DG);

  // std::cout << "**********************************************\n";
  // std::vector<std::vector<std::string>> results = cheetah::digraph_strong_components(g4);
  // for (const auto& result : results)
  // {
  //   for (const auto& vertex : result)
  //     std::cout << vertex << "  ";
  //   std::cout << "\n";
  // }
  // std::cout << "**********************************************\n\n";

  std::cout << "**********************************************\n";
  cheetah::quick_find_union_find<int>(MEDIUM_UF, std::string(" "));
  std::cout << "**********************************************\n\n";
}