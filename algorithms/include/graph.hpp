#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

namespace cheetah
{
  // Cannot stor edges as unordered set of pairs
  // Pairs as key to unordered map or entry to unordered set require hashing
  template<typename T>
  using graph = std::unordered_map<T, std::vector<std::pair<T, double>>>;

  template<typename T>
  graph<T> make_undirected_graph()
  {
    graph<T> graph;
    std::string line;
    while (std::getline(std::cin, line))
    {
      std::istringstream iss(line);
      T from;
      T to;
      iss >> from >> to;

      double weight = 1.0;
      if (iss >> weight)
        ;

      graph[from].push_back({to, weight});
      graph[to].push_back({from, weight});
    }

    return graph;
  }

  template<typename T>
  graph<T> make_directed_graph()
  {
    graph<T> graph;
    std::string line;
    while (std::getline(std::cin, line))
    {
      std::istringstream iss(line);
      T from;
      T to;
      iss >> from >> to;

      double weight = 1.0;
      if (iss >> weight)
        ;

      graph[from].push_back({to, weight});
    }

    return graph;
  }

  namespace
  {
    template<typename T>
    void graph_dfs_helper(const graph<T>& g,
                          const T& start,
                          std::unordered_map<T, bool>& visited,
                          const std::string& spaces)
    {
      std::cout << spaces << start << "\n";
      visited[start] = true;
      auto edges = g.at(start);
      for (const auto& pair : edges)
      {
        if (!visited[pair.first])
        {
          graph_dfs_helper(g, pair.first, visited, spaces + "  ");
        }
      }
    }
  }

  template<typename T>
  void graph_dfs(const graph<T>& g)
  {
    // for (const auto& item : g)
    // {
    //   std::cout << item.first << ": ";
    //   for (const auto& pair : item.second)
    //     std::cout << "[" << pair.first << ", " << pair.second << "] -> ";

    //   std::cout << "[]\n";
    // }

    std::unordered_map<T, bool> visited;
    std::string spaces;
    for (const auto& item : g)
    {
      if (!visited[item.first])
        graph_dfs_helper(g, item.first, visited, spaces);
    }
  }
}