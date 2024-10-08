#pragma once

#include <iostream>

namespace s21 {

template <typename T> class deque {
public:
  // Deque Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  // Deque Member functions
  deque();
  deque(std::initializer_list<value_type> const &items);
  deque(const deque &other);
  deque(deque &&other);
  ~deque();
  // operator=(deque &&other);

  // Deque Element access
  const_reference top() const;
  const_reference back() const;

  // Deque Capacity
  bool empty() const;
  size_type size() const;

  // deque Modifiers
  void push_back(const_reference value);
  void push_front(const_reference value);
  void pop_front();
  void swap(deque &other);

private:
  struct Node {
    value_type data;
    Node *next = nullptr;
    Node *previous = nullptr;
    Node(value_type data, Node *next = nullptr, Node *previous = nullptr)
        : data(data), next(next), previous(previous) {}
  };
  struct LinkedList {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };
  LinkedList list;
};

} // namespace s21

#include "deque.tpp"