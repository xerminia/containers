#ifndef SRC_S21_BTREE_HPP_
#define SRC_S21_BTREE_HPP_

#include <climits>
#include <initializer_list>

namespace s21 {

enum btree_color { red, black };

template <class Key, class Val>
class btree {
  //  *** public usings
 public:
  using key_type = Key;
  using value_type = Val;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  // *** private members and classes
 private:
  size_type size_{0};

//  *** define class btree_node;
#include "s21_btree_node.inc"

  btree_node *header_{nullptr};
  btree_node *first_node_{nullptr};
  btree_node *end_node_{nullptr};
  btree_node *afterend_node_{nullptr};

  // *** public members and classes
 public:
#include "s21_btree_iterator.inc"

  //  *** Public methods
 public:
  btree() {}

  btree(std::initializer_list<key_type> const &keys,
        std::initializer_list<value_type> const &values,
        bool only_unique_values);

  btree(std::initializer_list<key_type> const &keys,
        std::initializer_list<value_type> const &values)
      : btree(keys, values, false) {}

  //  *** The rules of 5
  btree(const btree &s);
  btree(btree &&s);
  ~btree() { clear(); }
  void operator=(const btree<Key, Val> &s);
  void operator=(btree<Key, Val> &&s);

  size_type get_size() { return size_; }
  //  *** Iterators
  iterator begin();
  iterator end();
  iterator cbegin() const;
  iterator cend() const;

  //  *** Capacity
  bool empty();
  size_type size();
  size_type max_size();

  //  *** Modifiers
  void clear();

  iterator insert(const key_type &key, const value_type &value);

  void erase(iterator pos);
  void swap(btree &other);
  void merge(btree &other);

  //  *** Lookup
  iterator find(const Key &key);
  bool contains(const Key &key);

  // *** Private methods
 private:
  void clear_node(btree_node *node);
  btree_node *insert_to_subtree(const key_type &key, const value_type &value,
                                btree_node *element);
  bool contains_node_with_key(btree_node *node, const Key &key);
  iterator find_node_with_key(btree_node *node, const Key &key);
};

#include "s21_btree_impl.inc"

}  //  namespace s21

#endif  // SRC_S21_BTREE_HPP_
