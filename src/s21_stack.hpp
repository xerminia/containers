#ifndef SRC_S21_STACK_HPP_
#define SRC_S21_STACK_HPP_

#include "s21_list.hpp"

namespace s21 {
template <typename T>
class stack {
 private:
  s21::list<T> list;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() : list() {}  // Создает пустой стек
  explicit stack(std::initializer_list<value_type> const &items)
      : list(items) {}  // std::initializer_list конструктор
  stack(const stack &s) : list(s.list) {}  // Конструктор копирования
  stack(stack &&s) : list(std::move(s.list)) {}  // Конструктор перемещения
  ~stack() {}

  stack &operator=(stack &&s) {
    list.clear();
    list = std::move(s.list);
    return *this;
  }  // Перегрузка оператора присваивания для движущегося объекта

  const_reference top() {
    return list.back();
  }  // Обращение к верхнему элементу

  bool empty() { return list.empty(); }  // Проверка на пустоту контейнера

  size_type size() { return list.size(); }  // Возвращает количество элементов

  void push(const_reference value) {
    list.push_back(value);
  }  // Вставляет элемент в top

  void pop() { list.pop_back(); }  // Удаляет верхний элемент

  void swap(stack &other) {
    list.swap(other.list);
  }  // Меняет содержимое стэков

  template <class... Args>
  void emplace_front(Args &&...args) {
    list.emplace_front(args...);
  }
};
}  // namespace s21

#endif  // SRC_S21_STACK_HPP_
