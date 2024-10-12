#pragma once

// Stack Member functions
template <typename T, typename Deque>
s21::stack<T, Deque>::stack() : deque() {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(std::initializer_list<value_type> const &items)
    : deque(items) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(const stack &other) : deque(other.deque) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(stack &&other) : deque(std::move(other)) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::~stack() {}

template <typename T, typename Deque>
s21::stack<T, Deque> &s21::stack<T, Deque>::operator=(stack &&other) {
  if (this != other) deque = other.deque;
  return *this;
}

// Stack Element access
template <typename T, typename Deque>
typename s21::stack<T, Deque>::const_reference s21::stack<T, Deque>::top() {
  return deque.front();
}

// Stack Capacity

template <typename T, typename Deque>
bool s21::stack<T, Deque>::empty() {
  return deque.empty();
}

template <typename T, typename Deque>
typename s21::stack<T, Deque>::size_type s21::stack<T, Deque>::size() {
  return deque.size();
}

// Stack Modifiers

template <typename T, typename Deque>
void s21::stack<T, Deque>::push(const_reference value) {
  deque.push_front(value);
}

template <typename T, typename Deque>
void s21::stack<T, Deque>::pop() {
  deque.pop_front();
}

template <typename T, typename Deque>
void s21::stack<T, Deque>::swap(stack &other) {
  std::swap(deque, other.deque);
}

// template <typename T, typename Deque>
// void insert_many_back(Args &&...args);