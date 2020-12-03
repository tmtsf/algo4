#pragma once

#include "container.hpp"

namespace cheetah
{
  template<typename T>
  struct stack : public impl::container<T>
  {
    using node_ptr_t = typename impl::container<T>::node_ptr_t;
    using iterator = typename impl::container<T>::iterator;

    stack() : first(nullptr), N(0)
    { }
    void push(const T& elem)
    {
      node_ptr_t temp = this->make_node(elem, first);
      first = temp;
      ++N;
    }
    T& top(void)
    {
      return first->item;
    }
    const T& top(void) const
    {
      return first->item;
    }
    bool empty(void)
    {
      return N == 0;
    }
    void pop(void)
    {
      first = first->next;
      --N;
    }
    int size(void)
    {
      return N;
    }
    virtual iterator begin(void)
    {
      return iterator(first);
    }
  private:
    node_ptr_t first;
    int N;
  };
}