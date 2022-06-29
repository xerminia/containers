#include "s21_list.h"

namespace s21 {

template <typename T>
S21List<T>::S21List() : head(nullptr), Size(0) {}

template <class T>
S21List<T>::~S21List() {
  clear();
}

template <class T>
void S21List<T>::clear() {
  while (Size) {
    pop_front();
  }
}

template <class T>
void S21List<T>::push_back(T data) {
  if (empty()) {
    head = new Node<T>(data);
  } else {
    Node<T> *current = head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  Size++;
}

template <class T>
bool S21List<T>::empty() {
  return head == nullptr;
}

template <class T>
void S21List<T>::pop_front() {
  Node<T> *tmp = head;
  head = head->pNext;
  delete tmp;
  Size--;
}

template <class T>
int S21List<T>::size() const {
  return Size;
}

}  // namespace s21
