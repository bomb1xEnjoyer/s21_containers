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
TEST(ArrayTest, ArrayTestAt1) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  for (size_t i = 0; i < 9; ++i) EXPECT_TRUE(int_array.at(i) == nums[i]);
  int_array.at(0) = 50;
  EXPECT_TRUE(int_array.at(0) == 50);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  for (size_t i = 0; i < 3; ++i) EXPECT_TRUE(str_array.at(i) == strings[i]);
  str_array.at(0) = strings[1];
  EXPECT_TRUE(str_array.at(0) == strings[1]);
}

TEST(ArrayTest, ArrayTestAt2) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  EXPECT_ANY_THROW(int_array.at(500) == 2);
  EXPECT_ANY_THROW(int_array.at(-1) == 2);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  EXPECT_ANY_THROW(str_array.at(500) == "some");
  EXPECT_ANY_THROW(str_array.at(-1) == "some");

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.at(-1) == 3.14);
}

// reference operator[](size_type pos) test
TEST(ArrayTest, ArrayTestOperatorSquareBrackets1) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  for (size_t i = 0; i < 9; ++i) EXPECT_TRUE(int_array[i] == nums[i]);
  int_array[0] = 50;
  EXPECT_TRUE(int_array[0] == 50);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  for (size_t i = 0; i < 3; ++i) EXPECT_TRUE(str_array[i] == strings[i]);
  str_array[0] = strings[1];
  EXPECT_TRUE(str_array[0] == strings[1]);
}

TEST(ArrayTest, ArrayTestOperatorSquareBrackets2) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  EXPECT_ANY_THROW(int_array[500] == 2);
  EXPECT_ANY_THROW(int_array[-1] == 2);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  EXPECT_ANY_THROW(str_array[500] == "some");
  EXPECT_ANY_THROW(str_array[-1] == "some");

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array[-1] == 3.14);
}

// const_reference front() test
TEST(ArrayTest, ArrayTestFront) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  EXPECT_TRUE(int_array.front() == 1);
  EXPECT_FALSE(int_array.front() == 9);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  EXPECT_TRUE(str_array.front() == strings[0]);
  EXPECT_FALSE(str_array.front() == strings[2]);

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.front() == 3.14);
}

// const_reference back() test
TEST(ArrayTest, ArrayTestBack) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};

  EXPECT_TRUE(int_array.back() == 9);
  EXPECT_FALSE(int_array.back() == 1);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};

  EXPECT_TRUE(str_array.back() == strings[2]);
  EXPECT_FALSE(str_array.back() == strings[0]);

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.back() == 3.14);
}

// iterator data() test
TEST(ArrayTest, ArrayTestData) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  int* int_array_ptr = int_array.data();

  for (size_t i = 0; i < 9; ++i) EXPECT_TRUE(int_array_ptr[i] == nums[i]);
  int_array_ptr[0] = 50;
  EXPECT_TRUE(int_array_ptr[0] == 50);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};
  std::string* str_array_ptr = str_array.data();

  for (size_t i = 0; i < 3; ++i) EXPECT_TRUE(str_array_ptr[i] == strings[i]);
  str_array_ptr[0] = strings[1];
  EXPECT_TRUE(str_array_ptr[0] == strings[1]);

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.data());
}

// iterator begin() test
TEST(ArrayTest, ArrayTestBegin) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  int* int_array_begin = int_array.begin();

  for (size_t i = 0; i < 9; ++i) EXPECT_TRUE(int_array_begin[i] == nums[i]);
  int_array_begin[0] = 50;
  EXPECT_TRUE(int_array_begin[0] == 50);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};
  std::string* str_array_begin = str_array.begin();

  for (size_t i = 0; i < 3; ++i) EXPECT_TRUE(str_array_begin[i] == strings[i]);
  str_array_begin[0] = strings[1];
  EXPECT_TRUE(str_array_begin[0] == strings[1]);

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.begin());
}

// iterator end() test
TEST(ArrayTest, ArrayTestEnd) {
  int nums[] = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  s21::array<int, 9> int_array = {1, 20, 300, 400, 5000, 6000, 700, 80, 9};
  int* int_array_end = int_array.end();

  --int_array_end;
  EXPECT_TRUE(*int_array_end == nums[8]);

  std::string strings[] = {"123", "some string", "another string"};
  s21::array<std::string, 3> str_array = {strings[0], strings[1], strings[2]};
  std::string* str_array_end = str_array.end();

  --str_array_end;
  EXPECT_TRUE(*str_array_end == strings[2]);

  s21::array<double, 0> double_array;

  EXPECT_ANY_THROW(double_array.end());
}

// bool empty() test
TEST(ArrayTest, ArrayTestEmpty) {
  s21::array<int, 3> int_array1 = {1, 2, 3};
  s21::array<int, 3> int_array2 = {0};
  s21::array<int, 3> int_array3;
  s21::array<int, 0> int_array4;

  EXPECT_TRUE(int_array1.empty() == false);
  EXPECT_TRUE(int_array2.empty() == false);
  EXPECT_TRUE(int_array3.empty() == false);
  EXPECT_TRUE(int_array4.empty() == true);
}

// size_type size() and size_type max_size() test
TEST(ArrayTest, ArrayTestSizeAndMaxSize) {
  s21::array<int, 3> int_array1 = {1, 2, 3};
  s21::array<int, 3> int_array2 = {500, 1000};
  s21::array<int, 0> int_array3;

  EXPECT_TRUE(int_array1.size() == 3);
  EXPECT_TRUE(int_array1.size() == int_array1.max_size());

  EXPECT_TRUE(int_array2.size() == 3);
  EXPECT_TRUE(int_array2.size() == int_array2.max_size());

  EXPECT_TRUE(int_array3.size() == 0);
  EXPECT_TRUE(int_array3.size() == int_array3.max_size());
}

// void swap(array &other) test
TEST(ArrayTest, ArrayTestSwap1) {
  s21::array<int, 3> int_array1 = {1, 2, 3};
  s21::array<int, 3> int_array2 = {4, 5, 6};

  int_array1.swap(int_array2);

  EXPECT_TRUE(int_array1[0] == 4);
  EXPECT_TRUE(int_array1[1] == 5);
  EXPECT_TRUE(int_array1[2] == 6);
  EXPECT_TRUE(int_array2[0] == 1);
  EXPECT_TRUE(int_array2[1] == 2);
  EXPECT_TRUE(int_array2[2] == 3);
}

TEST(ArrayTest, ArrayTestSwap2) {
  s21::array<std::string, 3> str_array1 = {"one", "two", "three"};
  s21::array<std::string, 3> str_array2 = {"four", "five"};

  str_array1.swap(str_array2);

  EXPECT_TRUE(str_array1[0] == "four");
  EXPECT_TRUE(str_array1[1] == "five");
  EXPECT_TRUE(str_array2[0] == "one");
  EXPECT_TRUE(str_array2[1] == "two");
  EXPECT_TRUE(str_array2[2] == "three");
}

// void fill(const_reference value) test
TEST(ArrayTest, ArrayTestFill1) {
  s21::array<int, 10> int_array;

  int_array.fill(10);

  for (size_t i = 0; i < 10; ++i) EXPECT_TRUE(int_array[i] == 10);
}

TEST(ArrayTest, ArrayTestFill2) {
  s21::array<std::string, 3> str_array;

  str_array.fill("str_array");

  for (size_t i = 0; i < 3; ++i) EXPECT_TRUE(str_array[i] == "str_array");
}
