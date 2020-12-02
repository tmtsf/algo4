#include <iostream>
#include <stack>
#include <queue>

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

  template<typename T>
  void test_graph_dfs(const graph<T>& g)
  {
    std::unordered_map<T, bool> visited;
    std::string spaces;
    for (const auto& item : g)
    {
      if (!visited[item.first])
        graph_dfs_helper(g, item.first, visited, spaces);
    }
  }

  template<typename T>
  void test_graph_bfs(const graph<T>& g)
  {
    // for (const auto& item : g)
    // {
    //   std::cout << item.first << ": ";
    //   for (const auto& pair : item.second)
    //     std::cout << "[" << pair.first << ", " << pair.second << "] -> ";

    //   std::cout << "[]\n";
    // }

    std::unordered_map<T, bool> visited;
    std::queue<T> q;
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
            T top = q.front();
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

  template<typename T>
  void test_graph_connected_components(const graph<T>& g)
  {
    std::unordered_map<T, bool> visited;
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
    // assert(count == 3);
  }

  namespace
  {
    template<typename T>
    void graph_dfs_path_helper(const graph<T>& g,
                               const T& source,
                               std::unordered_map<T, bool>& visited,
                               std::unordered_map<T, T>& path)
    {
      visited[source] = true;
      for (const auto& edge : g.at(source))
      {
        if (!visited[edge.first])
        {
          visited[edge.first] = true;
          path[edge.first] = source;
          graph_dfs_path_helper(g, edge.first, visited, path);
        }
      }
    }
  }

  template<typename T>
  void test_graph_dfs_path(const graph<T>& g,
                           const T& source)
  {
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, T> path;
    graph_dfs_path_helper(g, source, visited, path);

    for (const auto& item : g)
    {
      if (!visited[item.first])
        std::cout << item.first << ": Not accessible from " << source << "!\n";
      else if (source == item.first)
        std::cout << item.first << ": Start of the path!\n";
      else
      {
        T temp = item.first;
        std::stack<T> s;
        while (temp != source)
        {
          s.push(temp);
          temp = path[temp];
        }

        std::cout << item.first << ": " << source;
        while (!s.empty())
        {
          temp = s.top();
          s.pop();
          std::cout << "->" << temp;
        }

        std::cout << "\n";
      }

    }
  }

  template<typename T>
  void test_graph_bfs_path(const graph<T>& g,
                           const T& source)
  {
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, T> path;

    std::queue<T> q;
    q.push(source);
    while (!q.empty())
    {
      T temp = q.front();
      visited[temp] = true;
      q.pop();

      for (const auto& edge : g.at(temp))
      {
        if (!visited[edge.first])
        {
          visited[edge.first] = true;
          q.push(edge.first);
          path[edge.first] = temp;
        }
      }
    }

    for (const auto& item : g)
    {
      if (!visited[item.first])
        std::cout << item.first << ": Not accessible from " << source << "!\n";
      else if (source == item.first)
        std::cout << item.first << ": Start of the path!\n";
      else
      {
        T temp = item.first;
        std::stack<T> s;
        while (temp != source)
        {
          s.push(temp);
          temp = path[temp];
        }

        std::cout << item.first << ": " << source;
        while (!s.empty())
        {
          temp = s.top();
          s.pop();
          std::cout << "->" << temp;
        }

        std::cout << "\n";
      }

    }
  }
}