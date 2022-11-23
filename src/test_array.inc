TEST(test_at_queue, at_queue) {
  s21::array<int, 3> arr{10, 20, 30};
  ASSERT_EQ(arr.at(0), 10);
  ASSERT_EQ(arr.at(1), 20);
  ASSERT_EQ(arr.at(2), 30);
  ASSERT_THROW(arr.at(3), std::out_of_range);
  ASSERT_THROW(arr.at(-1), std::out_of_range);
}

///

TEST(test_square_brackets, square_brackets) {
  s21::array<int, 3> arr{10, 20, 30};
  ASSERT_EQ(arr[0], 10);
  ASSERT_EQ(arr[1], 20);
  ASSERT_EQ(arr[2], 30);
}

///

TEST(test_front_array, front_array) {
  std::array<int, 3> arr{10, 20, 30};
  s21::array<int, 3> arr2{10, 20, 30};
  ASSERT_EQ(arr.front(), arr2.front());
}

///

TEST(test_back_array, back_array) {
  std::array<int, 3> arr{10, 20, 30};
  s21::array<int, 3> arr2{10, 20, 30};
  // std::array<int, 3> arr3;
  ASSERT_EQ(arr.back(), arr2.back());
}

///

TEST(test_data_array, data_array) {
  s21::array<int, 3> arr{10, 20, 30};
  int *data_array = arr.data();
  ASSERT_EQ(arr[0], data_array[0]);
  ASSERT_EQ(arr[1], data_array[1]);
  ASSERT_EQ(arr[2], data_array[2]);
}

///

TEST(test_begin_array, begin_array) {
  s21::array<int, 3> arr{10, 20, 30};
  ASSERT_EQ(arr[0], *arr.begin());
}

///

TEST(test_end_array, end_array) {
  s21::array<int, 3> arr{10, 20, 30};
  ASSERT_EQ(arr[2], *arr.end());
}

///

TEST(test_empty_array, empty_array) {  // не создается пкстой статический массив
  s21::array<int, 5> arr;
  // s21::array<int, 0> arr2;
  ASSERT_FALSE(arr.empty());
  // ASSERT_TRUE(arr2.empty());
}

///

TEST(test_size_array, size_array) {
  s21::array<int, 5> arr;
  ASSERT_EQ(arr.size(), 5UL);
}

///

TEST(test_max_size_array, max_size_array) {
  s21::array<int, 5> arr;
  ASSERT_EQ(arr.max_size(), 5UL);
}

///

TEST(test_swap_array, swap_array) {
  s21::array<int, 3> arr1{1, 2, 3};
  s21::array<int, 3> arr2{90, 80, 70};
  arr1.swap(arr2);
  ASSERT_EQ(arr1[0], 90);
  ASSERT_EQ(arr1[1], 80);
  ASSERT_EQ(arr1[2], 70);
  ASSERT_EQ(arr2[0], 1);
  ASSERT_EQ(arr2[1], 2);
  ASSERT_EQ(arr2[2], 3);
}

///

TEST(test_fill_array, fill_array) {
  s21::array<int, 3> arr{1, 2, 3};
  arr.fill(100);
  ASSERT_EQ(arr[0], 100);
  ASSERT_EQ(arr[1], 100);
  ASSERT_EQ(arr[2], 100);
}

///

TEST(test_moving_constructor_array, moving_constructor_array) {
  s21::array<int, 3> arr{1, 2, 3};
  s21::array<int, 3> arr2(std::move(arr));
  ASSERT_EQ(arr2[0], 1);
  ASSERT_EQ(arr2[1], 2);
  ASSERT_EQ(arr2[2], 3);
}

///

TEST(test_moving_overload_array, moving_overload_array) {
  s21::array<int, 3> arr{1, 2, 3};
  s21::array<int, 3> arr2 = std::move(arr);
  ASSERT_EQ(arr2[0], 1);
  ASSERT_EQ(arr2[1], 2);
  ASSERT_EQ(arr2[2], 3);
}

///

TEST(test_copy_constructor_array, copy_constructor_array) {
  s21::array<int, 3> arr{1, 2, 3};
  s21::array<int, 3> arr2(arr);
  ASSERT_EQ(arr2[0], 1);
  ASSERT_EQ(arr2[1], 2);
  ASSERT_EQ(arr2[2], 3);
}
