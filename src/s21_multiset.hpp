#ifndef SRC_S21_MULTISET_HPP_
#define SRC_S21_MULTISET_HPP_

#include <initializer_list>

#include "s21_set.hpp"

namespace s21 {

template <class Key>
class multiset : public set<Key> {
#include "s21_set_using.inc"
  using set<Key>::set;

 public:
  explicit multiset(std::initializer_list<key_type> const &keys)
      : set<Key>::set(keys, false) {}
  std::pair<iterator, bool> insert(const key_type &key) override {
    return std::pair<iterator, bool>(this->tree.insert(key, key), true);
  }
};

}  //  namespace s21

#endif  // SRC_S21_MULTISET_HPP_
