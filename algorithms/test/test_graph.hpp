#include <iostream>
#include "graph.hpp"

namespace cheetah
{
  void test_make_graph(const char* filename)
  {
    graph<int> g1 = cheetah::make_undirected_graph<int>(filename);
    graph<int> g2 = cheetah::make_directed_graph<int>(filename);
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

  void test_graph_dfs(const char* filename)
  {
    graph<int> g = cheetah::make_undirected_graph<int>(filename);

    std::unordered_map<int, bool> visited;
    std::string spaces;
    for (const auto& item : g)
    {
      if (!visited[item.first])
        graph_dfs_helper(g, item.first, visited, spaces);
    }
  }

  void test_graph_bfs(const char* filename)
  {
    graph<int> g = cheetah::make_undirected_graph<int>(filename);

    // for (const auto& item : g)
    // {
    //   std::cout << item.first << ": ";
    //   for (const auto& pair : item.second)
    //     std::cout << "[" << pair.first << ", " << pair.second << "] -> ";

    //   std::cout << "[]\n";
    // }

    std::unordered_map<int, bool> visited;
    std::queue<int> q;
    for (const auto& item : g)
    {
      if (!visited[item.first])
      {
        q.push(item.first);
        while (!q.empty())
        {
          std::size_t sz = q.size();
          for (std::size_t i=0; i<sz; ++i)
          {
            int top = q.front();
            q.pop();
            visited[top] = true;
            std::cout << top << "\t";

            auto edges = g.at(top);
            for (const auto& pair : edges)
            {
              if (!visited[pair.first])
              {
                visited[pair.first] = true;
                q.push(pair.first);
              }
            }
          }

          std::cout << "\n";
        }
      }
    }
  }

  namespace
  {
    template<typename T>
    void connected_component_helper(const graph<T>& g,
                                    const T& v,
                                    std::unordered_map<int, bool>& visited)
    {
      visited[v] = true;
      const auto& edges = g.at(v);
      for (const auto& pair : edges)
      {
        if (!visited[pair.first])
          connected_component_helper(g, pair.first, visited);
      }
    }
  }

  void test_graph_connected_components(const char* filename)
  {
    graph<int> g = cheetah::make_undirected_graph<int>(filename);

    std::unordered_map<int, bool> visited;
    int count = 0;
    for (const auto& item : g)
    {
      if (!visited[item.first])
      {
        ++count;
        connected_component_helper(g, item.first, visited);
      }
    }

    std::cout << count << "\n";
    assert(count == 3);
  }
}