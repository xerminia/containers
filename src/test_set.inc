TEST(test_s21_set, set_begin) {
  const std::initializer_list<int> l = {6, 4, 2, 4, 1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l);
  s21::set<int> b2;
  EXPECT_EQ(b.begin().get_value(), 1);
  auto tmp_node = b.begin().ptr_node;
  EXPECT_EQ((b.begin()--).ptr_node, tmp_node);
  EXPECT_EQ(b2.begin(), b2.end());
}

TEST(test_s21_set, set_end) {
  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l2);
  EXPECT_EQ(b.end().ptr_node->left_, nullptr);
  EXPECT_EQ(b.end().ptr_node->right_, nullptr);
  EXPECT_NE(b.end().ptr_node->parent_, nullptr);

  auto it = b.end();
  EXPECT_EQ((--it).get_value(), 6);
  EXPECT_EQ((it--).get_value(), 6);
  EXPECT_EQ(it.get_value(), 5);
}

TEST(test_s21_set, set_empty_clear) {
  const std::initializer_list<int> l = {1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l);
  s21::set<int> b2;
  EXPECT_EQ(b.empty(), false);
  EXPECT_EQ(b2.empty(), true);
  b.clear();
  EXPECT_EQ(b.empty(), true);
}

TEST(test_s21_set, set_size) {
  const std::initializer_list<int> l = {1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l);
  s21::set<int> b2;
  EXPECT_EQ(b.size(), l.size() - 1UL);
  EXPECT_EQ(b2.size(), 0UL);
}

TEST(test_s21_set, set_max_size) {
  s21::set<int> b2;
  EXPECT_EQ(b2.max_size(), 128102389400760775UL);
}

TEST(test_s21_set, set_insert) {
  const std::initializer_list<int> l = {1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l);
  auto ok = b.insert(7);
  auto err = b.insert(7);
  EXPECT_EQ(ok.second, true);
  EXPECT_EQ(err.second, false);
  EXPECT_EQ(b.size(), 7UL);
  auto it = b.begin();

  for (unsigned long i = 1; i < 8; ++i) {
    EXPECT_EQ((it++).get_key(), (int)i);
  }
}

TEST(test_s21_set, set_erase) {
  const std::initializer_list<int> l1 = {
      51, 67, 76, 88, 2,  96, 92, 85, 21, 36, 78, 91, 39,  32, 77, 6,  46,
      94, 64, 33, 55, 97, 52, 56, 48, 26, 31, 43, 69, 59,  27, 99, 4,  84,
      41, 10, 16, 68, 40, 28, 11, 22, 73, 86, 63, 47, 83,  89, 37, 66, 82,
      19, 1,  35, 44, 24, 20, 38, 62, 72, 93, 57, 74, 98,  54, 30, 50, 8,
      80, 95, 58, 49, 17, 90, 3,  79, 23, 34, 45, 7,  71,  15, 25, 29, 9,
      12, 65, 13, 5,  75, 42, 60, 81, 14, 70, 61, 87, 100, 18, 53};

  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6};
  const std::initializer_list<int> l3 = {1, 1, 1, 1, 1};
  const std::vector<int> to_del = {70, 10, 20,  1,  51, 55, 84, 6,
                                   18, 51, 100, 67, 76, 88, 2};

  s21::set<int> b(l2);
  s21::set<int> b2(l1);
  s21::set<int> b3(l3);

  EXPECT_EQ(b.size(), 6UL);
  EXPECT_EQ(b2.size(), 100UL);
  EXPECT_EQ(b3.size(), 1UL);

  b3.erase(b3.find(1));
  b3.erase(b3.find(1));
  b3.erase(b3.find(1));
  EXPECT_EQ(b3.size(), 0UL);

  b.erase(--b.end());
  b.erase(b.find(4));
  b.erase(b.find(1));
  b.erase(b.find(3));
  b.erase(b.find(5));

  EXPECT_EQ(b.size(), 1UL);

  for (auto it = b.begin(); it != b.end(); ++it) {
    EXPECT_EQ(b.find(2).get_key(), 2);
  }

  for (auto &it : to_del) {
    b2.erase(b2.find(it));
  }

  EXPECT_EQ(b2.size(), 86UL);

  for (int i = 1; i <= 100; i++) {
    if (std::find(to_del.begin(), to_del.end(), i) != to_del.end()) {
      auto it1 = b2.find(i);
      auto it2 = b2.end();
      EXPECT_EQ(it1, it2);
    } else {
      EXPECT_EQ(b2.find(i).get_key(), i);
    }
  }
}

TEST(test_s21_set, set_swap) {
  const std::initializer_list<int> l1 = {
      51, 67, 76, 88, 2,  96, 92, 85, 21, 36, 78, 91, 39,  32, 77, 6,  46,
      94, 64, 33, 55, 97, 52, 56, 48, 26, 31, 43, 69, 59,  27, 99, 4,  84,
      41, 10, 16, 68, 40, 28, 11, 22, 73, 86, 63, 47, 83,  89, 37, 66, 82,
      19, 1,  35, 44, 24, 20, 38, 62, 72, 93, 57, 74, 98,  54, 30, 50, 8,
      80, 95, 58, 49, 17, 90, 3,  79, 23, 34, 45, 7,  71,  15, 25, 29, 9,
      12, 65, 13, 5,  75, 42, 60, 81, 14, 70, 61, 87, 100, 18, 53};

  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6};

  s21::set<int> b1(l1);
  s21::set<int> b2(l2);
  b1.swap(b2);
  EXPECT_EQ(b1.size(), l2.size());
  EXPECT_EQ(b2.size(), l1.size());

  int i = 1;
  for (auto &it : b2) {
    EXPECT_EQ((it), i++);
  }
  EXPECT_EQ((unsigned long)i, l1.size() + 1);
  i = 1;
  for (auto &it : b1) {
    EXPECT_EQ((it), i++);
  }
  EXPECT_EQ((unsigned long)i, l2.size() + 1);
}

TEST(test_s21_set, set_merge) {
  const std::initializer_list<int> l1 = {
      51, 67, 76, 88, 2,  96, 92, 85, 21, 36, 78, 91, 39,  32, 77, 6,  46,
      94, 64, 33, 55, 97, 52, 56, 48, 26, 31, 43, 69, 59,  27, 99, 4,  84,
      41, 10, 16, 68, 40, 28, 11, 22, 73, 86, 63, 47, 83,  89, 37, 66, 82,
      19, 1,  35, 44, 24, 20, 38, 62, 72, 93, 57, 74, 98,  54, 30, 50, 8,
      80, 95, 58, 49, 17, 90, 3,  79, 23, 34, 45, 7,  71,  15, 25, 29, 9,
      12, 65, 13, 5,  75, 42, 60, 81, 14, 70, 61, 87, 100, 18, 53};

  const std::initializer_list<int> l2 = {101, 102, 103, 104, 105, 106};

  s21::set<int> b1(l1);
  s21::set<int> b2(l2);
  b2.merge(b1);
  EXPECT_EQ(b1.size(), l1.size());
  EXPECT_EQ(b2.size(), l1.size() + l2.size());

  int i = 1;
  for (auto &it : b2) {
    EXPECT_EQ((it), i++);
  }
  EXPECT_EQ((unsigned long)i, l1.size() + l2.size() + 1UL);
}

TEST(test_s21_set, set_find) {
  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6};
  s21::set<int> b(l2);
  std::set<int> b2(l2);

  EXPECT_EQ((*b.find(1)), 1);
  EXPECT_EQ((*b2.find(1)), 1);
  EXPECT_EQ(b.find(6).get_key(), 6);
  EXPECT_EQ(b.find(7), b.end());
}

TEST(test_s21_btree, set_create) {
  const std::initializer_list<int> l1 = {1, 2, 3, 4, 5, 6};

  s21::set<int> b1(l1);
  s21::set<int> b2(b1);
  s21::set<int> b3 = std::move(b2);
  //  check = operator
  b3.clear();
}

TEST(test_s21_set, set_contains) {
  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6, 5};
  s21::set<int> b(l2);

  EXPECT_EQ(b.contains(1), true);
  EXPECT_EQ(b.contains(5), true);
  EXPECT_EQ(b.contains(6), true);
  EXPECT_EQ(b.contains(7), false);
}

TEST(test_s21_set, set_emplace) {
  const std::initializer_list<int> l2 = {1, 2, 3, 4, 5, 6};
  s21::set<int> b(l2);

  b.emplace(1, 2, 3, 4, 5, 6, 7);
  EXPECT_EQ(b.size(), 7UL);
  int i = 1;
  for (auto &it : b) {
    EXPECT_EQ((it), i++);
  }
}
