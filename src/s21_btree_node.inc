/*
 *
 *    BTREE_NODE CLASS WITH REALIZATION
 *
 */

class btree_node {
 public:
  Key _key;
  Val _value;

  btree_node *left_{nullptr};
  btree_node *right_{nullptr};
  btree_node *parent_{nullptr};

  btree_node() {}
  btree_node(const Key &key, const Val &value) : _key(key), _value(value) {}

  void operator=(const btree_node &one) {
    _key = one._key;
    _value = one._value;
    left_ = one.left_;
    right_ = one.right_;
    parent_ = one.parent_;
  }
};
