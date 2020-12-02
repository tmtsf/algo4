#include <iostream>
#include "graph.hpp"

namespace cheetah
{
  void test_make_graph()
  {
    graph<int> g1 = cheetah::make_undirected_graph<int>();
    graph<int> g2 = cheetah::make_directed_graph<int>();
  }

  void test_graph_dfs()
  {
    graph<int> g = cheetah::make_undirected_graph<int>();
    cheetah::graph_dfs(g);
  }
}