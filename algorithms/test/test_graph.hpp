#include <iostream>
#include <unordered_set>

#include "graph.hpp"
#include "graph_traversal.hpp"
#include "directed_graph.hpp"
#include "undirected_graph.hpp"
#include "connected_components.hpp"
#include "graph_path.hpp"
#include "topological_sort.hpp"

namespace cheetah
{
  void test_make_graph(const char* filename,
                       const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);

    const auto& adj_list1 = g1->adjacency_list();
    const auto& symbols1 = g1->symbol_table();
    for (std::size_t i=0; i<adj_list1.size(); ++i)
    {
      std::cout << symbols1[i] << ": ";
      for (const auto& vertex : adj_list1[i])
        std::cout << "[" << symbols1[vertex] << "] -> ";

      std::cout << "[]\n";
    }
    std::cout << "**********************************************\n\n";

    std::cout << "**********************************************\n";
    graph_ptr_t g2 = cheetah::make_directed_graph(filename, separator);

    const auto& adj_list2 = g2->adjacency_list();
    const auto& symbols2 = g2->symbol_table();
    for (std::size_t i=0; i<adj_list2.size(); ++i)
    {
      std::cout << symbols2[i] << ": ";
      for (const auto& vertex : adj_list2[i])
        std::cout << "[" << symbols2[vertex] << "] -> ";

      std::cout << "[]\n";
    }
    std::cout << "**********************************************\n\n";
  }

  void test_graph_dfs(const char* filename,
                      const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);
    cheetah::dfs(g1);
    std::cout << "**********************************************\n\n";
  }

  void test_graph_bfs(const char* filename,
                      const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);
    cheetah::bfs(g1);
    std::cout << "**********************************************\n\n";
  }

  void test_undirected_graph_connected_components(const char* filename,
                                                  const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);
    cheetah::undirected_graph_connected_components(g1);
    std::cout << "**********************************************\n\n";
  }

  void test_graph_dfs_path(const char* filename,
                           const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);
    cheetah::graph_dfs_path(g1, std::string("0"));
    std::cout << "**********************************************\n\n";
  }

  void test_graph_bfs_path(const char* filename,
                           const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g1 = cheetah::make_undirected_graph(filename, separator);
    cheetah::graph_bfs_path(g1, std::string("0"));
    std::cout << "**********************************************\n\n";
  }

  void test_topologial_sort(const char* filename,
                            const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g = cheetah::make_directed_graph(filename, separator);
    std::vector<std::string> result = cheetah::topological_sort(g);
    for (const auto& item : result)
      std::cout << item << "\n";
    std::cout << "**********************************************\n\n";
  }

  void test_strong_components(const char* filename,
                              const std::string& separator = " ")
  {
    std::cout << "**********************************************\n";
    graph_ptr_t g = cheetah::make_directed_graph(filename, separator);
    std::vector<std::vector<std::string>> result = cheetah::digraph_strong_components(g);
    for (std::size_t i=0; i<result.size(); ++i)
    {
      std::cout << i << ": ";
      for (const auto& vertex : result[i])
        std::cout << vertex << " ";
      std::cout << "\n";
    }
    std::cout << "**********************************************\n\n";
  }
}