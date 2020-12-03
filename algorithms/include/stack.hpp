#pragma once

#include "container.hpp"

namespace cheetah
{
  template<typename T>
  struct stack
  {
    stack() : first(nullptr), N(0)
    { }
    void push(const T& elem)
    {
      node_ptr_t<T> temp = std::make_shared<node<T>>(elem, first);
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
    virtual iterator<T> begin(void)
    {
      return iterator<T>(first);
    }
    virtual const iterator<T> begin(void) const
    {
      return iterator<T>(first);
    }
    iterator<T> end(void)
    {
      return iterator<T>{};
    }
    const iterator<T> end(void) const
    {
      return iterator<T>{};
    }
  private:
    node_ptr_t<T> first;
    int N;
  };
}