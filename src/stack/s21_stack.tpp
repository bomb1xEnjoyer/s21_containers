#pragma once

// Stack Member functions
template <typename T, typename Deque>
s21::stack<T, Deque>::stack() : _deque() {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(std::initializer_list<value_type> const &items)
    : _deque(items) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(const stack &other) : _deque(other._deque) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::stack(stack &&other) : _deque(std::move(other)) {}

template <typename T, typename Deque>
s21::stack<T, Deque>::~stack() {}

template <typename T, typename Deque>
s21::stack<T, Deque> &s21::stack<T, Deque>::operator=(stack &&other) {
  if (this != other) _deque = other._deque;
  return *this;
}

// Stack Element access
template <typename T, typename Deque>
typename s21::stack<T, Deque>::const_reference s21::stack<T, Deque>::top() {
  return _deque.front();
}

// Stack Capacity

template <typename T, typename Deque>
bool s21::stack<T, Deque>::empty() {
  return _deque.empty();
}

template <typename T, typename Deque>
typename s21::stack<T, Deque>::size_type s21::stack<T, Deque>::size() {
  return _deque.size();
}

// Stack Modifiers

template <typename T, typename Deque>
void s21::stack<T, Deque>::push(const_reference value) {
  _deque.push_front(value);
}

template <typename T, typename Deque>
void s21::stack<T, Deque>::pop() {
  _deque.pop_front();
}

template <typename T, typename Deque>
void s21::stack<T, Deque>::swap(stack &other) {
  std::swap(_deque, other._deque);
}

template <typename T, typename Deque>
template <typename... Args>
void s21::stack<T, Deque>::insert_many_back(Args &&...args) {
  std::initializer_list<int>{(push(std::forward<Args>(args)), 0)...};
}