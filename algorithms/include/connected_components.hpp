#pragma once

#include "graph.hpp"
#include "topological_sort.hpp"

namespace cheetah
{
  namespace
  {
    void connected_components_helper(const std::vector<cheetah::bag<int>>& adj_list,
                                     std::size_t i,
                                     std::vector<bool>& visited,
                                     std::vector<int>& component,
                                     int count)
    {
      visited[i] = true;
      component[i] = count;
      const auto& vertices = adj_list[i];
      for (const auto& vertex : vertices)
      {
        if (!visited[vertex])
          connected_components_helper(adj_list, vertex, visited, component, count);
      }
    }
  }

  void undirected_graph_connected_components(const graph_ptr_t& g)
  {
    int count = 0;
    const auto& adj_list = g->adjacency_list();
    std::vector<bool> visited(adj_list.size());
    std::vector<int> component(adj_list.size());

    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (!visited[i])
      {
        connected_components_helper(adj_list, i, visited, component, count);
        ++count;
      }
    }

    std::cout << "There are " << count << " connected components.\n";

    // const auto& symbol = g->symbol_table();
    // for (std::size_t i=0; i<component.size(); ++i)
    //   std::cout << symbol[i] << "  " << component[i] << "\n";
  }

  namespace
  {
    void digraph_strong_components_helper(const std::vector<cheetah::bag<int>>& adj_list,
                                          int t,
                                          std::vector<bool>& visited,
                                          std::vector<int>& components,
                                          int count)
    {
      visited[t] = true;
      components[t] = count;
      for (const auto& vertex : adj_list[t])
      {
        if (!visited[vertex])
          digraph_strong_components_helper(adj_list, vertex, visited, components, count);
      }
    }
  }

  std::vector<std::vector<std::string>> digraph_strong_components(const graph_ptr_t& g)
  {
    auto pd = dynamic_cast<cheetah::mixins::directed*>(g.get());
    graph_ptr_t rev_graph = pd->reverse();
    cheetah::stack<int> s;
    reverse_post_order(rev_graph, s);

    const auto& adj_list = g->adjacency_list();
    const auto& symbols = g->symbol_table();
    std::vector<bool> visited(adj_list.size(), false);
    std::vector<int> components(adj_list.size());
    int count = 0;
    while (!s.empty())
    {
      int t = s.top();
      s.pop();
      if (!visited[t])
      {
        digraph_strong_components_helper(adj_list, t, visited, components, count);
        ++count;
      }
    }

    std::vector<std::vector<std::string>> results(count, std::vector<std::string>());
    for (std::size_t i=0; i<components.size(); ++i)
    {
      results[components[i]].push_back(symbols[i]);
    }

    return results;
  }
}