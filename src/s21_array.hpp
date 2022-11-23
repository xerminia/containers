#ifndef SRC_S21_ARRAY_HPP_
#define SRC_S21_ARRAY_HPP_

namespace s21 {
template <class T, size_t size_>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  array() = default;  // Конструктор по умолчанию
  ~array() = default;

  explicit array(std::initializer_list<value_type> const &items) {
    int i = 0;
    for (auto &elem : items) {
      array_[i] = elem;
      i++;
    }
  }  // Коструктор с помощью списка иницилизации

  array(const array &a) {
    for (size_t i = 0; i < size_; i++) {
      array_[i] = a.array_[i];
    }
  }  // Конструктор копирования

  array(array &&a) = default;  // Конструктор перемещения

  array &operator=(array &&a) =
      default;  // Перегрузка оператора присваивания для движущигося оьекта

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Out of bounds array");
    }
    return array_[pos];
  }  // Доступ к указаному элементу с проверкой границ

  reference operator[](size_type pos) {
    return array_[pos];
  }  // Доступ к указаному элементу

  const_reference front() {
    return array_[0];
  }  // Получить доступ к первому элемнту

  const_reference back() {
    return array_[size_ - 1];
  }  // Получить доступ к последнему элемнту

  iterator data() { return array_; }  // Прямой доступ к базовому массиву

  ///

  iterator begin() { return array_; }  // Возвращает итератор в начало

  iterator end() {
    return (array_ + size_ - 1);
  }  // Возвращает итератор в конец

  ///

  bool empty() { return (size_ == 0); }  // Проверяет массив на пустоту +?

  size_type size() { return size_; }  // Возвращает количество элементов

  size_type max_size() {
    return size_;
  }  // Возвращает максимальное количество элементов

  ///

  void swap(array &other) {
    if (size_ != other.size()) {
      throw std::out_of_range("Different array sizes");
    }
    value_type tmp;
    for (size_t i = 0; i < size_; i++) {
      tmp = array_[i];
      array_[i] = other.array_[i];
      other.array_[i] = tmp;
    }
  }  // Меняет массивы местами

  void fill(const_reference value) {
    for (size_t i = 0; i < size(); i++) {
      array_[i] = value;
    }
  }  // Заполняет весь массив заданным значением

 private:
  alignas(T) T array_[sizeof(T) * size_] = {};
};
}  // namespace s21

#endif  // SRC_S21_ARRAY_HPP_
