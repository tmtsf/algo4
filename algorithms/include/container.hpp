#pragma once

#include <memory>

namespace cheetah
{
  template<typename T>
  struct node;

  template<typename T>
  using node_ptr_t = std::shared_ptr<node<T>>;

  template<typename T>
  struct node
  {
    node(void) :
      item(T()),
      next(nullptr)
    { }

    node(const T& item_,
         const node_ptr_t<T>& next_) :
      item(item_),
      next(next_)
    { }

    T item;
    node_ptr_t<T> next;
  };

  template<typename T>
  struct iterator
  {
    iterator(void) : ptr(nullptr)
    { }
    iterator(const node_ptr_t<T>& ptr_) :
      ptr(ptr_)
    { }
    iterator& operator++(void)
    {
      ptr = ptr->next;
      return *this;
    }
    iterator operator++(int)
    {
      iterator temp = *this;
      ptr = ptr->next;
      return temp;
    }
    bool operator!=(const iterator& other)
    {
      return ptr != other.ptr;
    }
    const T& operator*(void) const
    {
      return ptr->item;
    }
    T& operator*(void)
    {
      return ptr->item;
    }
  private:
    node_ptr_t<T> ptr;
  };
}