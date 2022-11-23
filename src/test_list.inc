TEST(list, test_list1) {
  s21::list<int> lst;
  std::list<int> expected;
  ASSERT_EQ(lst.empty(), expected.empty());
}

TEST(list, test_list2) {
  s21::list<double> lst;
  std::list<double> expected;
  ASSERT_EQ(lst.empty(), expected.empty());
}

TEST(list, test_list3) {
  s21::list<char> lst;
  std::list<char> expected;
  ASSERT_EQ(lst.empty(), expected.empty());
}

TEST(list, test_list4) {
  s21::list<int> lst(5);
  ASSERT_EQ(lst.size(), 5UL);
}

TEST(list, test_list5) {
  s21::list<char> lst(5);
  ASSERT_EQ(lst.size(), 5UL);
}

TEST(list, test_list6) {
  s21::list<int> lst{1, 2, 3};
  ASSERT_FALSE(lst.empty());
  ASSERT_EQ(lst.front(), 1);
  lst.clear();
  ASSERT_TRUE(lst.empty());
}

TEST(list, test_list7) {
  s21::list<char> lst{'a', 'b', 'c'};
  ASSERT_FALSE(lst.empty());
  ASSERT_EQ(lst.front(), 'a');
  lst.clear();
  ASSERT_TRUE(lst.empty());
}

TEST(list, test_list8) {
  s21::list<std::string> lst{"Hello", "world!"};
  ASSERT_EQ(lst.front(), "Hello");
  ASSERT_EQ(lst.back(), "world!");
}

TEST(list, test_list9) {
  s21::list<int> lst;
  std::list<int> expected;
  ASSERT_EQ(lst.empty(), expected.empty());
}

TEST(list, test_list10) {
  s21::list<int> lst;
  std::list<int> expected;
  for (int i = 1; i < 4; i++) {
    lst.push_back(i);
    expected.push_back(i);
  }
  ASSERT_EQ(lst.front(), expected.front());
  ASSERT_EQ(lst.back(), expected.back());
}

TEST(list, test_list11) {
  s21::list<int> lst;
  std::list<int> expected;
  for (int i = 1; i < 4; i++) {
    lst.push_back(i);
    expected.push_back(i);
  }
  lst.sort();
  expected.sort();
  lst.pop_back();
  expected.pop_back();
  s21::list<int>::iterator itr = lst.begin();
  std::list<int>::iterator expected_itr = expected.begin();
  for (size_t i = 0; i < lst.size(); i++) {
    ASSERT_EQ(*itr, *expected_itr);
    ++itr;
    ++expected_itr;
  }
  while (lst.size() && expected.size()) {
    lst.pop_back();
    expected.pop_back();
  }
  ASSERT_EQ(lst.empty(), expected.empty());
}

TEST(list, test_list12) {
  s21::list<int> lst;
  std::list<int> expected;

  for (int i = 0; i < 100; i++) {
    lst.push_front(i);
    expected.push_front(i);
  }

  lst.sort();
  expected.sort();

  s21::list<int>::iterator itr = lst.begin();
  std::list<int>::iterator expected_itr = expected.begin();
  for (size_t i = 0; i < lst.size(); i++) {
    ASSERT_EQ(*itr, *expected_itr);
    ++itr;
    ++expected_itr;
  }
}

TEST(list, test_list13) {
  s21::list<int> lst;
  std::list<int> expected;
  for (int i = 1; i < 5; i++) {
    lst.push_front(i);
    expected.push_front(i);
  }

  s21::list<int>::iterator itr = lst.begin();
  std::list<int>::iterator expected_itr = expected.begin();
  for (int i = 0; i < 2; i++) {
    ++itr;
    ++expected_itr;
  }
  lst.erase(itr);
  expected.erase(expected_itr);

  itr = lst.begin();
  expected_itr = expected.begin();
  lst.erase(itr);
  expected.erase(expected_itr);

  itr = lst.begin();
  expected_itr = expected.begin();
  ++itr;
  ++expected_itr;
  lst.erase(itr);
  expected.erase(expected_itr);

  itr = lst.begin();
  expected_itr = expected.begin();

  ASSERT_EQ(lst.size(), expected.size());

  for (size_t i = 0; i < lst.size(); i++, ++itr, ++expected_itr) {
    ASSERT_EQ(*itr, *expected_itr);
  }
}

TEST(list, test_list14) {
  s21::list<int> lst(5);
  s21::list<int>::const_iterator itr = lst.cbegin();
  ++itr;
  ASSERT_EQ(*itr, 0);
  itr = lst.cbegin();
  ASSERT_EQ(*itr, 0);
}

TEST(list, test_list15) {
  s21::list<int>::const_iterator itr;
  ASSERT_THROW(++itr, std::invalid_argument);
}

TEST(list, test_list16) {
  s21::list<int> lst;
  s21::list<int>::const_iterator itr = lst.cbegin();
  ASSERT_THROW(*itr, std::invalid_argument);
}

TEST(list, test_list17) {
  s21::list<int> lst(5);
  s21::list<int> lst2(lst);
  ASSERT_EQ(lst.size(), lst2.size());
}

TEST(list, test_list18) {
  s21::list<int> lst(5);
  s21::list<int>::iterator itr = lst.begin();
  itr = lst.insert(itr, 5);
  ASSERT_EQ(*itr, 5);
  for (int i = 0; i < 5; i++, ++itr) {
  }
  itr = lst.insert(itr, 44);
  ASSERT_EQ(*itr, 44);
  itr = lst.begin();
  ++itr;
  ++itr;
  ++itr;
  itr = lst.insert(itr, 99);
  ASSERT_EQ(*itr, 99);
  int tmp[8] = {5, 0, 0, 99, 0, 0, 0, 44};
  itr = lst.begin();
  for (int i = 0; itr != lst.end(); i++, ++itr) {
    ASSERT_EQ(*itr, tmp[i]);
  }
}

TEST(list, test_list19) {
  s21::list<int> lst(5);
  s21::list<int> lst2(4);
  lst.swap(lst2);
  size_t x = 5;
  ASSERT_EQ(lst2.size(), x);
  x = 4;
  ASSERT_EQ(lst.size(), x);
}

TEST(list, test_list20) {
  s21::list<int> lst;
  s21::list<int> lst2;
  for (int i = 0; i > -100; i--) {
    lst.push_back(i);
    lst2.push_back(i);
  }
  s21::list<int>::const_iterator c_itr = lst.cbegin();
  lst.splice(c_itr, lst2);
  size_t x = 200;
  ASSERT_EQ(lst.size(), x);
}

TEST(list, test_list21) {
  s21::list<int> lst;
  s21::list<int> lst2;
  for (int i = 0; i > -100; i--) {
    lst.push_back(i);
    lst2.push_back(i);
  }
  s21::list<int>::const_iterator c_itr = lst.cbegin();
  for (int i = 0; i < 50; i++, ++c_itr) {
  }
  lst.splice(c_itr, lst2);
  size_t x = 200;
  ASSERT_EQ(lst.size(), x);
}

TEST(list, test_list22) {
  s21::list<int> lst;
  s21::list<int> lst2;
  for (int i = 0; i > -5; i--) {
    lst.push_back(i);
    lst2.push_back(i);
  }
  s21::list<int>::const_iterator c_itr = lst.cend();
  lst.splice(c_itr, lst2);
  size_t x = 10;
  ASSERT_EQ(lst.size(), x);
}

TEST(list, test_list23) {
  s21::list<int> lst;
  s21::list<int> lst2;
  for (int i = 0; i > -5; i--) {
    lst.push_back(i);
  }
  s21::list<int>::const_iterator c_itr = lst.cend();
  lst.splice(c_itr, lst2);
  size_t x = 5;
  ASSERT_EQ(lst.size(), x);
}

TEST(list, test_list24) {
  s21::list<int> lst;
  s21::list<int> lst2;
  for (int i = 0; i > -25; i--) {
    lst.push_back(i);
    lst2.push_back(i * -1);
  }
  lst.merge(lst2);
  size_t x = 50;
  ASSERT_EQ(lst.size(), x);
  s21::list<int>::iterator itr = lst.begin();
  for (int i = -24; i < 25; i++, ++itr) {
    ASSERT_EQ(*itr, i);
    if (i == 0) {
      ++itr;
      ASSERT_EQ(*itr, i);
    }
  }
}

TEST(list, test_list25) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  lst.reverse();
  s21::list<int>::iterator itr = lst.begin();
  size_t x = 5;
  ASSERT_EQ(lst.size(), x);
  for (int i = 5; i > 0; i--, ++itr) {
    ASSERT_EQ(*itr, i);
  }
}

TEST(list, test_list26) {
  s21::list<int> lst{1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5};
  lst.unique();
  s21::list<int>::iterator itr = lst.begin();
  ASSERT_EQ(lst.size(), 5UL);
  for (int i = 1; i < 6; i++, ++itr) {
    ASSERT_EQ(*itr, i);
  }
}

TEST(list, test_list27) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  s21::list<int> expected{1, 2, 3, 4, 5};
  ASSERT_EQ(lst.max_size(), expected.max_size());
}

TEST(list, test_list28) {
  s21::list<int>::iterator itr;
  ASSERT_THROW(++itr, std::invalid_argument);
}

TEST(list, test_list29) {
  s21::list<int> lst(5);
  s21::list<int> lst2;
  lst2 = std::move(lst);
  ASSERT_EQ(lst.size(), 0UL);
  ASSERT_EQ(lst2.size(), 5UL);
}

TEST(list, test_list30) {
  s21::list<int> lst{1, 2, 3, 4, 5};
  s21::list<int>::iterator itr = lst.begin();
  s21::list<int>::const_iterator citr = lst.cbegin();
  for (int i = 1; i < 5; i++, ++itr, ++citr) {
    ASSERT_EQ(*itr, i);
    ASSERT_EQ(*citr, i);
  }
  for (int i = 5; i > 0; i--, --itr, --citr) {
    ASSERT_EQ(*itr, i);
    ASSERT_EQ(*citr, i);
  }
  ASSERT_THROW(--itr, std::invalid_argument);
}

TEST(list, test_list31) {
  s21::list<int> lst{1, 2, 5, 6};
  s21::list<int>::const_iterator itr = lst.cbegin();
  ++itr;
  ++itr;
  lst.emplace(itr, 3, 4);
  int i = 1;

  for (s21::list<int>::iterator it = lst.begin(); it != lst.end(); ++it, i++) {
    ASSERT_EQ(*it, i);
  }
}

TEST(list, test_list32) {
  s21::list<int> lst{1, 2, 3, 4};
  lst.emplace_back(5, 6);
  int i = 1;

  for (s21::list<int>::iterator it = lst.begin(); it != lst.end(); ++it, i++) {
    ASSERT_EQ(*it, i);
  }
}

TEST(list, test_list33) {
  s21::list<int> lst{3, 4, 5, 6};
  lst.emplace_front(2, 1);
  int i = 1;

  for (s21::list<int>::iterator it = lst.begin(); it != lst.end(); ++it, i++) {
    ASSERT_EQ(*it, i);
  }
}

TEST(list, test_list34) {
  s21::list<int> lst;
  ASSERT_THROW(lst.back(), std::out_of_range);
  ASSERT_THROW(lst.front(), std::out_of_range);
}
