#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>

namespace cheetah
{
  // Cannot stor edges as unordered set of pairs
  // Pairs as key to unordered map or entry to unordered set require hashing
  template<typename T>
  using graph = std::unordered_map<T, std::vector<std::pair<T, double>>>;

  template<typename T>
  graph<T> make_undirected_graph(const char* filename)
  {
    std::ifstream in(filename);
    if (!in.is_open())
    {
      std::cout << "File failed to open.\n";
      exit(1);
    }

    graph<T> graph;
    std::string line;
    while (std::getline(in, line))
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
  graph<T> make_directed_graph(const char* filename)
  {
    std::ifstream in(filename);
    if (!in.is_open())
    {
      std::cout << "File failed to open.\n";
      exit(1);
    }

    graph<T> graph;
    std::string line;
    while (std::getline(in, line))
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
}