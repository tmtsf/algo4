#pragma once

#include "graph.hpp"
#include "queue.hpp"
#include "stack.hpp"

namespace cheetah
{
  namespace
  {
    void graph_dfs_path_helper(const std::vector<cheetah::bag<int>>& adj_list,
                               int i,
                               std::vector<bool>& visited,
                               std::vector<int>& path)
    {
      for (const auto& vertex : adj_list[i])
      {
        if (!visited[vertex])
        {
          visited[vertex] = true;
          path[vertex] = i;
          graph_dfs_path_helper(adj_list, vertex, visited, path);
        }
      }
    }
  }

  void graph_dfs_path(const graph_ptr_t& g,
                      const std::string& source)
  {
    const auto& adj_list = g->adjacency_list();
    const auto& lookup = g->lookup_table();
    const auto& symbols = g->symbol_table();

    // for (std::size_t i=0; i<adj_list.size(); ++i)
    // {
    //   std::cout << i << ": ";
    //   for (const auto& vertex : adj_list[i])
    //     std::cout << "[" << vertex << "] -> ";

    //   std::cout << "[]\n";
    // }

    std::vector<bool> visited(adj_list.size(), false);
    std::vector<int> path(adj_list.size());
    int start = lookup.at(source);
    visited[start] = true;
    graph_dfs_path_helper(adj_list, start, visited, path);

    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (!visited[i])
        std::cout << symbols[i] << ": Not accessible from " << source << "!\n";
      else if (i == start)
        std::cout << source << ": Start of the path!\n";
      else
      {
        auto j = i;
        cheetah::stack<std::string> s;
        while (symbols[j] != source)
        {
          s.push(symbols[j]);
          j = path[j];
        }

        std::cout << symbols[i] << ": " << source;
        while (!s.empty())
        {
          std::string temp = s.top();
          s.pop();
          std::cout << "->" << temp;
        }

        std::cout << "\n";
      }
    }
  }

  void graph_bfs_path(const graph_ptr_t& g,
                      const std::string& source)
  {
    const auto& adj_list = g->adjacency_list();
    const auto& lookup = g->lookup_table();
    const auto& symbols = g->symbol_table();

    // for (std::size_t i=0; i<adj_list.size(); ++i)
    // {
    //   std::cout << i << ": ";
    //   for (const auto& vertex : adj_list[i])
    //     std::cout << "[" << vertex << "] -> ";

    //   std::cout << "[]\n";
    // }

    std::vector<bool> visited(adj_list.size(), false);
    std::vector<int> path(adj_list.size());
    int start = lookup.at(source);

    cheetah::queue<int> q;
    q.push(start);
    while (!q.empty())
    {
      int top = q.front();
      visited[top] = true;
      q.pop();

      for (const auto& vertex : adj_list[top])
      {
        if (!visited[vertex])
        {
          visited[vertex] = true;
          q.push(vertex);
          path[vertex] = top;
        }
      }
    }

    for (std::size_t i=0; i<adj_list.size(); ++i)
    {
      if (!visited[i])
        std::cout << symbols[i] << ": Not accessible from " << source << "!\n";
      else if (i == start)
        std::cout << source << ": Start of the path!\n";
      else
      {
        auto j = i;
        cheetah::stack<std::string> s;
        while (symbols[j] != source)
        {
          s.push(symbols[j]);
          j = path[j];
        }

        std::cout << symbols[i] << ": " << source;
        while (!s.empty())
        {
          std::string temp = s.top();
          s.pop();
          std::cout << "->" << temp;
        }

        std::cout << "\n";
      }
    }
  }
}