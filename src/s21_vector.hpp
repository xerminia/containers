#ifndef SRC_S21_VECTOR_HPP_
#define SRC_S21_VECTOR_HPP_

namespace s21 {
template <typename T>
class vector {
 private:
  T* arr_;
  // Размер
  size_t size_;
  // Количество выделенной памяти
  size_t capacity_;

 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  class iterator {
   public:
    T* array_;
    iterator() : array_(nullptr) {}
    explicit iterator(const vector<T>& one) { array_ = one.arr_; }
    T& operator+(int n) { return *(array_ + n); }
    T& operator-(int n) { return *(array_ - n); }
    T& operator++(int) { return *array_++; }
    T& operator--(int) { return *array_--; }
    T& operator++() { return *++array_; }
    T& operator--() { return *--array_; }

    bool operator!=(const iterator& it) { return array_ != it.array_; }
    bool operator==(const iterator& it) { return array_ == it.array_; }

    T& operator*() const { return *array_; }

    ~iterator() { array_ = nullptr; }
  };

  class const_iterator {
    const T* array_;
    const_iterator() : array_(nullptr) {}
    explicit const_iterator(T* one) : array_(one) {}
    T& operator+(int n) { return *(array_ + n); }
    T& operator-(int n) { return *(array_ - n); }
    T& operator=(const iterator& it) { return array_ = it; }

    T& operator++(int) { return *array_++; }
    T& operator--(int) { return *array_--; }
    T& operator++() { return *++array_; }
    T& operator--() { return *--array_; }

    bool operator!=(const iterator& it) { return array_ != it.array; }
    bool operator==(const iterator& it) { return array_ == it.array; }

    ~const_iterator() { delete[] array_; }
  };

  vector();
  explicit vector(size_type n);
  explicit vector(std::initializer_list<value_type> const& items);
  vector(const vector& v);
  vector(vector&& v);
  ~vector();
  vector operator=(vector&& v);
  reference at(size_type pos);
  T& operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();
  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector& other);
  template <typename... Args>
  iterator emplace(const_iterator pos, Args&&... args);
  template <typename... Args>
  void emplace_back(Args&&... args);
};

template <typename T>
template <typename... Args>
void vector<T>::emplace_back(Args&&... args) {
  for (auto& elem : {args...}) {
    push_back(elem);
  }
}

// Вставляет элементы в конкретную позицию и возвращает итератор, указывающий
// на новый элемент +
template <typename T>
typename vector<T>::iterator vector<T>::insert(vector<T>::iterator pos,
                                               const T& value) {
  T* newarr = new T[size_ + 1];
  size_t count = 0;
  for (; pos != begin(); count++, --pos) {
  }
  newarr[count] = value;
  for (size_t i = 0; i < size_; i++) {
    if (i < count) {
      newarr[i] = arr_[i];
    } else {
      newarr[i + 1] = arr_[i];
    }
  }
  delete[] arr_;
  arr_ = newarr;
  size_++;
  capacity_ = size_;
  pos = begin();
  while (count) {
    count--;
    ++pos;
  }
  return pos;
}

// Уменьшает использование памяти, освобождая неиспользуемую память +
template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    T* newarr = new T[size_];
    for (size_t i = 0; i < size_; i++) {
      newarr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = newarr;
    capacity_ = size_;
  }
}

// Стирает элемент на позиции
template <typename T>
void vector<T>::erase(vector<T>::iterator pos) {
  size_t count;
  for (count = 0; pos != begin(); count++, --pos) {
  }
  for (size_t i = count; i < size_; ++i) {
    arr_[i] = arr_[i + 1];
  }
  --size_;
}

// Перегрузка оператора присваивания для движущегося объекта +
template <typename T>
vector<T> vector<T>::operator=(vector<T>&& a) {
  delete[] arr_;
  size_ = a.size_;
  capacity_ = a.capacity_;
  arr_ = a.arr_;
  a.size_ = 0;
  a.capacity_ = 0;
  a.arr_ = nullptr;
  return *this;
}

// Возвращает итератор в начало +
template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(*this);
}

// Возвращает итератор в конец +
template <typename T>
typename vector<T>::iterator vector<T>::end() {
  iterator vec_iterator = begin();
  for (size_t i = 0; i != size_; i++) {
    ++vec_iterator;
  }
  ++vec_iterator;
  return vec_iterator;
}

// Проверяет, пуст ли контейнер +
template <typename T>
bool vector<T>::empty() {
  return size_ == 0;
}

// Деструктор +
template <typename T>
vector<T>::~vector() {
  clear();
}

// Очищаем содержимое +
template <typename T>
void vector<T>::clear() {
  if (arr_) {
    size_ = 0;
    capacity_ = 0;
    delete[] arr_;
    arr_ = nullptr;
  }
}

// Конструктор по умолчанию, создает пустой вектор +
template <typename T>
vector<T>::vector() : arr_(nullptr), size_(0), capacity_(0) {}

// Параметризованный конструктор, создает вектор размера n +
template <typename T>
vector<T>::vector(size_type n) : size_(n), capacity_(n) {
  arr_ = new T[n];
}

// Конструктор копирования +
template <typename T>
vector<T>::vector(const vector& v) : size_(v.size_), capacity_(v.capacity_) {
  arr_ = new T[v.size_];
  for (size_t i = 0; i < size_; i++) {
    arr_[i] = v.arr_[i];
  }
}

// Конструктор списка инициализаторов,
// создает вектор, инициализированный с помощью std::initializer_list +
template <typename T>
vector<T>::vector(std::initializer_list<value_type> const& items)
    : arr_(nullptr), size_(0), capacity_(0) {
  for (auto& elem : items) {
    push_back(elem);
  }
  shrink_to_fit();
}

// Конструктор перемещения +
template <typename T>
vector<T>::vector(vector&& v)
    : arr_(v.arr_), size_(v.size_), capacity_(v.capacity_) {
  for (size_t i = 0; i < size_; i++) {
    arr_[i] = v.arr_[i];
  }
  v.size_ = 0;
  v.capacity_ = 0;
  v.arr_ = nullptr;
}

// Доступ к указанному элементу +
template <typename T>
T& vector<T>::operator[](size_t pos) {
  return arr_[pos];
}

// Доступ к указанному элементу с проверкой границ +
template <typename T>
typename vector<T>::reference vector<T>::at(typename vector<T>::size_type pos) {
  if (pos > size_) {
    throw std::out_of_range("terminate called after throwing an instance of ");
  }
  return arr_[pos];
}

// Прямой доступ к базовому массиву +
template <typename T>
typename vector<T>::iterator vector<T>::data() {
  return begin();
}

// Получить доступ к первому элементу +
template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return arr_[0];
}

// Получить доступ к последнему элементу +
template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return arr_[size_ - 1];
}

// Возвращает количество элементов +
template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return size_;
}

// Возвращает максимально возможное количество элементов +
template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return (std::numeric_limits<size_type>::max() / sizeof(T*));
}

// Возвращает количество элементов, которые могут храниться в выделенной на
// данный момент памяти +
template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return capacity_;
}

// выделяет хранилище элементов размера и копирует текущие элементы массива
// в новый выделенный массив +
template <typename T>
void vector<T>::reserve(size_type size) {
  if (!size) size = 1;
  if (size <= capacity_) {
  } else {
    T* newarr = new T[size];
    for (size_t i = 0; i < size_; i++) {
      newarr[i] = arr_[i];
    }
    delete[] arr_;
    arr_ = newarr;
    capacity_ = size;
  }
}

// Добавляем элемент в конец +
template <typename T>
void vector<T>::push_back(const_reference value) {
  if (capacity_ == size_) {
    reserve(2 * size_);
  }
  arr_[size_] = value;
  ++size_;
}

// Удаляет последний элемент +
template <typename T>
void vector<T>::pop_back() {
  --size_;
}

// Меняет содержимое местами +
template <typename T>
void vector<T>::swap(vector& other) {
  auto size = size_;
  auto capacity = capacity_;
  auto arr = arr_;
  size_ = other.size_;
  capacity_ = other.capacity_;
  arr_ = other.arr_;
  other.size_ = size;
  other.capacity_ = capacity;
  other.arr_ = arr;
}

}  // namespace s21

#endif  // SRC_S21_VECTOR_HPP_
