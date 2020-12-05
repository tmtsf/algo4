#pragma once

#include "graph.hpp"

namespace cheetah
{
  namespace
  {
    struct directed_graph : public graph,
                            public mixins::directed
    {
      directed_graph(const char* filename,
                     const std::string& separator = " ")
      {
        std::vector<std::pair<int, int>> edges;
        parse(filename, separator, edges, lookup, symbols);

        adj_list.resize(symbols.size());
        for (const auto& edge : edges)
        {
          adj_list[edge.first].push(edge.second);
        }
      }
      directed_graph(const std::unordered_map<std::string, int>& lookup_,
                     const std::vector<std::string>& symbols_,
                     const std::vector<cheetah::bag<int>>& adj_list_) :
        lookup(lookup_),
        symbols(symbols_),
        adj_list(adj_list_)
      { }
      virtual ~directed_graph(void)
      { }
    public:
      virtual const std::string& description(void) const
      {
        static std::string ss("DirectedGraph");
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
      virtual graph_ptr_t reverse(void) const
      {
        std::vector<cheetah::bag<int>> rev_adj_list(adj_list.size());
        for (std::size_t i=0; i<adj_list.size(); ++i)
        {
          for (const auto& vertex : adj_list[i])
            rev_adj_list[vertex].push(i);
        }

        return std::make_shared<directed_graph>(lookup, symbols, rev_adj_list);
      }
    private:
      std::unordered_map<std::string, int> lookup;
      std::vector<std::string> symbols;
      std::vector<cheetah::bag<int>> adj_list;
    };
  }

  graph_ptr_t make_directed_graph(const char* filename,
                                  const std::string& separator)
  {
    return std::make_shared<directed_graph>(filename, separator);
  }
}