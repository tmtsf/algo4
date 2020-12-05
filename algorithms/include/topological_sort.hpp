#pragma once

#include "graph.hpp"
#include "stack.hpp"

namespace cheetah
{
  namespace
  {
    bool is_dag_helper(const std::vector<cheetah::bag<int>>& adj_list,
                       int v,
                       std::vector<bool>& visited)
    {
      if (!visited[v])
      {
        visited[v] = true;
        for (const auto& vertex : adj_list[v])
          return is_dag_helper(adj_list, vertex, visited);
      }
      else
      {
        return false;
      }

      return true;
    }
  }

  bool is_dag(const graph_ptr_t& g)
  {
    const auto& adj_list = g->adjacency_list();
    std::vector<bool> visited(adj_list.size(), false);
    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (visited[i])
        return false;
      else
        return is_dag_helper(adj_list, i, visited);
    }

    return true;
  }

  namespace
  {
    void reverse_post_order_helper(const std::vector<cheetah::bag<int>>& adj_list,
                                   int v,
                                   std::vector<bool>& visited,
                                   cheetah::stack<int>& s)
    {
      visited[v] = true;
      for (const auto& vertex : adj_list[v])
      {
        if (!visited[vertex])
          reverse_post_order_helper(adj_list, vertex, visited, s);
      }

      s.push(v);
    }

    void reverse_post_order(const graph_ptr_t& g,
                            cheetah::stack<int>& s)
    {
      const auto& adj_list = g->adjacency_list();
      std::vector<bool> visited(adj_list.size(),  false);
      for (std::size_t i=0; i<adj_list.size(); ++i)
      {
        if (!visited[i])
        {
          reverse_post_order_helper(adj_list, i, visited, s);
        }
      }
    }
  }

  std::vector<std::string> topological_sort(const graph_ptr_t& g)
  {
    if (!is_dag(g))
    {
      std::cout << "Cannot perform topological sort on a directed graph with cycle!\n";
      exit(1);
    }

    cheetah::stack<int> s;
    reverse_post_order(g, s);

    std::vector<std::string> result;
    const auto& symbols = g->symbol_table();
    while (!s.empty())
    {
      result.push_back(symbols[s.top()]);
      s.pop();
    }

    return result;
  }
}