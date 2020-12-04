#pragma once

#include <unordered_map>
#include <unordered_set>

#include "util.hpp"

namespace cheetah
{
  template<typename T>
  void quick_find_union_find(const char* filename,
                             const std::string& delim)
  {
    std::ifstream in(filename);
    if (!in.is_open())
    {
      std::cout << "File failed to open.\n";
      exit(1);
    }

    std::unordered_map<T, T> id;
    std::string line;
    while (std::getline(in, line))
    {
      std::vector<T> vertices = parse<T>(split(line, delim));
      const T& first = vertices[0];
      const T& second = vertices[1];

      if (id.count(first) && id.count(second) && id[first] == id[second])
        continue;

      if (!id.count(first))
        id[first] = first;

      if (id.count(second))
      {
        T temp = id[second];
        for (auto& pair : id)
        {
          if (pair.second == temp)
          {
            pair.second = id[first];
          }
        }
      }
      else
        id[second] = id[first];
    }

    std::unordered_set<T> components;
    for (const auto& pair : id)
      components.insert(pair.second);

    std::cout << components.size() << " connected components.\n";
  }
}