TEST(map_erase, test1) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> mape{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> expected{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char>::iterator map_iterator = mape.begin();
    std::map<int, char>::iterator expected_iterator = expected.begin();
    for (size_t i = 0; i < y; i++) {
      ++map_iterator;
      ++expected_iterator;
    }
    mape.erase(map_iterator);
    expected.erase(expected_iterator);
    s21::map<int, char>::iterator map_iterator_2 = mape.begin();
    std::map<int, char>::iterator expected_iterator_2 = expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_erase, test2) {
  s21::map<int, char> mape{{2, 'b'}};
  std::map<int, char> expected{{2, 'b'}};

  s21::map<int, char>::iterator map_iterator = mape.begin();
  std::map<int, char>::iterator expected_iterator = expected.begin();
  mape.erase(map_iterator);
  expected.erase(expected_iterator);
  ASSERT_EQ(mape.size(), expected.size());
}

TEST(map_erase, test3) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> mape{
        {1, 'a'},  {2, 'b'},  {4, 'd'},  {6, 'f'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> expected{
        {1, 'a'},  {2, 'b'},  {4, 'd'},  {6, 'f'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char>::iterator map_iterator = mape.begin();
    std::map<int, char>::iterator expected_iterator = expected.begin();
    for (size_t i = 0; i < y; i++) {
      ++map_iterator;
      ++expected_iterator;
    }
    mape.erase(map_iterator);
    expected.erase(expected_iterator);
    s21::map<int, char>::iterator map_iterator_2 = mape.begin();
    std::map<int, char>::iterator expected_iterator_2 = expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_erase, test4) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> mape{
        {24, 'x'}, {17, 'q'}, {1, 'a'},  {2, 'b'},  {4, 'd'},  {6, 'f'},
        {3, 'c'},  {5, 'e'},  {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'},
        {9, 'k'},  {10, 'k'}, {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'},
        {15, 'o'}, {14, 'n'}, {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}};
    std::map<int, char> expected{
        {24, 'x'}, {17, 'q'}, {1, 'a'},  {2, 'b'},  {4, 'd'},  {6, 'f'},
        {3, 'c'},  {5, 'e'},  {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'},
        {9, 'k'},  {10, 'k'}, {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'},
        {15, 'o'}, {14, 'n'}, {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}};

    s21::map<int, char>::iterator map_iterator = mape.begin();
    std::map<int, char>::iterator expected_iterator = expected.begin();
    for (size_t i = 0; i < y; i++) {
      ++map_iterator;
      ++expected_iterator;
    }
    mape.erase(map_iterator);
    expected.erase(expected_iterator);
    s21::map<int, char>::iterator map_iterator_2 = mape.begin();
    std::map<int, char>::iterator expected_iterator_2 = expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_begin_and_construct_and_insert, test1) {
  s21::map<int, char> tmp_map;
  tmp_map.insert(std::pair<int, char>(13, 'm'));
  tmp_map.insert(std::pair<int, char>(6, 'f'));
  tmp_map.insert(std::pair<int, char>(3, 'c'));
  tmp_map.insert(std::pair<int, char>(2, 'b'));
  tmp_map.insert(std::pair<int, char>(1, 'a'));
  s21::map<int, char>::iterator it_map = tmp_map.begin();
  std::map<int, char> tmp_expected;
  tmp_expected.insert(std::pair<int, char>(13, 'm'));
  tmp_expected.insert(std::pair<int, char>(6, 'f'));
  tmp_expected.insert(std::pair<int, char>(3, 'c'));
  tmp_expected.insert(std::pair<int, char>(2, 'b'));
  tmp_expected.insert(std::pair<int, char>(1, 'a'));
  std::map<int, char>::iterator it_expected = tmp_expected.begin();
  ASSERT_EQ((*it_expected).first, (*it_map).first);
}

TEST(map_begin_end_initializer_list, test1) {
  s21::map<int, char> tmp_map{
      {13, 'm'}, {6, 'f'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  s21::map<int, char>::iterator it_map = tmp_map.begin();
  std::map<int, char> tmp_expected{
      {13, 'm'}, {6, 'f'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  std::map<int, char>::iterator it_expected = tmp_expected.begin();
  ASSERT_EQ((*it_expected).first, (*it_map).first);
}
TEST(map_end_and_construct_and_insert, test1) {
  s21::map<int, char> tmp_map;
  tmp_map.insert(std::pair<int, char>(13, 'm'));
  tmp_map.insert(std::pair<int, char>(6, 'f'));
  tmp_map.insert(std::pair<int, char>(3, 'c'));
  tmp_map.insert(std::pair<int, char>(2, 'b'));
  tmp_map.insert(std::pair<int, char>(1, 'a'));
  s21::map<int, char>::iterator it_map = tmp_map.end();
  std::map<int, char> tmp_expected;
  tmp_expected.insert(std::pair<int, char>(13, 'm'));
  tmp_expected.insert(std::pair<int, char>(6, 'f'));
  tmp_expected.insert(std::pair<int, char>(3, 'c'));
  tmp_expected.insert(std::pair<int, char>(2, 'b'));
  tmp_expected.insert(std::pair<int, char>(1, 'a'));
  std::map<int, char>::iterator it_expected = tmp_expected.end();
  --it_map;
  --it_expected;
  ASSERT_EQ((*it_expected).first, (*it_map).first);
}

TEST(map_end_or_initializer_list, test1) {
  s21::map<int, char> tmp_map{
      {13, 'm'}, {6, 'f'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  s21::map<int, char>::iterator it_map = tmp_map.end();
  std::map<int, char> tmp_expected{
      {13, 'm'}, {6, 'f'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  std::map<int, char>::iterator it_expected = tmp_expected.end();
  --it_map;
  --it_expected;
  ASSERT_EQ((*it_expected).first, (*it_map).first);
}

TEST(map_square_brackets, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> tmp_expected{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  for (size_t i = 1; i < 6; i++) {
    ASSERT_EQ(tmp_map[i], tmp_expected[i]);
  }
}

TEST(map_size, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> tmp_expected{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  ASSERT_EQ(tmp_map.size(), tmp_expected.size());
}

TEST(map_max_size, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  ASSERT_EQ(tmp_map.max_size(), 230584300921369395UL);
}

TEST(map_rav, test1) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> tmp_map{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> tmp_expected{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char> tmp2_map = tmp_map;
    std::map<int, char> tmp2_expected = tmp_expected;

    s21::map<int, char>::iterator map_iterator_2 = tmp2_map.begin();
    std::map<int, char>::iterator expected_iterator_2 = tmp2_expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_rav, test2) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> tmp_map{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> tmp_expected{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char> tmp2_map = tmp_map;
    std::map<int, char> tmp2_expected = tmp_expected;

    s21::map<int, char>::iterator map_iterator_2 = tmp2_map.end();
    std::map<int, char>::iterator expected_iterator_2 = tmp2_expected.end();
    --map_iterator_2;
    --expected_iterator_2;
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      --map_iterator_2;
      --expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_copy, test1) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> tmp_map{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> tmp_expected{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char> tmp2_map(tmp_map);
    std::map<int, char> tmp2_expected(tmp_expected);

    s21::map<int, char>::iterator map_iterator_2 = tmp2_map.begin();
    std::map<int, char>::iterator expected_iterator_2 = tmp2_expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_copy, test2) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<char, std::string> tmp_map{
        {'a', "Hello"}, {'b', "World"}, {'c', "!!!"}};
    std::map<char, std::string> tmp_expected{
        {'a', "Hello"}, {'b', "World"}, {'c', "!!!"}};

    s21::map<char, std::string> tmp2_map(tmp_map);
    std::map<char, std::string> tmp2_expected(tmp_expected);

    s21::map<char, std::string>::iterator map_iterator_2 = tmp2_map.begin();
    std::map<char, std::string>::iterator expected_iterator_2 =
        tmp2_expected.begin();
    for (size_t i = 0; i < 2; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_assignment, test1) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<char, std::string> tmp_map{
        {'a', "Hello"}, {'b', "World"}, {'c', "!!!"}};
    std::map<char, std::string> tmp_expected{
        {'a', "Hello"}, {'b', "World"}, {'c', "!!!"}};

    s21::map<char, std::string> tmp2_map(std::move(tmp_map));
    std::map<char, std::string> tmp2_expected(std::move(tmp_expected));

    s21::map<char, std::string>::iterator map_iterator_2 = tmp2_map.begin();
    std::map<char, std::string>::iterator expected_iterator_2 =
        tmp2_expected.begin();
    for (size_t i = 0; i < 2; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_assignment, test2) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> tmp_map{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> tmp_expected{
        {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
        {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    s21::map<int, char> tmp2_map(std::move(tmp_map));
    std::map<int, char> tmp2_expected(std::move(tmp_expected));

    s21::map<int, char>::iterator map_iterator_2 = tmp2_map.begin();
    std::map<int, char>::iterator expected_iterator_2 = tmp2_expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_at, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'},
                              {4, 'd'}, {5, 'e'}, {0, 'e'}};
  std::map<int, char> tmp_expected{{1, 'a'}, {2, 'b'}, {3, 'c'},
                                   {4, 'd'}, {5, 'e'}, {0, 'e'}};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(tmp_map.at(i), tmp_expected.at(i));
  }
}

TEST(map_at, test2) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  ASSERT_THROW(tmp_map.at(6), std::out_of_range);
}

TEST(map_empty, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> tmp_expected{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  ASSERT_EQ(tmp_map.empty(), tmp_expected.empty());
}

TEST(map_empty, test2) {
  s21::map<int, char> tmp_map;
  std::map<int, char> tmp_expected;
  ASSERT_EQ(tmp_map.empty(), tmp_expected.empty());
}

TEST(map_swap, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> tmp_expected{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  s21::map<int, char> tmp2_map{
      {5, 'e'}, {4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  std::map<int, char> tmp2_expected{
      {5, 'e'}, {4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
  tmp_map.swap(tmp2_map);
  tmp_expected.swap(tmp2_expected);
  for (size_t i = 1; i < 6; i++) {
    ASSERT_EQ(tmp_map[i], tmp_expected[i]);
  }
  for (size_t i = 5; i > 0; i--) {
    ASSERT_EQ(tmp2_map[i], tmp2_expected[i]);
  }
}

TEST(map_merge, test1) {
  for (size_t y = 0; y < 22; y++) {
    s21::map<int, char> tmp_map{{2, 'b'},  {4, 'd'},  {6, 'f'}, {1, 'a'},
                                {3, 'c'},  {5, 'e'},  {8, 'h'}, {7, 'g'},
                                {10, 'j'}, {11, 'k'}, {9, 'k'}, {10, 'k'}};
    std::map<int, char> tmp_expected{{2, 'b'},  {4, 'd'},  {6, 'f'}, {1, 'a'},
                                     {3, 'c'},  {5, 'e'},  {8, 'h'}, {7, 'g'},
                                     {10, 'j'}, {11, 'k'}, {9, 'k'}, {10, 'k'}};

    s21::map<int, char> tmp2_map{{5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'},
                                 {15, 'o'}, {14, 'n'}, {22, 'v'}, {21, 'u'},
                                 {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
    std::map<int, char> tmp2_expected{
        {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
        {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

    tmp_map.merge(tmp2_map);
    tmp_expected.merge(tmp2_expected);
    s21::map<int, char>::iterator map_iterator_2 = tmp_map.begin();
    std::map<int, char>::iterator expected_iterator_2 = tmp_expected.begin();
    for (size_t i = 0; i < 20; i++) {
      ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
      ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
      ++map_iterator_2;
      ++expected_iterator_2;
    }
    ASSERT_EQ((*expected_iterator_2).first, (*map_iterator_2).first);
    ASSERT_EQ((*expected_iterator_2).second, (*map_iterator_2).second);
  }
}

TEST(map_contains, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'},
                              {4, 'd'}, {5, 'e'}, {0, 'e'}};
  ASSERT_EQ(tmp_map.contains(3), 1);
  ASSERT_EQ(tmp_map.contains(0), 1);
}

TEST(map_contains, test2) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  ASSERT_EQ(tmp_map.contains(10), 0);
}

TEST(map_insert, test3) {
  s21::map<int, char> mape{
      {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
      {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
      {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
      {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};
  std::map<int, char> expected{
      {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
      {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
      {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
      {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

  std::pair<s21::map<int, char>::iterator, bool> map_iterator =
      mape.insert(std::pair<int, char>(6, 'f'));
  std::pair<std::map<int, char>::iterator, bool> expected_iterator =
      expected.insert(std::pair<int, char>(6, 'f'));

  ASSERT_EQ((*expected_iterator.first).first, (*map_iterator.first).first);
  ASSERT_EQ((*expected_iterator.first).second, (*map_iterator.first).second);
}

TEST(map_insert, test4) {
  s21::map<int, char> mape{
      {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
      {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
      {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
      {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

  std::pair<s21::map<int, char>::iterator, bool> map_iterator =
      mape.insert_or_assign(6, 'z');

  ASSERT_EQ(6, (*map_iterator.first).first);
  ASSERT_EQ('z', (*map_iterator.first).second);
}
TEST(map_insert, test5) {
  s21::map<int, char> mape{
      {2, 'b'},  {4, 'd'},  {6, 'f'},  {1, 'a'},  {3, 'c'},  {5, 'e'},
      {8, 'h'},  {7, 'g'},  {10, 'j'}, {11, 'k'}, {9, 'k'},  {10, 'k'},
      {5, 'k'},  {12, 'l'}, {19, 's'}, {16, 'p'}, {15, 'o'}, {14, 'n'},
      {22, 'v'}, {21, 'u'}, {20, 't'}, {23, 'w'}, {24, 'x'}, {17, 'q'}};

  std::pair<s21::map<int, char>::iterator, bool> map_iterator =
      mape.insert_or_assign(50, 'z');

  ASSERT_EQ(50, (*map_iterator.first).first);
  ASSERT_EQ('z', (*map_iterator.first).second);
}

TEST(map_emplace, test1) {
  s21::map<int, char> tmp_map;
  std::pair<int, char> one(1, 'a');
  std::pair<int, char> two(2, 'b');
  std::pair<int, char> three(3, 'c');
  tmp_map.emplace(one, two, three);

  ASSERT_EQ(tmp_map[1], 'a');
  ASSERT_EQ(tmp_map[2], 'b');
  ASSERT_EQ(tmp_map[3], 'c');
}

TEST(map_operator_equals, test1) {
  s21::map<int, char> tmp_map{{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  s21::map<int, char> tmp_map2;
  tmp_map2 = std::move(tmp_map);
  std::map<int, char> tmp_expected{
      {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> tmp_expected2;
  tmp_expected2 = std::move(tmp_expected);
  for (size_t i = 1; i < 5; i++) {
    ASSERT_EQ(tmp_map2[i], tmp_expected2[i]);
  }
}
