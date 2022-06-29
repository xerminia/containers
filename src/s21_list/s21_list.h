#ifndef SRC_S21_LIST_H_
#define SRC_S21_LIST_H_
#include <iostream>

namespace s21 {

template <typename T>
class S21List {
 private:
  size_t _size;
  Node<T> *head;

 public:
  S21List();
  ~S21List();
  void clear();
  void pop_front();
  void push_back(T date);
  bool empty();

  int size() const;

  class listNode {
   public:
    T data;
    listNode *pNext;
    listNode *pPrev;

    explicit listNode(T d_data = T(), listNode *d_pNext = nullptr,
                      listNode *d_pPrev = nullptr)
        : data(d_data), pNext(d_pNext), pPrev(d_pPrev) {}

    ~listNode() { free_memory(); }
    void free_memory();
  };
  using node = typename list<T>::listNode;
};
}  // namespace s21
#include "s21_list.inc"

#endif  // SRC_S21_LIST_H_
