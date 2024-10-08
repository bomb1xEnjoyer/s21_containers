#pragma once

// deque Member functions
template <typename T>
s21::deque<T>::deque() {
  list.size = 0;
  list.head = nullptr;
  list.tail = nullptr;
}

template <typename T>
s21::deque<T>::deque(std::initializer_list<value_type> const &items) {

}

template <typename T>
s21::deque<T>::deque(const deque &other) {
  list.size = other.size;
  
}

template <typename T>
s21::deque<T>::deque(deque &&other) {
  list.size = other.size;
  list.head = other.list.head;
  list.tail = other.list.tail;
  other.size = 0;
  other.list.head = nullptr;
  other.list.tail = nullptr;
}

template <typename T>
s21::deque<T>::~deque() {

}

// deque Element access
template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::top() const {

}

template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::back() const {

}

// deque Capacity
template <typename T>
bool s21::deque<T>::empty() const {

}

template <typename T>
typename s21::deque<T>::size_type s21::deque<T>::size() const {

}

// Queue Modifiers
template <typename T>
void s21::deque<T>::push_back(const_reference value) {

}

template <typename T>
void s21::deque<T>::push_front(const_reference value) {

}

template <typename T>
void s21::deque<T>::pop_front() {

}

// void pop_back(); // no need

template <typename T>
void s21::deque<T>::swap(deque &other) {

}