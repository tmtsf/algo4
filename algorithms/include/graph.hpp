#pragma once

#include <memory>

#include "bag.hpp"
#include "util.hpp"

namespace cheetah
{
  struct graph;
  using graph_ptr_t = std::shared_ptr<graph>;

  struct graph
  {
    virtual ~graph(void)
    { }
  public:
    virtual const std::string& description(void) const = 0;
    virtual const std::unordered_map<std::string, int>& lookup_table(void) const = 0;
    virtual const std::vector<std::string>& symbol_table(void) const= 0;
    virtual const std::vector<cheetah::bag<int>>& adjacency_list(void) const= 0;
  };

  namespace mixins
  {
    struct undirected
    {
      virtual ~undirected(void)
      { }
    };

    struct directed
    {
      virtual ~directed(void)
      { }
    public:
      virtual graph_ptr_t reverse(void) const = 0;
    };
  }
}