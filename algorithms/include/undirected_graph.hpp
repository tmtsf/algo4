#pragma once

#include "graph.hpp"

namespace cheetah
{
  namespace
  {
    struct undirected_graph : public graph,
                              public mixins::undirected
    {
      undirected_graph(const char* filename,
                      const std::string& separator = " ")
      {
        std::vector<std::pair<int, int>> edges;
        parse(filename, separator, edges, lookup, symbols);

        adj_list.resize(symbols.size());
        for (const auto& edge : edges)
        {
          adj_list[edge.first].push(edge.second);
          adj_list[edge.second].push(edge.first);
        }
      }
      virtual ~undirected_graph(void)
      { }
    public:
      virtual const std::string& description(void) const
      {
        static std::string ss("UndirectedGraph");
        return ss;
      }
      virtual const std::unordered_map<std::string, int>& lookup_table(void) const
      {
        return lookup;
      }
      virtual const std::vector<std::string>& symbol_table(void) const
      {
        return symbols;
      }
      virtual const std::vector<cheetah::bag<int>>& adjacency_list(void) const
      {
        return adj_list;
      }
    private:
      std::unordered_map<std::string, int> lookup;
      std::vector<std::string> symbols;
      std::vector<cheetah::bag<int>> adj_list;
    };
  }

  graph_ptr_t make_undirected_graph(const char* filename,
                                    const std::string& separator)
  {
    return std::make_shared<undirected_graph>(filename, separator);
  }
}