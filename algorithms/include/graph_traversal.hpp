#pragma once

#include "graph.hpp"
#include "queue.hpp"

namespace cheetah
{
  namespace
  {
    void dfs_helper(const std::vector<cheetah::bag<int>>& adj_list,
                    const std::vector<std::string>& symbols,
                    int i,
                    std::vector<bool>& visited,
                    const std::string& spaces)
    {
      std::cout << spaces << symbols[i] << "\n";
      visited[i] = true;
      const auto& vertices = adj_list[i];
      for (const auto& vertex : vertices)
      {
        if (!visited[vertex])
        {
          dfs_helper(adj_list, symbols, vertex, visited, spaces + "  ");
        }
      }
    }
  }

  void dfs(const graph_ptr_t& g)
  {
    const std::vector<cheetah::bag<int>>& adj_list = g->adjacency_list();
    const std::vector<std::string>& symbols = g->symbol_table();
    std::vector<bool> visited(adj_list.size());
    std::string spaces;
    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (!visited[i])
        dfs_helper(adj_list, symbols, i, visited, spaces);
    }
  }

  void bfs(const graph_ptr_t& g)
  {
    const std::vector<cheetah::bag<int>>& adj_list = g->adjacency_list();
    const std::vector<std::string>& symbols = g->symbol_table();
    std::vector<bool> visited(adj_list.size());
    cheetah::queue<int> q;
    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (!visited[i])
      {
        q.push(i);
        while (!q.empty())
        {
          std::size_t sz = q.size();
          for (std::size_t i=0; i<sz; ++i)
          {
            int top = q.front();
            q.pop();
            visited[top] = true;
            std::cout << top << "\t";

            auto vertices = adj_list[top];
            for (const auto& vertex : vertices)
            {
              if (!visited[vertex])
              {
                visited[vertex] = true;
                q.push(vertex);
              }
            }
          }

          std::cout << "\n";
        }
      }
    }
  }
}