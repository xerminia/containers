TEST(vector_empty, test1) {
  s21::vector<int> vec;
  std::vector<int> expected;
  ASSERT_EQ(vec.empty(), expected.empty());
}
TEST(vector_empty, test2) {
  s21::vector<double> vec;
  std::vector<double> expected;
  ASSERT_EQ(vec.empty(), expected.empty());
}

TEST(vector_empty, test3) {
  s21::vector<char> vec;
  std::vector<char> expected;
  ASSERT_EQ(vec.empty(), expected.empty());
}

TEST(vector_construct_n, test1) {
  s21::vector<double> vec(2);
  vec[0] = 1.12345;
  vec[1] = 2.12345;
  std::vector<double> expected(2);
  expected[0] = 1.12345;
  expected[1] = 2.12345;
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}

TEST(vector_construct_n, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}

TEST(vector_construct_n, test3) {
  s21::vector<int> vec(2);
  vec[0] = 1;
  vec[1] = 2;
  std::vector<int> expected(2);
  expected[0] = 1;
  expected[1] = 2;
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_construct_n, test4) {
  s21::vector<std::string> vec(2);
  vec[0] = "Hello";
  vec[1] = "World";
  std::vector<std::string> expected(2);
  expected[0] = "Hello";
  expected[1] = "World";
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}

TEST(vector_construct_initializer_list, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};

  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_construct_initializer_list, test2) {
  s21::vector<int> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<int> expected{'v', 'e', 'c', 't', 'o', 'r'};

  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_construct_initializer_list, test3) {
  s21::vector<double> vec{1.2345, 2.12345};
  std::vector<double> expected{1.2345, 2.12345};

  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}

TEST(vector_construct_default, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_construct_default, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_construct_default, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}

TEST(vector_construct_copy, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int> vec_copy(vec);
  std::vector<int> expected{1, 2, 3, 4, 5};
  std::vector<int> expected_copy(expected);
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec_copy[i], expected_copy[i]);
  }
}
TEST(vector_construct_copy, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char> vec_copy(vec);
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected_copy(expected);
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec_copy[i], expected_copy[i]);
  }
}
TEST(vector_construct_copy, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double> vec_copy(vec);
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected_copy(expected);
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec_copy[i], expected_copy[i]);
  }
}
TEST(vector_construct_assignment, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int> vec_assignment(std::move(vec));
  std::vector<int> expected{1, 2, 3, 4, 5};
  std::vector<int> expected_assignment(std::move(expected));
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_construct_assignment, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char> vec_assignment(std::move(vec));
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected_assignment(std::move(expected));
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_construct_assignment, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double> vec_assignment(std::move(vec));
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected_assignment(std::move(expected));
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_operator_equals, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int> vec_assignment(std::move(vec));
  std::vector<int> expected{1, 2, 3, 4, 5};
  std::vector<int> expected_assignment(std::move(expected));
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_operator_equals, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char> vec_assignment = vec;
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected_assignment = expected;
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_operator_equals, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double> vec_assignment = vec;
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected_assignment = expected;
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}

TEST(vector_operator_equals, test4) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int> vec_assignment;
  vec_assignment = std::move(vec);
  std::vector<int> expected{1, 2, 3, 4, 5};
  std::vector<int> expected_assignment;
  expected_assignment = std::move(expected);
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec_assignment[i], expected_assignment[i]);
  }
}
TEST(vector_at, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec.at(i), expected.at(i));
  }
}
TEST(vector_at, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec.at(i), expected.at(i));
  }
}
TEST(vector_at, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec.at(i), expected.at(i));
  }
}
TEST(vector_square_brackets, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_square_brackets, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_square_brackets, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  for (size_t i = 0; i < 2; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
}
TEST(vector_front, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  ASSERT_EQ(vec.front(), expected.front());
}
TEST(vector_front, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  ASSERT_EQ(vec.front(), expected.front());
}
TEST(vector_front, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  ASSERT_EQ(vec.front(), expected.front());
}

TEST(vector_back, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  ASSERT_EQ(vec.back(), expected.back());
}
TEST(vector_back, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  ASSERT_EQ(vec.back(), expected.back());
}
TEST(vector_back, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  ASSERT_EQ(vec.back(), expected.back());
}
TEST(vector_begin, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int>::iterator vec_iterator = vec.begin();
  ASSERT_EQ(*vec_iterator, 1);
}
TEST(vector_begin, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char>::iterator vec_iterator = vec.begin();
  ASSERT_EQ(*vec_iterator, 'v');
}
TEST(vector_begin, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double>::iterator vec_iterator = vec.begin();
  ASSERT_EQ(*vec_iterator, 1.12345);
}
TEST(vector_data, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int>::iterator vec_iterator = vec.data();
  ASSERT_EQ(*vec_iterator, 1);
}
TEST(vector_data, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char>::iterator vec_iterator = vec.data();
  ASSERT_EQ(*vec_iterator, 'v');
}
TEST(vector_data, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double>::iterator vec_iterator = vec.data();
  ASSERT_EQ(*vec_iterator, 1.12345);
}
TEST(vector_size, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  ASSERT_EQ(vec.size(), expected.size());
}
TEST(vector_size, test2) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_size, test3) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  ASSERT_EQ(vec.size(), expected.size());
}
TEST(vector_capacity, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  ASSERT_EQ(vec.capacity(), expected.capacity());
}
TEST(vector_capacity, test2) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  ASSERT_EQ(vec.capacity(), expected.capacity());
}

TEST(vector_capacity, test3) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  ASSERT_EQ(vec.capacity(), expected.capacity());
}

TEST(vector_reserve, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  vec.reserve(2);
  std::vector<int> expected{1, 2, 3, 4, 5};
  expected.reserve(2);
  ASSERT_EQ(vec.capacity(), expected.capacity());
}
TEST(vector_reserve, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  vec.reserve(3);
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  expected.reserve(3);
  ASSERT_EQ(vec.capacity(), expected.capacity());
}
TEST(vector_reserve, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  vec.reserve(4);
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  expected.reserve(4);
  ASSERT_EQ(vec.capacity(), expected.capacity());
}
TEST(vector_max_size, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(vec.max_size(), 2305843009213693951UL);
}

TEST(vector_shrink_to_fit, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  vec.shrink_to_fit();
  std::vector<int> expected{1, 2, 3, 4, 5};
  expected.shrink_to_fit();
  ASSERT_EQ(vec.capacity(), expected.capacity());
}

TEST(vector_shrink_to_fit, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  vec.shrink_to_fit();
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  expected.shrink_to_fit();
  ASSERT_EQ(vec.capacity(), expected.capacity());
}

TEST(vector_shrink_to_fit, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  vec.shrink_to_fit();
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  expected.shrink_to_fit();
  ASSERT_EQ(vec.capacity(), expected.capacity());
}

TEST(vector_clear, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  vec.clear();
  size_t x = 0;
  ASSERT_EQ(vec.size(), x);
  ASSERT_EQ(vec.capacity(), x);
}

TEST(vector_clear, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  vec.clear();
  size_t x = 0;
  ASSERT_EQ(vec.size(), x);
  ASSERT_EQ(vec.capacity(), x);
}

TEST(vector_clear, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  vec.clear();
  size_t x = 0;
  ASSERT_EQ(vec.size(), x);
  ASSERT_EQ(vec.capacity(), x);
}

TEST(vector_insert, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  s21::vector<int>::iterator vec_iterator = vec.begin();
  std::vector<int>::iterator expected_iterator = expected.begin();
  ++vec_iterator;
  ++vec_iterator;
  ++expected_iterator;
  ++expected_iterator;
  vec.insert(vec_iterator, 9);
  expected.insert(expected_iterator, 9);
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_insert, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char>::iterator vec_iterator = vec.begin();
  std::vector<char>::iterator expected_iterator = expected.begin();
  ++vec_iterator;
  ++vec_iterator;
  ++expected_iterator;
  ++expected_iterator;
  vec.insert(vec_iterator, 'x');
  expected.insert(expected_iterator, 'x');
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_insert, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double>::iterator vec_iterator = vec.begin();
  std::vector<double>::iterator expected_iterator = expected.begin();
  ++vec_iterator;
  ++vec_iterator;
  ++expected_iterator;
  ++expected_iterator;
  vec.insert(vec_iterator, 9.99999);
  expected.insert(expected_iterator, 9.99999);
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_push_back, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_push_back, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_push_back, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  for (size_t i = 0; i < 5; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_pop_back, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  std::vector<int> expected{1, 2, 3, 4, 5};
  vec.pop_back();
  vec.pop_back();
  expected.pop_back();
  expected.pop_back();
  for (size_t i = 0; i < 3; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_pop_back, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  vec.pop_back();
  vec.pop_back();
  expected.pop_back();
  expected.pop_back();
  for (size_t i = 0; i < 4; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_pop_back, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  vec.pop_back();
  vec.pop_back();
  expected.pop_back();
  expected.pop_back();
  for (size_t i = 0; i < 3; i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_vector_erase, test1) {
  s21::vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  std::vector<int> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(4);
  expected.push_back(5);
  s21::vector<int>::iterator vec_iterator = vec.begin();
  std::vector<int>::iterator expected_iterator = expected.begin();
  ++vec_iterator;
  ++expected_iterator;
  vec.erase(vec_iterator);
  expected.erase(expected_iterator);
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}

TEST(vector_erase, test2) {
  s21::vector<double> vec;
  vec.push_back(1.12345);
  vec.push_back(2.23456);
  vec.push_back(3.34567);
  vec.push_back(4.45678);
  vec.push_back(5.56789);
  std::vector<double> expected;
  expected.push_back(1.12345);
  expected.push_back(2.23456);
  expected.push_back(3.34567);
  expected.push_back(4.45678);
  expected.push_back(5.56789);
  s21::vector<double>::iterator vec_iterator = vec.begin();
  std::vector<double>::iterator expected_iterator = expected.begin();
  ++vec_iterator;
  vec.erase(vec_iterator);
  ++expected_iterator;
  expected.erase(expected_iterator);
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
}
TEST(vector_swap, test1) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int> vec2;
  vec2.push_back(5);
  vec2.push_back(6);
  vec2.push_back(7);
  vec2.push_back(8);
  vec2.push_back(9);
  std::vector<int> expected{1, 2, 3, 4, 5};
  std::vector<int> expected2;
  expected2.push_back(5);
  expected2.push_back(6);
  expected2.push_back(7);
  expected2.push_back(8);
  expected2.push_back(9);

  vec.swap(vec2);
  expected.swap(expected2);

  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec2[i], expected2[i]);
  }
  ASSERT_EQ(vec2.size(), expected2.size());
}
TEST(vector_swap, test2) {
  s21::vector<char> vec{'v', 'e', 'c', 't', 'o', 'r'};
  s21::vector<char> vec2{'r', 'o', 't', 'c', 'e', 'v'};
  std::vector<char> expected{'v', 'e', 'c', 't', 'o', 'r'};
  std::vector<char> expected2{'r', 'o', 't', 'c', 'e', 'v'};
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec2[i], expected2[i]);
  }
  ASSERT_EQ(vec2.size(), expected2.size());
}
TEST(vector_swap, test3) {
  s21::vector<double> vec{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  s21::vector<double> vec2{5.54321, 6.65432, 7.76543, 8.87654, 9.98765};
  std::vector<double> expected{1.12345, 2.23456, 3.34567, 4.45678, 5.56789};
  std::vector<double> expected2{5.54321, 6.65432, 7.76543, 8.87654, 9.98765};
  for (size_t i = 0; i < vec.size(); i++) {
    ASSERT_EQ(vec[i], expected[i]);
  }
  ASSERT_EQ(vec.size(), expected.size());
  for (size_t i = 0; i < vec2.size(); i++) {
    ASSERT_EQ(vec2[i], expected2[i]);
  }
  ASSERT_EQ(vec2.size(), expected2.size());
}
TEST(vector_at, test4) {
  s21::vector<int> vec{1, 2, 3, 4, 5};
  s21::vector<int>::iterator vec_iterator = vec.end();
  ++vec_iterator;
  ASSERT_THROW(vec.at(-1), std::out_of_range);
}
