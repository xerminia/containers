/**
 *
 * ITERATOR CLASS WITH REALIZATION
 *
 */

class iterator {
 private:
  using _node = btree_node;

  //  *** Get - minimum node for tmp_node. If this tmp_node is the root node,
  //  then function return
  //      minimum node of tree.
  //      If this tmp_node is not the root node, then function return previos
  //      (--) node.
  _node *get_minimum_node(_node *tmp_node) {
    if (tmp_node->left_) return get_minimum_node(tmp_node->left_);
    return tmp_node;
  }

  //  *** Get - maximum node for tmp_node. If this tmp_node is the root node,
  //  then function return
  //      maximum node of tree.
  //      If this tmp_node is not the root node, then function return next (++)
  //      node.
  _node *get_maximum_node(_node *tmp_node) {
    if (tmp_node->right_) return get_maximum_node(tmp_node->right_);
    return tmp_node;
  }

 public:
  iterator() {}

  btree_node *ptr_node{nullptr};

  explicit iterator(_node *ptr) { ptr_node = ptr; }

  key_type get_key() { return ptr_node->_key; }

  value_type get_value() { return ptr_node->_value; }

  value_type &operator*() { return ptr_node->_value; }

  //  *** Если у узла есть правое поддерево, то следующий за ним элемент
  //      будет минимальным элементом в этом поддереве.
  //      Если у него нет правого поддерева, то нужно следовать вверх,
  //      пока не встретим узел, который является левым дочерним узлом своего
  //      родителя.
  iterator &operator++() {
    if (ptr_node->right_) {
      ptr_node = get_minimum_node(ptr_node->right_);
    } else {
      auto tmp_ptr = ptr_node;
      auto breaked = false;
      while (ptr_node && ptr_node->parent_ && !breaked) {
        if (ptr_node->parent_->left_ == ptr_node) {
          breaked = true;
        }
        ptr_node = ptr_node->parent_;
      }
      if (!breaked) ptr_node = tmp_ptr;
    }
    return (*this);
  }

  iterator operator++(Key) {
    iterator temp = *this;
    ++(*this);
    return temp;
  }

  //  *** Если у узла есть левое поддерево, то предыдущий ему элемент
  //      будет максимальным элементом в этом поддереве.
  //      Если у него нет левого поддерева, то нужно следовать вверх, пока
  //      не встретим узел, который является правым дочерним узлом своего
  //      родителя.
  iterator &operator--() {
    if (ptr_node->left_) {
      ptr_node = get_maximum_node(ptr_node->left_);
    } else {
      auto tmp_ptr = ptr_node;
      auto breaked = false;
      while (ptr_node && ptr_node->parent_ && !breaked) {
        if (ptr_node->parent_->right_ == ptr_node) {
          breaked = true;
        }
        ptr_node = ptr_node->parent_;
      }
      if (!breaked) ptr_node = tmp_ptr;
    }
    return (*this);
  }

  iterator operator--(Key) {
    iterator temp = iterator(*this);
    --(*this);
    return temp;
  }

  friend bool operator==(const _node &one, const _node &two) {
    return one._key == two._key;
  }

  friend bool operator==(const iterator &one, const iterator &two) {
    return one.ptr_node == two.ptr_node;
  }

  friend bool operator!=(const iterator &one, const iterator &two) {
    return one.ptr_node != two.ptr_node;
  }
};
