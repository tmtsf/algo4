#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

namespace cheetah
{
  // Cannot stor edges as unordered set of pairs
  // Pairs as key to unordered map or entry to unordered set require hashing
  template<typename T>
  struct Edge
  {
    Edge() :
      vertex(T{}),
      weight(0.)
    { }

    Edge(const T& vertex_) :
      vertex(vertex_),
      weight(1.0)
    { }

    Edge(const T& vertex_,
         double weight_) :
      vertex(vertex_),
      weight(weight_)
    { }

    T vertex;
    double weight;
  };

  template<typename T>
  using graph = std::unordered_map<T, std::vector<Edge<T>>>;

  namespace
  {
    std::vector<std::string> split(const std::string& str,
                                   const std::string& delim)
    {
      std::vector<std::string> tokens;
      std::size_t start = 0;
      std::size_t pos;
      while (true)
      {
        pos = str.find(delim, start);
        tokens.push_back(str.substr(start, pos-start));
        if (pos == std::string::npos)
        {
          break;
        }
        else
        {
          start = pos + delim.size();
        }
      }

      return tokens;
    }

    template<typename T>
    std::vector<T> parse(const std::vector<std::string>& tokens)
    {
      std::vector<T> results;
      for (const auto& token : tokens)
      {
        std::istringstream iss(token);
        T result;
        iss >> result;
        results.push_back(result);
      }

      return results;
    }

    template<>
    std::vector<std::string> parse(const std::vector<std::string>& tokens)
    {
      return tokens;
    }
  }

  template<typename T>
  graph<T> make_undirected_graph(const char* filename,
                                 const std::string& separator = " ")
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
      std::vector<T> vertices = parse<T>(split(line, separator));
      if (vertices.size() == 1)
      {
        std::cout << "Cannot create an edge with only one vertex supplied!\n";
        exit(1);
      }

      for (std::size_t i=1; i<vertices.size(); ++i)
      {
        graph[vertices.front()].emplace_back(vertices[i]);
        graph[vertices[i]].emplace_back(vertices.front());
      }
    }

    // for (const auto& item : graph)
    // {
    //   std::cout << item.first << ": ";
    //   for (const auto& edge : item.second)
    //     std::cout << "[" << edge.vertex << "] -> ";

    //   std::cout << "[]\n";
    // }

    return graph;
  }

  template<typename T>
  graph<T> make_directed_graph(const char* filename,
                               const std::string& separator = " ")
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
      std::vector<T> vertices = parse<T>(split(line, separator));
      if (vertices.size() == 1)
      {
        std::cout << "Cannot create an edge with only one vertex supplied!\n";
        exit(1);
      }

      for (std::size_t i=1; i<vertices.size(); ++i)
      {
        graph[vertices.front()].emplace_back(vertices[i]);
      }
    }

    // for (const auto& item : graph)
    // {
    //   std::cout << item.first << ": ";
    //   for (const auto& edge : item.second)
    //     std::cout << "[" << edge.vertex << "] -> ";

    //   std::cout << "[]\n";
    // }

    return graph;
  }
}