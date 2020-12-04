#pragma once

#include <vector>
#include <unordered_map>

#include "bag.hpp"
#include "util.hpp"

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
  using graph = std::unordered_map<T, cheetah::bag<Edge<T>>>;

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
        graph[vertices.front()].push(vertices[i]);
        graph[vertices[i]].push(vertices.front());
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
        graph[vertices.front()].push(vertices[i]);
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