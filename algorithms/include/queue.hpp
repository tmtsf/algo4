#pragma once

#include "container.hpp"

namespace cheetah
{
  template<typename T>
  struct queue : public impl::container<T>
  {
    using node_ptr_t = typename impl::container<T>::node_ptr_t;
    using iterator = typename impl::container<T>::iterator;

    queue() : first(nullptr), last(nullptr), N(0)
    { }
    void push(const T& elem)
    {
      node_ptr_t temp = last;
      last = this->make_node(elem, nullptr);
      if (empty())
        first = last;
      else
        temp->next = last;

      ++N;
    }
    T& front(void)
    {
      return first->item;
    }
    const T& front(void) const
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
      if (empty())
        last = nullptr;
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
    node_ptr_t last;
    int N;
  };
}