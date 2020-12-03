#include <iostream>
#include <stack>
#include <queue>
#include <unordered_set>

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
    std::unordered_set<T> vertices(const graph<T>& g)
    {
      std::unordered_set<T> s;
      for (const auto& item : g)
      {
        s.insert(item.first);
        for (const auto& edge : item.second)
        {
          s.insert(edge.vertex);
        }
      }

      return s;
    }

    template<typename T>
    void graph_dfs_helper(const graph<T>& g,
                          const T& start,
                          std::unordered_map<T, bool>& visited,
                          const std::string& spaces)
    {
      std::cout << spaces << start << "\n";
      visited[start] = true;
      auto edges = g.at(start);
      for (const auto& edge : edges)
      {
        if (!visited[edge.vertex])
        {
          graph_dfs_helper(g, edge.vertex, visited, spaces + "  ");
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
                                    std::unordered_map<int, bool>& visited,
                                    std::unordered_map<T, int>& m,
                                    int count)
    {
      visited[v] = true;
      m[v] = count;
      const auto& edges = g.at(v);
      for (const auto& edge : edges)
      {
        if (!visited[edge.vertex])
          connected_component_helper(g, edge.vertex, visited, m, count);
      }
    }
  }

  template<typename T>
  void test_graph_connected_components(const graph<T>& g)
  {
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, int> m;
    int count = 0;
    for (const auto& item : g)
    {
      if (!visited[item.first])
      {
        ++count;
        connected_component_helper(g, item.first, visited, m, count);
      }
    }

    std::cout << "There are " << count << " connected components in this graph.\n";
    std::vector<std::vector<T>> components(count, std::vector<T>());
    for (const auto& item : m)
    {
      components[item.second-1].push_back(item.first);
    }

    for (int i=0; i<count; ++i)
    {
      std::cout << i << ": ";
      for (const auto& e : components[i])
        std::cout << e << "  ";

      std::cout << "\n";
    }
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

      if (g.count(source))
      {
        for (const auto& edge : g.at(source))
        {
          if (!visited[edge.vertex])
          {
            visited[edge.vertex] = true;
            path[edge.vertex] = source;
            graph_dfs_path_helper(g, edge.vertex, visited, path);
          }
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
    std::unordered_set<T> s = vertices(g);

    for (const auto& item : s)
    {
      if (!visited[item])
        std::cout << item << ": Not accessible from " << source << "!\n";
      else if (source == item)
        std::cout << item << ": Start of the path!\n";
      else
      {
        T temp = item;
        std::stack<T> s;
        while (temp != source)
        {
          s.push(temp);
          temp = path[temp];
        }

        std::cout << item << ": " << source;
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

      if (g.count(temp))
      {
        for (const auto& edge : g.at(temp))
        {
          if (!visited[edge.vertex])
          {
            visited[edge.vertex] = true;
            q.push(edge.vertex);
            path[edge.vertex] = temp;
          }
        }
      }
    }

    std::unordered_set<T> s = vertices(g);
    for (const auto& item : s)
    {
      if (!visited[item])
        std::cout << item << ": Not accessible from " << source << "!\n";
      else if (source == item)
        std::cout << item << ": Start of the path!\n";
      else
      {
        T temp = item;
        std::stack<T> s;
        while (temp != source)
        {
          s.push(temp);
          temp = path[temp];
        }

        std::cout << item << ": " << source;
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

  namespace
  {
    template<typename T>
    bool is_dag_helper(const graph<T>& g,
                       const T& v,
                       std::unordered_map<T, bool>& visited)
    {
      if (!visited[v])
      {
        visited[v] = true;
        if (g.count(v))
        {
          const auto& edges = g.at(v);
          for (const auto& edge : edges)
            return is_dag_helper(g, edge.vertex, visited);
        }
      }
      else
      {
        return false;
      }

      return true;
    }
  }

  template<typename T>
  bool is_dag(const graph<T>& g)
  {
    std::unordered_map<T, bool> visited;
    for (const auto& item : g)
    {
      if (visited[item.first])
        return false;
      else
        return is_dag_helper(g, item.first, visited);
    }

    return true;
  }

  namespace
  {
    template<typename T>
    void topological_sort_helper(const graph<T>& g,
                                 const T& v,
                                 std::unordered_map<T, bool>& visited,
                                 std::stack<T>& s)
    {
      visited[v] = true;
      if (g.count(v))
      {
        const auto& edges = g.at(v);
        for (const auto& edge : edges)
        {
          if (!visited[edge.vertex])
            topological_sort_helper(g, edge.vertex, visited, s);
        }
      }

      s.push(v);
    }
  }

  template<typename T>
  std::vector<T> topological_sort(const graph<T>& g)
  {
    if (!is_dag(g))
    {
      std::cout << "Cannot perform topological sort on a directed graph with cycle!\n";
      exit(1);
    }

    std::stack<T> s;
    std::unordered_map<T, bool> visited;
    for (const auto& item : g)
    {
      if (!visited[item.first])
      {
        topological_sort_helper(g, item.first, visited, s);
      }
    }

    std::vector<T> result;
    while (!s.empty())
    {
      result.push_back(s.top());
      s.pop();
    }

    return result;
  }
}