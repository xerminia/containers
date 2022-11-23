TEST(test_constructor_copy_queue, constructor_copy_1) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2(queue1);
  std::queue<int> queue3({1, 2, 3});
  std::queue<int> queue4(queue3);
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
}

///

TEST(test_constructor_move_queue, constructor_move_1) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2(std::move(queue1));
  std::queue<int> queue3({1, 2, 3});
  std::queue<int> queue4(std::move(queue3));
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
}

///

TEST(test_empty_queue, empty_1) {
  s21::queue<int> queue;
  std::queue<int> queue_expected;
  ASSERT_EQ(queue.empty(), queue_expected.empty());
}

TEST(test_empty_queue, empty_2) {
  s21::queue<double> queue;
  std::queue<double> queue_expected;
  ASSERT_EQ(queue.empty(), queue_expected.empty());
}

TEST(test_empty_queue, empty_3) {
  s21::queue<char> queue;
  std::queue<char> queue_expected;
  ASSERT_EQ(queue.empty(), queue_expected.empty());
}

///

TEST(test_size_queue, size_1) {
  s21::queue<int> queue{1, 2, 3};
  size_t x = 3;
  ASSERT_EQ(queue.size(), x);
}

TEST(test_size_queue, size_2) {
  s21::queue<char> queue{1};
  size_t x = 1;
  ASSERT_EQ(queue.size(), x);
}

///

TEST(test_push_queue, top_push_1) {
  s21::queue<int> queue1;
  std::queue<int> queue2;
  queue1.push(1);
  queue2.push(1);
  ASSERT_EQ(queue1.front(), queue2.front());
  queue1.push(100);
  queue2.push(100);
  ASSERT_EQ(queue1.front(), queue2.front());
}

TEST(test_push_queue, top_push_2) {
  s21::queue<char> queue1{'l', 'e', 'x'};
  std::queue<char> queue2({'l', 'e', 'x'});
  queue1.push('a');
  queue2.push('a');
  ASSERT_EQ(queue1.front(), queue2.front());
  queue1.push('b');
  queue2.push('b');
  ASSERT_EQ(queue1.front(), queue2.front());
}

///

TEST(test_assignment_operator_overload_moving_object_queue,
     assignment_operator_overload_moving_object) {
  s21::queue<int> queue1{1, 2, 3};
  s21::queue<int> queue2;
  queue2 = std::move(queue1);
  std::queue<int> queue3({1, 2, 3});
  std::queue<int> queue4;
  queue4 = std::move(queue3);
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  ASSERT_EQ(queue1.empty(), queue3.empty());
}

///

TEST(test_front_queue, front_queue_1) {
  s21::queue<int> queue{1, 2, 3};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.front(), 1);
  queue.pop();
  size_t x = 2;
  ASSERT_EQ(queue.size(), x);
}

TEST(test_front_queue, front_queue_2) {
  s21::queue<char> queue{'a', 'b'};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.front(), 'a');
  queue.pop();
  size_t x = 1;
  ASSERT_EQ(queue.size(), x);
}

TEST(test_front_queue, front_queue_3) {
  s21::queue<double> queue{8.921321};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.front(), 8.921321);
  queue.pop();
  ASSERT_TRUE(queue.empty());
}

///

TEST(test_back_queue, back_queue_1) {
  s21::queue<int> queue{1, 2, 3};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.back(), 3);
  queue.pop();
  size_t x = 2;
  ASSERT_EQ(queue.size(), x);
}

TEST(test_back_queue, back_queue_2) {
  s21::queue<char> queue{'a', 'b'};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.back(), 'b');
  queue.pop();
  size_t x = 1;
  ASSERT_EQ(queue.size(), x);
}

TEST(test_back_queue, back_queue_3) {
  s21::queue<double> queue{8.921321};
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(queue.back(), 8.921321);
  queue.pop();
  ASSERT_TRUE(queue.empty());
}

///

TEST(test_swap_queue, swap_queue) {
  s21::queue<int> queue1{10, 20, 30, 40, 50};
  s21::queue<int> queue2{1, 2, 3, 4, 5};
  std::queue<int> queue3({10, 20, 30, 40, 50});
  std::queue<int> queue4({1, 2, 3, 4, 5});
  queue1.swap(queue2);
  queue3.swap(queue4);
  ASSERT_EQ(queue1.front(), queue3.front());
  queue1.pop();
  queue3.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue1.front(), queue3.front());
  queue1.pop();
  queue3.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue1.front(), queue3.front());
  queue1.pop();
  queue3.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
  queue2.pop();
  queue4.pop();
  ASSERT_EQ(queue1.front(), queue3.front());
  queue1.pop();
  queue3.pop();
  ASSERT_EQ(queue2.front(), queue4.front());
}

///

TEST(test_emplace_back, emplace_back) {
  s21::queue<char> queue1;
  queue1.emplace_back('a', 'b');
  ASSERT_EQ(queue1.front(), 'a');
  ASSERT_EQ(queue1.back(), 'b');
}
