#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace cheetah
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

  // template<typename T>
  // std::vector<T> parse(const std::vector<std::string>& tokens)
  // {
  //   std::vector<T> results;
  //   for (const auto& token : tokens)
  //   {
  //     std::istringstream iss(token);
  //     T result;
  //     iss >> result;
  //     results.push_back(result);
  //   }

  //   return results;
  // }

  // template<>
  // std::vector<std::string> parse(const std::vector<std::string>& tokens)
  // {
  //   return tokens;
  // }

  void parse(const char* filename,
             const std::string& delim,
             std::vector<std::pair<int, int>>& edges,
             std::unordered_map<std::string, int>& lookup,
             std::vector<std::string>& symbols)
  {
    std::ifstream in(filename);
    if (!in.is_open())
    {
      std::cout << "File failed to open.\n";
      exit(1);
    }


    std::string line;
    while (std::getline(in, line))
    {
      std::vector<std::string> vertices = split(line, delim);
      for (const std::string& vertex : vertices)
      {
        if (!lookup.count(vertex))
          lookup[vertex] = lookup.size();
      }

      for (std::size_t i=1; i<vertices.size(); ++i)
        edges.emplace_back(lookup[vertices.front()], lookup[vertices[i]]);
    }

    symbols.resize(lookup.size());
    for (const auto& item : lookup)
      symbols[item.second] = item.first;
  }
}