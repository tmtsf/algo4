#pragma once

#include <numeric>

#include "util.hpp"
#include "bag.hpp"

namespace cheetah
{
  void quick_find_union_find(const char* filename,
                             const std::string& delim)
  {
    std::vector<std::pair<int, int>> edges;
    std::unordered_map<std::string, int> lookup;
    std::vector<std::string> symbols;
    parse(filename, delim, edges, lookup, symbols);

    int count = symbols.size();
    std::vector<int> id(count);
    std::iota(id.begin(),
              id.end(),
              0);

    for (const auto& edge : edges)
    {
      int first = edge.first;
      int second = edge.second;

      int first_id = id[first];
      int second_id = id[second];

      if (first_id == second_id)
        continue;

      for (std::size_t i=0; i<id.size(); ++i)
      {
        if (id[i] == first_id)
          id[i] = second_id;
      }

      --count;
    }

    std::unordered_map<int, cheetah::bag<std::string>> components(count);
    for (std::size_t i=0; i<id.size(); ++i)
      components[id[i]].push(symbols[i]);

    // for (const auto& pair : components)
    // {
    //   std::cout << symbols[pair.first] << ": ";
    //   for (const auto& v : pair.second)
    //     std::cout << v << " ";
    //   std::cout << "\n";
    // }

    // std::cout << "\n";

    std::cout << "There are " << components.size() << " connected components.\n";
  }

  namespace
  {
    int find(const std::vector<int>& id,
             int i)
    {
      while (id[i] != i)
        i = id[i];

      return i;
    }
  }

  void quick_union_union_find(const char* filename,
                              const std::string& delim)
  {
    std::vector<std::pair<int, int>> edges;
    std::unordered_map<std::string, int> lookup;
    std::vector<std::string> symbols;
    parse(filename, delim, edges, lookup, symbols);

    int count = symbols.size();
    std::vector<int> id(count);
    std::iota(id.begin(),
              id.end(),
              0);

    for (const auto& edge : edges)
    {
      int first = edge.first;
      int second = edge.second;

      int first_id = find(id, first);
      int second_id = find(id, second);

      if (first_id == second_id)
        continue;

      id[first_id] = second_id;
      --count;
    }

    std::unordered_map<int, cheetah::bag<std::string>> components(count);
    for (std::size_t i=0; i<id.size(); ++i)
      components[find(id, i)].push(symbols[i]);

    // for (const auto& pair : components)
    // {
    //   std::cout << symbols[pair.first] << ": ";
    //   for (const auto& v : pair.second)
    //     std::cout << v << " ";
    //   std::cout << "\n";
    // }

    // std::cout << "\n";

    std::cout << "There are " << components.size() << " connected components.\n";
  }

  void weighted_quick_union_union_find(const char* filename,
                                       const std::string& delim)
  {
    std::vector<std::pair<int, int>> edges;
    std::unordered_map<std::string, int> lookup;
    std::vector<std::string> symbols;
    parse(filename, delim, edges, lookup, symbols);

    int count = symbols.size();
    std::vector<int> sizes(count, 1);
    std::vector<int> id(count);
    std::iota(id.begin(),
              id.end(),
              0);

    for (const auto& edge : edges)
    {
      int first = edge.first;
      int second = edge.second;

      int first_id = find(id, first);
      int second_id = find(id, second);

      if (first_id == second_id)
        continue;

      if (sizes[first_id] < sizes[second_id])
      {
        id[first_id] = second_id;
        sizes[second_id] += sizes[first_id];
      }
      else
      {
        id[second_id] = first_id;
        sizes[first_id] += sizes[second_id];
      }

      --count;
    }

    std::cout << count << "\n";

    // std::unordered_map<int, cheetah::bag<std::string>> components(count);
    // for (std::size_t i=0; i<id.size(); ++i)
    //   components[find(id, i)].push(symbols[i]);

    // // for (const auto& pair : components)
    // // {
    // //   std::cout << symbols[pair.first] << ": ";
    // //   for (const auto& v : pair.second)
    // //     std::cout << v << " ";
    // //   std::cout << "\n";
    // // }

    // // std::cout << "\n";

    // std::cout << "There are " << components.size() << " connected components.\n";
  }
}