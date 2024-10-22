#include "tests.h"

// constructor array() test
TEST(ArrayTest, ArrayTestInit1) {
  s21::array<int, 10> int_array;
  s21::array<char, 0> char_array;

  EXPECT_TRUE(int_array.size() == 10);
  EXPECT_TRUE(int_array.max_size() == 10);
  EXPECT_TRUE(int_array.empty() == false);

  EXPECT_TRUE(char_array.size() == 0);
  EXPECT_TRUE(char_array.max_size() == 0);
  EXPECT_TRUE(char_array.empty() == true);
}

// constructor array(std::initializer_list<value_type> const &items) test
TEST(ArrayTest, ArrayTestInit2) {
  std::initializer_list<int> nums = {1, 2, 3, 4, 5};
  s21::array<int, 5> int_array{nums};

  EXPECT_TRUE(int_array.front() == 1);
  EXPECT_TRUE(int_array.back() == 5);

  std::string str1 = "123", str2 = "some string", str3 = "another string";
  std::initializer_list<std::string> strings = {str1, str2, str3};
  s21::array<std::string, 3> str_array{strings};

  EXPECT_TRUE(str_array.front() == str1);
  EXPECT_TRUE(str_array.back() == str3);

  std::initializer_list<double> empty_double_list;
  s21::array<double, 0> double_array(empty_double_list);

  EXPECT_TRUE(double_array.size() == 0);
  EXPECT_TRUE(double_array.max_size() == 0);
  EXPECT_TRUE(double_array.empty() == true);
}

// constructor array(const array &other) test
TEST(ArrayTest, ArrayTestInit3) {
  s21::array<int, 5> int_array1 = {1, 2, 3, 4, 100}, int_array2(int_array1);

  EXPECT_TRUE(int_array2.front() == 1);
  EXPECT_TRUE(int_array2.back() == 100);

  std::string str1 = "123", str2 = "some string", str3 = "another string";
  s21::array<std::string, 3> str_array1 = {str1, str2, str3},
                             str_array2(str_array1);

  EXPECT_TRUE(str_array2.front() == str1);
  EXPECT_TRUE(str_array2.back() == str3);

  s21::array<double, 0> double_array1, double_array2(double_array1);

  EXPECT_TRUE(double_array2.size() == 0);
  EXPECT_TRUE(double_array2.max_size() == 0);
  EXPECT_TRUE(double_array2.empty() == true);
}

// constructor array(array &&other) test
TEST(ArrayTest, ArrayTestInit4) {
  std::initializer_list<int> nums = {1, 2, 3, 4, 100};
  s21::array<int, 5> int_array2(s21::array<int, 5>{nums});

  EXPECT_TRUE(int_array2.front() == 1);
  EXPECT_TRUE(int_array2.back() == 100);

  std::string str1 = "123", str2 = "some string", str3 = "another string";
  s21::array<std::string, 3> str_array2(
      s21::array<std::string, 3>{str1, str2, str3});

  EXPECT_TRUE(str_array2.front() == str1);
  EXPECT_TRUE(str_array2.back() == str3);

  s21::array<double, 0> double_array2(s21::array<double, 0>{});

  EXPECT_TRUE(double_array2.size() == 0);
  EXPECT_TRUE(double_array2.max_size() == 0);
  EXPECT_TRUE(double_array2.empty() == true);
}

// array &operator=(array &&other) test
TEST(ArrayTest, ArrayTestOperatorEq) {
  s21::array<int, 9> int_array1 =
      s21::array<int, 9>{1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  EXPECT_TRUE(int_array1.front() == 1);
  EXPECT_TRUE(int_array1.back() == 9);

  std::string str1 = "123", str2 = "some string", str3 = "another string";
  s21::array<std::string, 3> str_array1 =
      s21::array<std::string, 3>{str1, str2, str3};

  EXPECT_TRUE(str_array1.front() == str1);
  EXPECT_TRUE(str_array1.back() == str3);

  s21::array<double, 0> double_array1 = s21::array<double, 0>{};

  EXPECT_TRUE(double_array1.size() == 0);
  EXPECT_TRUE(double_array1.max_size() == 0);
  EXPECT_TRUE(double_array1.empty() == true);
}

// reference at(size_type pos) test

// reference operator[](size_type pos) test

// const_reference front() const test

// const_reference back() const test

// iterator data() test

// iterator begin() test

// iterator end() test

// bool empty() const test

// size_type size() const test

// size_type max_size() const test

// void swap(array &other) test

// void fill(const_reference value) test
