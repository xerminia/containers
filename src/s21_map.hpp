#ifndef SRC_S21_MAP_HPP_
#define SRC_S21_MAP_HPP_

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  class MapNode {
   public:
    Key key_;
    T value_;
    MapNode *left_;
    MapNode *right_;
    MapNode *parent_;

    MapNode()
        : key_(), value_(), left_(nullptr), right_(nullptr), parent_(nullptr) {}
    explicit MapNode(Key const &key = Key(), T const &value = T(),
                     MapNode *left = nullptr, MapNode *right = nullptr,
                     MapNode *parent = nullptr)
        : key_(key),
          value_(value),
          left_(left),
          right_(right),
          parent_(parent) {}
    ~MapNode() {
      left_ = nullptr;
      right_ = nullptr;
      parent_ = nullptr;
    }
  };
  using Node = typename map<Key, T>::MapNode;

  class MapIterator {
   public:
    Node *first_;
    Node *end_;
    Node *itr_;
    Node *itrhead_;
    MapIterator() : first_(), end_(), itr_(), itrhead_() {}
    explicit MapIterator(const map<Key, T> &one) {
      if (one.head_->left_) {
        first_ = one.head_->left_;
        while (first_->left_) {
          first_ = first_->left_;
        }
      } else {
        first_ = one.head_;
      }
      if (one.head_->right_) {
        end_ = one.head_->right_;
        while (end_->right_) {
          end_ = end_->right_;
        }
      } else {
        end_ = one.head_;
      }
      itr_ = first_;
      itrhead_ = one.head_;
    }

    MapIterator operator++() {
      if (itr_ == end_) {
        itr_ = end_->right_;
        return *this;
      }
      Node *tmp = itr_;
      while (!tmp->right_) {
        tmp = tmp->parent_;
        if (itr_->key_ < tmp->key_) {
          itr_ = tmp;
          return *this;
        }
      }
      while (tmp->key_ < itr_->key_) {
        tmp = tmp->parent_;
        if (itr_->key_ < tmp->key_) {
          itr_ = tmp;
          return *this;
        }
      }
      tmp = tmp->right_;
      while (tmp->left_) {
        tmp = tmp->left_;
      }
      itr_ = tmp;
      return *this;
    }

    MapIterator operator--() {
      if (itr_ == end_->right_) {
        itr_ = end_;
        return *this;
      }
      Node *tmp = itr_;
      while (!tmp->left_) {
        tmp = tmp->parent_;
        if (itr_->key_ > tmp->key_) {
          itr_ = tmp;
          return *this;
        }
      }
      while (tmp->key_ > itr_->key_) {
        tmp = tmp->parent_;
        if (itr_->key_ > tmp->key_) {
          itr_ = tmp;
          return *this;
        }
      }
      tmp = tmp->left_;
      while (tmp->right_) {
        tmp = tmp->right_;
      }
      itr_ = tmp;
      return *this;
    }

    bool operator!=(const MapIterator &it) { return itr_ != it.itr_; }
    bool operator==(const MapIterator &it) { return itr_ == it.itr_; }

    std::pair<Key, T> operator*() const {
      return std::make_pair(itr_->key_, itr_->value_);
    }

    ~MapIterator() {
      first_ = nullptr;
      end_ = nullptr;
      itr_ = nullptr;
    }
  };
  using iterator = typename map<Key, T>::MapIterator;

  map();
  explicit map(std::initializer_list<value_type> const &items);
  map(const map &m);
  map(map &&m);
  ~map();
  map operator=(map &&m);
  T &at(const Key &key);
  T &operator[](const Key &key);

  iterator begin();
  iterator end();
  bool empty();
  size_type size();
  size_type max_size();
  void clear();
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);
  void erase(iterator pos);
  void swap(map &other);
  void merge(map &other);
  bool contains(const Key &key);

  template <class... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args);

 private:
  Node *head_;
  size_t size_;
  void copy(Node *cp);
};

// Конструктор по умолчанию, создает пустой map
template <typename Key, typename T>
map<Key, T>::map() : head_(nullptr), size_(0) {}

// Конструктор списка инициализаторов, создает карту, инициализированную с
// помощью std::initializer_list
template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const &items) : map() {
  for (const auto &element : items) {
    insert(element);
  }
}

// Конструктор копирования
template <typename Key, typename T>
map<Key, T>::map(const map &m) : map() {
  copy(m.head_);
}

// Конструктор перемещения
template <typename Key, typename T>
map<Key, T>::map(map &&m) : map() {
  swap(m);
}

// Деструктор
template <typename Key, typename T>
map<Key, T>::~map() {
  clear();
}

// Перегрузка оператора присваивания для движущегося объекта
template <typename Key, typename T>
map<Key, T> map<Key, T>::operator=(map &&m) {
  clear();
  head_ = m.head_;
  size_ = m.size_;
  m.head_ = nullptr;
  m.size_ = 0;
  return *this;
}

// Доступ к указанному элементу с проверкой границ
template <typename Key, typename T>
T &map<Key, T>::at(const Key &key) {
  Node *tmp = head_;
  while (key != tmp->key_) {
    if (tmp->right_ && key > tmp->key_) {
      tmp = tmp->right_;
    } else if (tmp->left_ && key < tmp->key_) {
      tmp = tmp->left_;
    } else {
      throw std::out_of_range("The key does not exist, out of the map!");
    }
  }
  return tmp->value_;
}

// Получить доступ или вставить указанный элемент
template <typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) {
  Node *tmp = head_;
  while (key != tmp->key_) {
    if (key > tmp->key_) {
      tmp = tmp->right_;
    } else {
      tmp = tmp->left_;
    }
  }
  return tmp->value_;
}

// Возвращает итератор в начало
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::begin() {
  iterator tmp(*this);
  return tmp;
}

// Возвращает итератор в конец
template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::end() {
  iterator tmp(*this);
  tmp.itr_ = tmp.end_;
  ++tmp;
  return tmp;
}

// Проверяет, пуст ли контейнер
template <typename Key, typename T>
bool map<Key, T>::empty() {
  if (!size_) return true;
  return false;
}

// Возвращает количество элементов
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::size() {
  return size_;
}

// Возвращает максимально возможное количество элементов
template <typename Key, typename T>
typename map<Key, T>::size_type map<Key, T>::max_size() {
  return std::numeric_limits<intmax_t>::max() / (10 * sizeof(Key));
}

// Очищает содержимое
template <typename Key, typename T>
void map<Key, T>::clear() {
  while (head_) {
    if (head_->right_) {
      Node *del = head_->right_;
      while (del->right_ || del->left_) {
        if (del->right_) {
          del = del->right_;
        } else {
          del = del->left_;
        }
      }
      Node *tmp = del->parent_;
      if (tmp->right_ == del) {
        tmp->right_ = nullptr;
      } else {
        tmp->left_ = nullptr;
      }
      delete del;
    } else if (head_->left_) {
      Node *del = head_->left_;
      while (del->right_ || del->left_) {
        if (del->right_) {
          del = del->right_;
        } else {
          del = del->left_;
        }
      }
      Node *tmp = del->parent_;
      if (tmp->right_ == del) {
        tmp->right_ = nullptr;
      } else {
        tmp->left_ = nullptr;
      }
      delete del;
    } else {
      delete head_;
      head_ = nullptr;
    }
  }
  size_ = 0;
}

// Вставляет узел и возвращает итератор туда, где элемент находится в
// контейнере, и логическое значение, обозначающее, имела ли место вставка
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const map<Key, T>::value_type &value) {
  return insert(value.first, value.second);
}

// вставляет значение по ключу и возвращает итератор туда, где элемент
// находится в контейнере, и логическое значение, обозначающее, имела ли
// место вставка
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  if (!head_) {
    head_ = new Node(key, obj);
    size_++;
    return std::pair(begin(), true);
  }

  Node *tmp = head_;

  iterator result = begin();

  while (1) {
    if (tmp->key_ == key) {
      result.itr_ = tmp;
      break;
    }

    if (tmp->key_ > key) {
      if (tmp->left_) {
        tmp = tmp->left_;
      } else {
        tmp->left_ = new Node(key, obj);
        Node *tmp2 = tmp->left_;
        tmp2->parent_ = tmp;
        result.itr_ = tmp2;
        size_++;
        return std::pair(result, true);
      }
    } else {
      if (tmp->right_) {
        tmp = tmp->right_;
      } else {
        tmp->right_ = new Node(key, obj);
        Node *tmp2 = tmp->right_;
        tmp2->parent_ = tmp;
        result.itr_ = tmp2;
        size_++;
        return std::pair(result, true);
      }
    }
  }

  return std::pair(result, false);
}

// Вставляет элемент или присваивает значение текущему элементу,
// если ключ уже существует
template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  if (contains(key)) {
    for (iterator tmp = begin(); tmp != end(); ++tmp) {
      if (tmp.itr_->key_ == key) {
        tmp.itr_->value_ = obj;
        return std::pair(tmp, false);
      }
    }
  }
  return insert(key, obj);
}

// Cтирает элемент в позиции
template <typename Key, typename T>
void map<Key, T>::erase(typename map<Key, T>::iterator pos) {
  if (size_ == 1) {
    delete pos.itr_;
    head_ = nullptr;
    size_--;
    return;
  }

  Node *tmp = pos.itr_;

  if (tmp->left_ && !tmp->right_ && tmp->parent_) {
    tmp = tmp->parent_;
    if (tmp->left_ && tmp->left_ == pos.itr_)
      tmp->left_ = pos.itr_->left_;
    else
      tmp->right_ = pos.itr_->left_;
    tmp = pos.itr_->left_;
    tmp->parent_ = pos.itr_->parent_;

  } else if (tmp->right_ && !tmp->left_ && tmp->parent_) {
    tmp = tmp->parent_;
    if (tmp->left_ && tmp->left_ == pos.itr_)
      tmp->left_ = pos.itr_->right_;
    else
      tmp->right_ = pos.itr_->right_;
    tmp = pos.itr_->right_;
    tmp->parent_ = pos.itr_->parent_;

  } else if (tmp->right_ && tmp->left_) {
    tmp = tmp->right_;
    while (tmp->left_) tmp = tmp->left_;
    pos.itr_->key_ = tmp->key_;
    pos.itr_->value_ = tmp->value_;
    pos.itr_ = pos.itr_->right_;
    while (pos.itr_->left_) pos.itr_ = pos.itr_->left_;
    erase(pos);
    return;

  } else if (!tmp->left_ && !tmp->right_) {
    tmp = tmp->parent_;
    if (tmp->right_ == pos.itr_)
      tmp->right_ = nullptr;
    else
      tmp->left_ = nullptr;

  } else if (!tmp->left_ && !tmp->parent_) {
    head_ = pos.itr_->right_;
    head_->parent_ = nullptr;
  } else if (!tmp->right_ && !tmp->parent_) {
    head_ = pos.itr_->left_;
    head_->parent_ = nullptr;
  }
  size_--;
  delete pos.itr_;
  pos.itr_ = nullptr;
}

// Меняет содержимое
template <typename Key, typename T>
void map<Key, T>::swap(map &other) {
  auto size = size_;
  auto head = head_;
  size_ = other.size_;
  head_ = other.head_;
  other.size_ = size;
  other.head_ = head;
}

// Cоединяет узлы из другого контейнера
template <typename Key, typename T>
void map<Key, T>::merge(map &other) {
  size_t tmp_other_size = other.size_;
  iterator itr_other;
  std::pair<iterator, bool> ok;
  int flag = 0;

  while (tmp_other_size) {
    itr_other = other.begin();
    for (int i = 0; i < flag; i++, ++itr_other) {
    }
    ok = insert(itr_other.itr_->key_, itr_other.itr_->value_);
    if (!ok.second) {
      flag++;
    } else {
      other.erase(itr_other);
    }
    tmp_other_size--;
  }
}

// Проверяет, есть ли элемент с ключом, эквивалентным ключу в контейнере
template <typename Key, typename T>
bool map<Key, T>::contains(const Key &key) {
  Node *tmp = head_;
  while (tmp->key_ != key) {
    if (tmp->left_ && tmp->key_ > key)
      tmp = tmp->left_;
    else if (tmp->right_ && tmp->key_ < key)
      tmp = tmp->right_;
    else
      return false;
  }
  return true;
}

template <typename Key, typename T>
template <class... Args>
std::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::emplace(Args &&...args) {
  std::vector<value_type> tmp = {args...};
  std::vector<std::pair<typename map<Key, T>::iterator, bool>> res(tmp.size());
  for (size_t i = 0; i < tmp.size(); i++) {
    res[i] = insert(tmp[i]);
  }
  return res;
}

template <typename Key, typename T>
void map<Key, T>::copy(typename map<Key, T>::Node *cp) {
  if (cp) {
    insert(cp->key_, cp->value_);
    copy(cp->left_);
    copy(cp->right_);
  }
}

}  // namespace s21

#endif  // SRC_S21_MAP_HPP_
