TEST(test_constructor_copy_stack, constructor_copy_1) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2(stack1);
  std::stack<int> stack3({1, 2, 3});
  std::stack<int> stack4(stack3);
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
}

///

TEST(test_constructor_move_stack, constructor_move_1) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2(std::move(stack1));
  std::stack<int> stack3({1, 2, 3});
  std::stack<int> stack4(std::move(stack3));
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
}

///

TEST(test_empty_stack, empty_1) {
  s21::stack<int> stack;
  std::stack<int> stack_expected;
  ASSERT_EQ(stack.empty(), stack_expected.empty());
}

TEST(test_empty_stack, empty_2) {
  s21::stack<double> stack;
  std::stack<double> stack_expected;
  ASSERT_EQ(stack.empty(), stack_expected.empty());
}

TEST(test_empty_stack, empty_3) {
  s21::stack<char> stack;
  std::stack<char> stack_expected;
  ASSERT_EQ(stack.empty(), stack_expected.empty());
}

///

TEST(test_size_stack, size_1) {
  s21::stack<int> stack{1, 2, 3};
  size_t x = 3;
  ASSERT_EQ(stack.size(), x);
}

TEST(test_size_stack, size_2) {
  s21::stack<char> stack{1};
  size_t x = 1;
  ASSERT_EQ(stack.size(), x);
}

///

TEST(test_push_stack, top_push_1) {
  s21::stack<int> stack1;
  std::stack<int> stack2;
  stack1.push(1);
  stack2.push(1);
  ASSERT_EQ(stack1.top(), stack2.top());
  stack1.push(100);
  stack2.push(100);
  ASSERT_EQ(stack1.top(), stack2.top());
}

TEST(test_push_stack, top_push_2) {
  s21::stack<char> stack1{'l', 'e', 'x'};
  std::stack<char> stack2({'l', 'e', 'x'});
  stack1.push('a');
  stack2.push('a');
  ASSERT_EQ(stack1.top(), stack2.top());
  stack1.push('b');
  stack2.push('b');
  ASSERT_EQ(stack1.top(), stack2.top());
}

///

TEST(test_assignment_operator_overload_moving_object_stack,
     assignment_operator_overload_moving_object) {
  s21::stack<int> stack1{1, 2, 3};
  s21::stack<int> stack2;
  stack2 = std::move(stack1);
  std::stack<int> stack3({1, 2, 3});
  std::stack<int> stack4;
  stack4 = std::move(stack3);
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  ASSERT_EQ(stack1.empty(), stack3.empty());
}

///

TEST(test_top_pop_stack, top_pop_1) {
  s21::stack<int> stack{1, 2, 3};
  ASSERT_FALSE(stack.empty());
  ASSERT_EQ(stack.top(), 3);
  stack.pop();
  size_t x = 2;
  ASSERT_EQ(stack.size(), x);
}

TEST(test_top_pop_stack, top_pop_2) {
  s21::stack<char> stack{'a', 'b'};
  ASSERT_FALSE(stack.empty());
  ASSERT_EQ(stack.top(), 'b');
  stack.pop();
  size_t x = 1;
  ASSERT_EQ(stack.size(), x);
}

TEST(test_top_pop_stack, top_pop_3) {
  s21::stack<double> stack{8.921321};
  ASSERT_FALSE(stack.empty());
  ASSERT_EQ(stack.top(), 8.921321);
  stack.pop();
  ASSERT_TRUE(stack.empty());
}

///

TEST(test_swap_stack, swap_stack) {
  s21::stack<int> stack1{10, 20, 30, 40, 50};
  s21::stack<int> stack2{1, 2, 3, 4, 5};
  std::stack<int> stack3({10, 20, 30, 40, 50});
  std::stack<int> stack4({1, 2, 3, 4, 5});
  stack1.swap(stack2);
  stack3.swap(stack4);
  ASSERT_EQ(stack1.top(), stack3.top());
  stack1.pop();
  stack3.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack1.top(), stack3.top());
  stack1.pop();
  stack3.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack1.top(), stack3.top());
  stack1.pop();
  stack3.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
  stack2.pop();
  stack4.pop();
  ASSERT_EQ(stack1.top(), stack3.top());
  stack1.pop();
  stack3.pop();
  ASSERT_EQ(stack2.top(), stack4.top());
}

///

TEST(test_emplace_front, emplace_front) {
  s21::stack<char> stack{'a'};
  ASSERT_EQ(stack.top(), 'a');
  stack.pop();
  stack.emplace_front('b', 'c');
  ASSERT_EQ(stack.top(), 'b');
  stack.pop();
  ASSERT_EQ(stack.top(), 'c');
  stack.pop();
}
