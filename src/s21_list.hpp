#ifndef SRC_S21_LIST_HPP_
#define SRC_S21_LIST_HPP_

namespace s21 {

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  //  CLASS SINGLY LINKED LIST
  class listNode {
   public:
    T data;
    listNode *pNext;
    listNode *pPrev;

    listNode() : data(), pNext(nullptr), pPrev(nullptr) {}
    explicit listNode(T const &data = T(), listNode *pNext = nullptr,
                      listNode *pPrev = nullptr) {
      this->data = data;
      this->pNext = pNext;
      this->pPrev = pPrev;
    }
    ~listNode() { free_memory(); }
    inline void free_memory() {
      pNext = nullptr;
      pPrev = nullptr;
    }
  };
  using Node = typename list<T>::listNode;

  //  CLASS ITERATOR
  class ListIterator {
   public:
    Node *itr;

    ListIterator() { itr = nullptr; }
    explicit ListIterator(const list<T> &other) { itr = other.head_; }
    ~ListIterator() { itr = nullptr; }
    inline T &operator*() {
      if (itr == nullptr) {
        throw std::invalid_argument("attempt to dereference a null pointer");
      }
      return itr->data;
    }
    inline ListIterator operator++(int) {
      if (itr == nullptr) {
        throw std::invalid_argument("attempt to dereference a null pointer");
      }
      ListIterator ptr = *this;
      itr = itr->pNext;
      return ptr;
    }

    inline ListIterator operator++() {
      if (itr == nullptr) {
        throw std::invalid_argument("attempt to dereference a null pointer");
      }
      itr = itr->pNext;
      return *this;
    }

    inline ListIterator operator--(int) {
      if (itr == nullptr) {
        throw std::invalid_argument("attempt to dereference a null pointer");
      }
      ListIterator ptr = *this;
      itr = itr->pPrev;
      return ptr;
    }

    inline ListIterator operator--() {
      if (itr == nullptr) {
        throw std::invalid_argument("attempt to dereference a null pointer");
      }
      itr = itr->pPrev;
      return *this;
    }

    inline bool operator==(const ListIterator &other) {
      return itr == other.itr;
    }
    inline bool operator!=(const ListIterator &other) {
      return itr != other.itr;
    }
  };
  using iterator = typename list<T>::ListIterator;

  //  CLASS CONST ITERATOR
  class ListConstIterator {
   public:
    list::iterator citr;

    ListConstIterator() {}
    explicit ListConstIterator(const list<T> &other) : citr(other) {}
    explicit ListConstIterator(const ListIterator &other) {
      citr.itr = other.itr;
    }
    ~ListConstIterator() {}

    inline T &operator*() { return *citr; }
    inline ListConstIterator operator++() { return (ListConstIterator)++citr; }
    inline ListConstIterator operator++(int) {
      return (ListConstIterator)citr++;
    }
    inline ListConstIterator operator--() { return (ListConstIterator)--citr; }
    inline ListConstIterator operator--(int) {
      return (ListConstIterator)citr--;
    }
    inline bool operator==(const ListConstIterator &other) {
      return citr == other.citr;
    }
    inline bool operator!=(const ListConstIterator &other) {
      return citr != other.citr;
    }
  };
  using const_iterator = typename list<T>::ListConstIterator;

  list();
  explicit list(size_t n);
  explicit list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  list &operator=(list &&l);

  inline const_reference front();
  inline const_reference back();

  inline iterator begin();
  inline iterator end();
  inline const_iterator cbegin();
  inline const_iterator cend();

  inline bool empty();
  inline size_type size() const;
  size_type max_size();

  inline void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  inline void merge(list &other);
  void splice(const_iterator pos, list &other);
  inline void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args);
  template <class... Args>
  void emplace_back(Args &&...args);
  template <class... Args>
  void emplace_front(Args &&...args);

 private:
  size_t size_;
  Node *head_;
  iterator last_elem();
  inline const_iterator clast_elem();
};

template <typename T>
list<T>::list() : size_(0), head_(nullptr) {}

template <typename T>
list<T>::list(size_t n) : size_(0), head_(nullptr) {
  while (n != size_) {
    push_back(value_type());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) : list() {
  for (const auto &element : items) {
    push_back(element);
  }
}

template <typename T>
list<T>::list(const list &l) : list() {
  if (l.size_) {
    list<T>::iterator tmp(l);
    while (tmp.itr->pNext != nullptr) {
      push_back(*tmp);
      ++tmp;
    }
    push_back(*tmp);
  }
}

template <typename T>
list<T>::list(list &&l) : size_(l.size_), head_(l.head_) {
  l.head_ = nullptr;
  l.size_ = 0;
}

template <typename T>
list<T>::~list() {
  clear();
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  clear();
  head_ = l.head_;
  size_ = l.size_;
  l.head_ = nullptr;
  l.size_ = 0;
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  if (!size_) throw std::out_of_range("Error, size = 0");
  list<T>::iterator tmp(*this);
  return *tmp;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  if (!size_) throw std::out_of_range("Error, size = 0");
  list<T>::iterator tmp(*this);
  while (tmp.itr->pNext != nullptr) ++tmp;
  return *tmp;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(*this);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  iterator tmp = last_elem();
  ++tmp;
  return tmp;
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() {
  return (const_iterator)begin();
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() {
  return (const_iterator)end();
}

template <typename T>
bool list<T>::empty() {
  return head_ == nullptr;
}

template <typename T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node);
}

template <typename T>
void list<T>::clear() {
  while (size_) {
    pop_front();
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(list<T>::iterator pos,
                                           list<T>::const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = begin();
  } else if (pos.itr->pNext == nullptr) {
    push_back(value);
    ++pos;
  } else {
    iterator tmp = begin();
    ++tmp;
    iterator rab = begin();
    while (pos.itr != tmp.itr) {
      ++tmp;
      ++rab;
    }
    --tmp;
    rab.itr->pNext = new Node(value);
    ++rab;
    rab.itr->pNext = pos.itr;
    rab.itr->pPrev = tmp.itr;
    pos.itr->pPrev = tmp.itr->pNext;
    size_++;
    pos = rab;
  }
  return pos;
}

template <typename T>
void list<T>::erase(list<T>::iterator pos) {
  if (pos == begin()) {
    pop_front();
  } else if (pos.itr->pNext == nullptr) {
    pop_back();
  } else {
    iterator tmp = begin();
    ++tmp;
    iterator rab = begin();
    while (pos.itr != tmp.itr) {
      ++tmp;
      ++rab;
    }
    ++tmp;
    rab.itr->pNext = pos.itr->pNext;
    tmp.itr->pPrev = pos.itr->pPrev;
    delete pos.itr;
    size_--;
  }
}

template <typename T>
void list<T>::push_back(list<T>::const_reference value) {
  if (!size_) {
    head_ = new Node(value);
  } else {
    Node *current = head_;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node(value, nullptr, current);
  }
  size_++;
}

template <typename T>
void list<T>::pop_back() {
  if (!size_) return;
  if (size_ == 1) {
    pop_front();
  } else {
    Node *current = head_;
    for (size_t i = 0; i < size_ - 2; i++) {
      current = current->pNext;
    }
    Node *tmp = current->pNext;
    current->pNext = nullptr;
    delete tmp;
    size_--;
  }
}

template <typename T>
void list<T>::push_front(list<T>::const_reference value) {
  if (!size_) {
    head_ = new Node(value);
  } else {
    Node *current = new Node(value, head_, nullptr);
    head_->pPrev = current;
    head_ = current;
  }
  size_++;
}

template <typename T>
void list<T>::pop_front() {
  if (!size_) return;
  Node *tmp = head_;
  head_ = head_->pNext;
  if (size_ != 1) head_->pPrev = nullptr;
  delete tmp;
  size_--;
}

template <typename T>
void list<T>::swap(list &other) {
  Node *tmp = head_;
  head_ = other.head_;
  other.head_ = tmp;
  size_t tmp_size = size_;
  size_ = other.size_;
  other.size_ = tmp_size;
}

template <typename T>
void list<T>::merge(list &other) {
  const_iterator tmp = cend();
  splice(tmp, other);
  sort();
}

template <typename T>
void list<T>::splice(list<T>::const_iterator pos, list &other) {
  if (other.size_ == 0) {
    return;
  }
  if (pos == cbegin()) {
    Node *temp = head_;
    head_ = other.head_;
    iterator tmp = other.last_elem();
    tmp.itr->pNext = temp;
    temp->pPrev = tmp.itr;
  } else if (pos == cend()) {
    iterator tmp = last_elem();
    tmp.itr->pNext = other.head_;
    other.head_->pPrev = tmp.itr;
  } else {
    const_iterator tmp = cbegin();
    ++tmp;
    const_iterator rab = cbegin();
    while (pos.citr.itr != tmp.citr.itr) {
      ++tmp;
      ++rab;
    }
    rab.citr.itr->pNext = other.head_;
    tmp = other.clast_elem();
    pos.citr.itr->pPrev = tmp.citr.itr;
    tmp.citr.itr->pNext = pos.citr.itr;
    other.head_->pPrev = rab.citr.itr;
  }
  other.head_ = nullptr;
  size_ += other.size_;
  other.size_ = 0;
}

template <typename T>
void list<T>::reverse() {
  list<T> tmp(std::move(*this));
  for (iterator itr = tmp.begin(); itr != tmp.end(); ++itr) {
    push_front(*itr);
  }
}

template <typename T>
void list<T>::unique() {
  iterator one = begin();
  iterator two = begin();
  ++two;
  while (two.itr->pNext != nullptr) {
    if (*one == *two) {
      iterator tmp = two;
      ++two;
      erase(tmp);
    } else {
      ++one;
      ++two;
    }
  }
  if (*one == *two) {
    erase(two);
  }
}

template <typename T>
void list<T>::sort() {
  if (size_ > 1) {
    iterator one = begin();
    iterator two = begin();
    for (size_type i = 0; i < size_; ++i, ++one) {
      two = begin();
      size_type k = 0;
      while (k < i) {
        ++k;
        ++two;
      }
      for (size_type j = i; j < size_; ++j, ++two) {
        if (*one > *two) {
          auto tmp = *two;
          *two = *one;
          *one = tmp;
        }
      }
    }
  }
}

template <typename T>
template <class... Args>
typename list<T>::iterator list<T>::emplace(list<T>::const_iterator pos,
                                            Args &&...args) {
  iterator res = pos.citr;
  for (auto &element : {args...}) {
    res = insert(res, element);
    ++res;
  }
  --res;
  return res;
}

template <typename T>
template <class... Args>
void list<T>::emplace_back(Args &&...args) {
  for (auto &element : {args...}) {
    push_back(element);
  }
}

template <typename T>
template <class... Args>
void list<T>::emplace_front(Args &&...args) {
  for (auto &element : {args...}) {
    push_front(element);
  }
}

template <typename T>
typename list<T>::iterator list<T>::last_elem() {
  iterator tmp(*this);
  if (tmp.itr != nullptr) {
    while (tmp.itr->pNext != nullptr) {
      ++tmp;
    }
  }
  return tmp;
}

template <typename T>
typename list<T>::const_iterator list<T>::clast_elem() {
  return (const_iterator)last_elem();
}

}  // namespace s21

#endif  // SRC_S21_LIST_HPP_
