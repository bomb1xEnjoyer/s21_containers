#pragma once

// Array Member functions
template <typename T, size_t N>
s21::array<T, N>::array() : _size(N) {}

template <typename T, size_t N>
s21::array<T, N>::array(std::initializer_list<value_type> const &items)
    : _size(items.size()) {
  std::copy(items.begin(), items.end(), _data);
}

template <typename T, size_t N>
s21::array<T, N>::array(const array &other) : _size(N) {
  std::copy(other._data, other._data + N, _data);
}

template <typename T, size_t N>
s21::array<T, N>::array(array &&other) : _size(N) {
  std::move(other._data, other._data + N, _data);
  other._size = 0;
}

template <typename T, size_t N>
s21::array<T, N>::~array() {}

template <typename T, size_t N>
s21::array<T, N> &s21::array<T, N>::operator=(array &&other) {
  _size = other._size;
  std::move(other._data, other._data + N, _data);
  return *this;
}

// Array Element access
template <typename T, size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::at(size_type pos) {
  if (pos >= _size || pos < 0)
    throw std::out_of_range("Index out of range");
  else if (empty())
    throw std::logic_error("Array is empty");
  return (*this)[pos];
}

template <typename T, size_t N>
typename s21::array<T, N>::reference s21::array<T, N>::operator[](
    size_type pos) {
  if (pos >= _size || pos < 0)
    throw std::out_of_range("Index out of range");
  else if (empty())
    throw std::logic_error("Array is empty");
  return _data[pos];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::front() const {
  if (empty()) throw std::logic_error("Array is empty");
  return _data[0];
}

template <typename T, size_t N>
typename s21::array<T, N>::const_reference s21::array<T, N>::back() const {
  if (empty()) throw std::logic_error("Array is empty");
  return _data[N - 1];
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::data() {
  if (empty()) throw std::logic_error("Array is empty");
  return _data;
}

// Array Iterators
template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::begin() {
  if (empty()) throw std::logic_error("Array is empty");
  return &_data[0];
}

template <typename T, size_t N>
typename s21::array<T, N>::iterator s21::array<T, N>::end() {
  if (empty()) throw std::logic_error("Array is empty");
  return &_data[_size];
}

// Array Capacity
template <typename T, size_t N>
bool s21::array<T, N>::empty() const {
  return _size == 0;
}

template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::size() const {
  return _size;
}

template <typename T, size_t N>
typename s21::array<T, N>::size_type s21::array<T, N>::max_size() const {
  return _size;
}

// Array Modifiers
template <typename T, size_t N>
void s21::array<T, N>::swap(array &other) {
  if (*this != other) {
    std::swap(_data, other._data);
    std::swap(_size, other._size);
  }
}

template <typename T, size_t N>
void s21::array<T, N>::fill(const_reference value) {
  for (size_t i = 0; i < _size; ++i) _data[i] = value;
}