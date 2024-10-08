#pragma once

// Deque Member functions
template <typename T> s21::deque<T>::deque() {
  list.size = 0;
  list.head = nullptr;
  list.tail = nullptr;
}

template <typename T>
s21::deque<T>::deque(std::initializer_list<value_type> const &items) {
  for (auto item = items.begin(); item != items.end(); ++item)
    push_back(*item);
}

template <typename T> s21::deque<T>::deque(const deque &other) {
  list.size = other.size;
}

template <typename T> s21::deque<T>::deque(deque &&other) {
  list.size = other.size;
  list.head = other.list.head;
  list.tail = other.list.tail;
  other.size = 0;
  other.list.head = nullptr;
  other.list.tail = nullptr;
}

template <typename T> s21::deque<T>::~deque() {}

// Deque Element access
template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::top() const {
  return list.head->data;
}

template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::back() const {
  return list.tail->data;
}

// Deque Capacity
template <typename T> bool s21::deque<T>::empty() const {
  return list.head == nullptr;
}

template <typename T>
typename s21::deque<T>::size_type s21::deque<T>::size() const {
  return list.size;
}

// Deque Modifiers
template <typename T> void s21::deque<T>::push_back(const_reference value) {
  Node *new_node = new Node(value);
  if (list.tail) {
    new_node->next = list.tail;
    list.tail->previous = new_node;
    list.tail = new_node;
  } else {
    list.tail = new_node;
    if (list.head) {
      Node *current = list.head;
      while (list.head->previous)
        current = current->previous;
      current->previous = list.tail;
      list.tail->next = current;
    } else
      list.head = new_node;
  }
  ++list.size;
}

template <typename T> void s21::deque<T>::push_front(const_reference value) {
  Node *new_node = new Node(value);
  if (list.head) {
    new_node->previous = list.head;
    list.head->next = new_node;
    list.head = new_node;
  } else {
    list.head = new_node;
    if (list.tail) {
      Node *current = list.tail;
      while (current->next)
        current = current->next;
      current->next = list.head;
      list.head->previous = current;
    } else
      list.tail = new_node;
  }
}

template <typename T> void s21::deque<T>::pop_front() {}

template <typename T> void s21::deque<T>::swap(deque &other) {}