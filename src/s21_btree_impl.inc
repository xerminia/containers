
template <typename Key, typename Val>
typename btree<Key, Val>::size_type btree<Key, Val>::size() {
  return size_;
}

template <typename Key, typename Val>
typename btree<Key, Val>::size_type btree<Key, Val>::max_size() {
  try {
    std::numeric_limits<long> _k;
    return _k.max() /
           (sizeof(btree<Key, Val>) + sizeof(btree<Key, Val>::btree_node));
  } catch (...) {
  }

  return LONG_MAX / 6;
}

template <typename Key, typename Val>
bool btree<Key, Val>::empty() {
  return size() == 0;
}

template <typename Key, typename Val>
void btree<Key, Val>::clear() {
  clear_node(header_);
  header_ = nullptr;

  if (afterend_node_) {
    afterend_node_ = nullptr;
  }
  first_node_ = nullptr;
  end_node_ = nullptr;
  size_ = 0;
}

template <typename Key, typename Val>
void btree<Key, Val>::clear_node(btree_node *node) {
  if (node == nullptr) return;
  if (node->left_ == nullptr && node->right_ == nullptr) {
    delete node;
  } else {
    clear_node(node->left_);
    node->left_ = nullptr;
    clear_node(node->right_);
    node->right_ = nullptr;
    clear_node(node);
  }
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::insert(
    const key_type &key, const value_type &value) {
  ++size_;
  btree_node *ret = nullptr;
  if (header_ == nullptr) {
    header_ = new btree_node(key, value);

    first_node_ = header_;
    end_node_ = header_;

    afterend_node_ = new btree_node();

    ret = header_;
  } else {
    ret = insert_to_subtree(key, value, header_);
  }

  afterend_node_->parent_ = end_node_;
  end_node_->right_ = afterend_node_;

  return iterator(ret);
}

template <typename Key, typename Val>
typename btree<Key, Val>::btree_node *btree<Key, Val>::insert_to_subtree(
    const key_type &key, const value_type &value, btree_node *element) {
  btree_node *element_to_store;

  if (key < element->_key) {
    if (element->left_) {
      return insert_to_subtree(key, value, element->left_);
    } else {
      element->left_ = new btree_node(key, value);
      element_to_store = element->left_;
      element_to_store->parent_ = element;

      if (first_node_ == element) {
        first_node_ = element_to_store;
      }
    }
  } else {
    if (element->right_ && element->right_ != afterend_node_) {
      return insert_to_subtree(key, value, element->right_);
    } else {
      element->right_ = new btree_node(key, value);
      element_to_store = element->right_;
      element_to_store->parent_ = element;
      if (end_node_ == element) {
        end_node_ = element_to_store;
      }
    }
  }
  //  *** Store first and end element
  return element_to_store;
}

template <typename Key, typename Val>
btree<Key, Val>::btree(std::initializer_list<Key> const &keys,
                       std::initializer_list<Val> const &values,
                       bool only_unique_values) {
  if (keys.size() != values.size())
    throw std::length_error(
        "Sizes of keys and values arrays must be identical.");

  auto k = keys.begin();
  auto v = values.begin();

  for (std::initializer_list<int>::size_type i = 0; i < keys.size(); i++) {
    if (only_unique_values && contains(k[i]))
      continue;
    else
      insert(k[i], v[i]);
  }
}

template <typename Key, typename Val>
btree<Key, Val>::btree(const btree &s) {
  for (auto it = s.cbegin(); it != s.cend(); ++it) {
    insert(it.get_key(), it.get_value());
  }
}

template <typename Key, typename Val>
btree<Key, Val>::btree(btree &&s) {
  size_ = s.size_;
  header_ = s.header_;
  first_node_ = s.first_node_;
  end_node_ = s.end_node_;
  afterend_node_ = s.afterend_node_;

  s.size_ = 0;
  s.header_ = nullptr;
  s.first_node_ = nullptr;
  s.end_node_ = nullptr;
  s.afterend_node_ = nullptr;
}

template <typename Key, typename Val>
bool btree<Key, Val>::contains(const Key &key) {
  return contains_node_with_key(header_, key);
}

template <typename Key, typename Val>
bool btree<Key, Val>::contains_node_with_key(btree_node *node, const Key &key) {
  if (node == nullptr || node == afterend_node_) return false;
  if (node->_key == key) {
    return true;
  } else {  // *** We try search faster, not element-by-element
    if (node->left_ && node->_key > key) {
      return contains_node_with_key(node->left_, key);
    } else if (node->right_ && node->_key < key) {
      return contains_node_with_key(node->right_, key);
    } else {
      return false;
    }
  }
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::find(const Key &key) {
  return find_node_with_key(header_, key);
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::find_node_with_key(
    btree_node *node, const Key &key) {
  if (node == nullptr || node == afterend_node_) {
    return end();
  }

  if (node->_key == key) {
    return iterator(node);
  }

  // *** We try search faster, not element-by-element
  if (node->left_ && node->_key > key) {
    return find_node_with_key(node->left_, key);
  }

  if (node->right_ && node->_key < key) {
    return find_node_with_key(node->right_, key);
  }

  return end();
}

template <typename Key, typename Val>
void btree<Key, Val>::erase(btree<Key, Val>::iterator pos) {
  // смысл удаления - взять следующий елемент (++) и поставить на это место
  if (pos == end()) return;

  --size_;

  btree<Key, Val>::iterator next = pos;
  ++next;
  auto cparent_ = pos.ptr_node->parent_;
  auto cleft_ = pos.ptr_node->left_;
  auto cright_ = pos.ptr_node->right_;

  if (next == end()) {
    end_node_ = pos.ptr_node->parent_;
  }

  // последний елемент c не пустым родителем, у него нету правого и левого
  if (cparent_ && cleft_ == nullptr &&
      (cright_ == nullptr || cright_ == afterend_node_)) {
    if (cparent_->right_ == pos.ptr_node) {
      if (cright_ == afterend_node_) {
        cparent_->right_ = afterend_node_;
        afterend_node_->parent_ = cparent_;
      } else {
        cparent_->right_ = nullptr;
      }
    } else {
      cparent_->left_ = nullptr;
    }
    delete pos.ptr_node;

  } else if (cleft_ == nullptr) {  // подвешивается его правое поддерево
    if (cright_) {
      cright_->parent_ = cparent_;
      if (end_node_ == cright_) {
        end_node_ = pos.ptr_node;
        end_node_->right_ = afterend_node_;
        afterend_node_->parent_ = end_node_;
      }
      *(pos.ptr_node) = *(cright_);

      if (cright_->right_) cright_->right_->parent_ = pos.ptr_node;

      if (cright_->left_) cright_->left_->parent_ = pos.ptr_node;

      cright_->left_ = nullptr;
      cright_->right_ = nullptr;
      cright_->parent_ = nullptr;
      delete cright_;
    }
  } else if (pos.ptr_node->right_ ==
             nullptr) {  // подвешивается его левое поддерево
    cleft_->parent_ = cparent_;
    *(pos.ptr_node) = *(cleft_);
    delete cleft_;
  } else {
    pos.ptr_node->_key = next.get_key();
    pos.ptr_node->_value = next.get_value();
  }

  if (size_ == 0) {
    clear();
  }
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::begin() {
  return iterator(first_node_);
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::cbegin() const {
  return iterator(first_node_);
}

// *** Iterator to the element following the last element.
template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::end() {
  return iterator(afterend_node_);
}

template <typename Key, typename Val>
typename btree<Key, Val>::iterator btree<Key, Val>::cend() const {
  return iterator(afterend_node_);
}

template <typename Key, typename Val>
void btree<Key, Val>::operator=(const btree<Key, Val> &other) {
  clear();
  auto tmp(other);
  (*this) = std::move(tmp);
}

template <typename Key, typename Val>
void btree<Key, Val>::operator=(btree<Key, Val> &&other) {
  size_ = other.size_;
  header_ = other.header_;
  first_node_ = other.first_node_;
  end_node_ = other.end_node_;
  afterend_node_ = other.afterend_node_;
  other.size_ = 0;
  other.header_ = nullptr;
  other.first_node_ = nullptr;
  other.end_node_ = nullptr;
  other.afterend_node_ = nullptr;
}

template <typename Key, typename Val>
void btree<Key, Val>::swap(btree<Key, Val> &other) {
  auto thissize_ = size_;
  auto thisheader_ = header_;
  auto thisfirst_node_ = first_node_;
  auto thisend_node_ = end_node_;
  auto thisafterend_node_ = afterend_node_;

  (*this) = std::move(other);

  other.size_ = thissize_;
  other.header_ = thisheader_;
  other.first_node_ = thisfirst_node_;
  other.end_node_ = thisend_node_;
  other.afterend_node_ = thisafterend_node_;
}

template <typename Key, typename Val>
void btree<Key, Val>::merge(btree<Key, Val> &other) {
  for (auto it = other.begin(); it != other.end(); ++it) {
    insert(it.get_key(), it.get_value());
  }
}
