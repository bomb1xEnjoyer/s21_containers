#pragma once

#include "../deque/deque.h"

namespace s21 {

template <typename T, typename Deque = deque<T>>
class stack {
 public:
  // Stack Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Stack Member functions
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &other);
  stack(stack &&other);
  ~stack();
  stack &operator=(stack &&other);

  // Stack Element access
  const_reference top();

  // Stack Capacity
  bool empty();
  size_type size();

  // Stack Modifiers
  void push(const_reference value);
  void pop();
  void swap(stack &other);
  // void insert_many_back(Args &&...args);

 private:
  Deque deque;
};

}  // namespace s21

#include "s21_stack.tpp"