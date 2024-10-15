#pragma once

// Queue Member functions
template <typename T, typename Deque>
s21::queue<T, Deque>::queue() : deque() {}

template <typename T, typename Deque>
s21::queue<T, Deque>::queue(std::initializer_list<value_type> const &items)
    : deque(items) {}

template <typename T, typename Deque>
s21::queue<T, Deque>::queue(const queue &other) : deque(other.deque) {}

template <typename T, typename Deque>
s21::queue<T, Deque>::queue(queue &&other) : deque(std::move(other)) {}

template <typename T, typename Deque>
s21::queue<T, Deque>::~queue() {}

template <typename T, typename Deque>
s21::queue<T, Deque> &s21::queue<T, Deque>::operator=(queue &&other) {
  if (this != other) deque = other.deque;
  return *this;
}

// Queue Element access
template <typename T, typename Deque>
typename s21::queue<T, Deque>::const_reference s21::queue<T, Deque>::front() {
  return deque.front();
}

template <typename T, typename Deque>
typename s21::queue<T, Deque>::const_reference s21::queue<T, Deque>::back() {
  return deque.back();
}

// Queue Capacity
template <typename T, typename Deque>
bool s21::queue<T, Deque>::empty() {
  return deque.empty();
}

template <typename T, typename Deque>
typename s21::queue<T, Deque>::size_type s21::queue<T, Deque>::size() {
  return deque.size();
}

// Queue Modifiers
template <typename T, typename Deque>
void s21::queue<T, Deque>::push(const_reference value) {
  deque.push_back(value);
}

template <typename T, typename Deque>
void s21::queue<T, Deque>::pop() {
  deque.pop_front();
}

template <typename T, typename Deque>
void s21::queue<T, Deque>::swap(queue &other) {
  std::swap(deque, other.deque);
}

template <typename T, typename Deque>
template <typename... Args>
void s21::queue<T, Deque>::insert_many_back(Args &&...args) {
  std::initializer_list<int>{(push(std::forward<Args>(args)), 0)...};
}