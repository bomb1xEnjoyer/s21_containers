#pragma once

// Deque Member functions
template <typename T>
s21::deque<T>::deque() {
  _list.size = 0;
  _list.head = nullptr;
  _list.tail = nullptr;
}

template <typename T>
s21::deque<T>::deque(std::initializer_list<value_type> const &items) {
  for (auto item = items.begin(); item != items.end(); ++item) push_back(*item);
}

template <typename T>
s21::deque<T>::deque(const deque &other) {
  Node *current = other._list.head;
  while (current) {
    push_back(current->data);
    current = current->previous;
  }
}

template <typename T>
s21::deque<T>::deque(deque &&other) {
  _list.size = other._list.size;
  _list.head = other._list.head;
  _list.tail = other._list.tail;
  other._list.size = 0;
  other._list.head = nullptr;
  other._list.tail = nullptr;
}

template <typename T>
s21::deque<T>::~deque() {
  while (_list.head) pop_front();
}

template <typename T>
s21::deque<T> &s21::deque<T>::operator=(deque &&other) {
  if (this != &other) {
    while (_list.head) pop_front();
    _list.size = other._list.size;
    _list.head = other._list.head;
    _list.tail = other._list.tail;
    other._list.size = 0;
    other._list.head = nullptr;
    other._list.tail = nullptr;
  }
  return *this;
}

// Deque Element access
template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::front() const {
  if (_list.head)
    return _list.head->data;
  else
    throw std::logic_error("The deque is empty, front pointer equals nullptr");
}

template <typename T>
typename s21::deque<T>::const_reference s21::deque<T>::back() const {
  if (_list.tail)
    return _list.tail->data;
  else
    throw std::logic_error("The deque is empty, back pointer equals nullptr");
}

// Deque Capacity
template <typename T>
bool s21::deque<T>::empty() const {
  return _list.head == nullptr;
}

template <typename T>
typename s21::deque<T>::size_type s21::deque<T>::size() const {
  return _list.size;
}

// Deque Modifiers
template <typename T>
void s21::deque<T>::push_back(const_reference value) {
  Node *new_node = new Node(value);
  if (_list.tail) {
    new_node->next = _list.tail;
    _list.tail->previous = new_node;
    _list.tail = new_node;
  } else {
    _list.tail = new_node;
    if (_list.head) {
      Node *current = _list.head;
      while (_list.head->previous) current = current->previous;
      current->previous = _list.tail;
      _list.tail->next = current;
    } else
      _list.head = new_node;
  }
  ++_list.size;
}

template <typename T>
void s21::deque<T>::push_front(const_reference value) {
  Node *new_node = new Node(value);
  if (_list.head) {
    new_node->previous = _list.head;
    _list.head->next = new_node;
    _list.head = new_node;
  } else {
    _list.head = new_node;
    if (_list.tail) {
      Node *current = _list.tail;
      while (current->next) current = current->next;
      current->next = _list.head;
      _list.head->previous = current;
    } else
      _list.tail = new_node;
  }
  ++_list.size;
}

template <typename T>
void s21::deque<T>::pop_front() {
  if (_list.head) {
    if (_list.head->previous) {
      Node *previous_node = _list.head->previous;
      delete _list.head;
      _list.head = previous_node;
    } else {
      Node *node = _list.head;
      delete node;
      _list.head = nullptr;
      _list.tail = nullptr;
    }
    --_list.size;
  }
}

template <typename T>
void s21::deque<T>::swap(deque &other) {
  std::swap(_list, other._list);
}