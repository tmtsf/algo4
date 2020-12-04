#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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