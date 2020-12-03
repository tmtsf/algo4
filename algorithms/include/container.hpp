#pragma once

#include <memory>

namespace cheetah
{
  namespace impl
  {
    template<typename T>
    struct container
    {
      struct node;
      using node_ptr_t = std::shared_ptr<node>;

      struct node
      {
        node(void) :
          item(T()),
          next(nullptr)
        { }

        node(const T& item_,
             const node_ptr_t& next_) :
          item(item_),
          next(next_)
        { }

        T item;
        node_ptr_t next;
      };

      struct iterator
      {
        iterator(void) : ptr(nullptr)
        { }
        iterator(const node_ptr_t& ptr_) : ptr(ptr_)
        { }
        iterator operator++(void)
        {
          ptr = ptr->next;
          return *this;
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
        node_ptr_t ptr;
      };

      virtual ~container(void)
      { }
      node_ptr_t make_node(void)
      {
        return std::make_shared<node>();
      }
      node_ptr_t make_node(const T& elem,
                           const node_ptr_t& next)
      {
        return std::make_shared<node>(elem, next);
      }
      virtual iterator begin(void) = 0;
      iterator end(void)
      {
        return iterator{};
      }
    };
  }
}