#pragma once

#include "container.hpp"

namespace cheetah
{
  template<typename T>
  struct queue
  {
    queue() : first(nullptr), last(nullptr), N(0)
    { }
    void push(const T& elem)
    {
      node_ptr_t<T> temp = last;
      last = std::make_shared<node<T>>(elem, nullptr);
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
    node_ptr_t<T> last;
    int N;
  };
}