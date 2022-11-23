#ifndef SRC_S21_QUEUE_HPP_
#define SRC_S21_QUEUE_HPP_

#include "s21_list.hpp"

namespace s21 {
template <typename T>
class queue {
 private:
  s21::list<T> list;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : list() {}  // Создает пустую очередь
  explicit queue(std::initializer_list<value_type> const &items)
      : list(items) {}  // std::initializer_list конструктор
  queue(const queue &s) : list(s.list) {}  // Конструктор копирования
  queue(queue &&s) : list(std::move(s.list)) {}  // Конструктор перемещения
  ~queue() {}

  queue &operator=(queue &&s) {
    list.clear();
    list = std::move(s.list);
    return *this;
  }  // Перегрузка оператора присваивания для движущегося объекта

  const_reference front() { return list.front(); }  // Доступ к первому элементу

  const_reference back() {
    return list.back();
  }  // Доступ к последнему элементу

  bool empty() { return list.empty(); }  // Проверка на пустоту контейнера

  size_type size() { return list.size(); }  // Возвращает количество элементов

  void push(const_reference value) {
    list.push_back(value);
  }  // Вставляет элемент в конец очереди

  void pop() { list.pop_front(); }  // Удаляет первый элемент

  void swap(queue &other) {
    list.swap(other.list);
  }  // Меняет содержимое очередей

  template <class... Args>
  void emplace_back(Args &&...args) {
    list.emplace_back(args...);
  }
};
}  // namespace s21

#endif  // SRC_S21_QUEUE_HPP_
