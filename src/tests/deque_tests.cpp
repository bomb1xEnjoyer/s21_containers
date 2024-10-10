#include "tests.h"

// constructor deque() test
TEST(TestDeque, TestDequeInit1) {
  s21::deque<int> deque1;
  EXPECT_TRUE(deque1.size() == 0);
  EXPECT_TRUE(deque1.empty() == true);
  EXPECT_ANY_THROW(deque1.front());
  EXPECT_ANY_THROW(deque1.back());

  s21::deque<double> deque2;
  EXPECT_TRUE(deque2.size() == 0);
  EXPECT_TRUE(deque2.empty() == true);
  EXPECT_ANY_THROW(deque2.front());
  EXPECT_ANY_THROW(deque2.back());

  s21::deque<char> deque3;
  EXPECT_TRUE(deque3.size() == 0);
  EXPECT_TRUE(deque3.empty() == true);
  EXPECT_ANY_THROW(deque3.front());
  EXPECT_ANY_THROW(deque3.back());

  s21::deque<std::string> deque4;
  EXPECT_TRUE(deque4.size() == 0);
  EXPECT_TRUE(deque4.empty() == true);
  EXPECT_ANY_THROW(deque4.front());
  EXPECT_ANY_THROW(deque4.back());
}

// constructor deque(std::initializer_list<value_type> const &items) test
TEST(TestDeque, TestDequeInit2) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::deque<int> deque1(items1);
  EXPECT_TRUE(deque1.size() == 5);
  EXPECT_TRUE(deque1.empty() == false);
  EXPECT_TRUE(deque1.front() == 1);
  EXPECT_TRUE(deque1.back() == 5);

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::deque<double> deque2(items2);
  EXPECT_TRUE(deque2.size() == 5);
  EXPECT_TRUE(deque2.empty() == false);
  EXPECT_TRUE(deque2.front() == 1.5);
  EXPECT_TRUE(deque2.back() == 5.000001);

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::deque<char> deque3(items3);
  EXPECT_TRUE(deque3.size() == 5);
  EXPECT_TRUE(deque3.empty() == false);
  EXPECT_TRUE(deque3.front() == 'a');
  EXPECT_TRUE(deque3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::deque<std::string> deque4(items4);
  EXPECT_TRUE(deque4.size() == 3);
  EXPECT_TRUE(deque4.empty() == false);
  EXPECT_TRUE(deque4.front() == str1);
  EXPECT_TRUE(deque4.back() == str3);
}

// constructor deque(const deque &other) test
TEST(TestDeque, TestDequeInit3) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::deque<int> other1(items1), deque1(other1);
  EXPECT_TRUE(deque1.size() == other1.size());
  EXPECT_TRUE(deque1.front() == other1.front());
  EXPECT_TRUE(deque1.back() == other1.back());

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::deque<double> other2(items2), deque2(other2);
  EXPECT_TRUE(deque2.size() == other2.size());
  EXPECT_TRUE(deque2.front() == other2.front());
  EXPECT_TRUE(deque2.back() == other2.back());

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::deque<char> other3(items3), deque3(other3);
  EXPECT_TRUE(deque3.size() == other3.size());
  EXPECT_TRUE(deque3.front() == other3.front());
  EXPECT_TRUE(deque3.back() == other3.back());

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::deque<std::string> other4(items4), deque4(other4);
  EXPECT_TRUE(deque4.size() == other4.size());
  EXPECT_TRUE(deque4.front() == other4.front());
  EXPECT_TRUE(deque4.back() == other4.back());

  s21::deque<char> other5, deque5(other5);
  EXPECT_TRUE(deque5.size() == other5.size());
  EXPECT_TRUE(deque5.empty() == other5.empty());
  EXPECT_ANY_THROW(deque5.front());
  EXPECT_ANY_THROW(deque5.back());
}

// constructor deque(deque &&other) test
TEST(TestDeque, TestDequeInit4) {
  s21::deque<int> deque1(s21::deque<int>{1, 2, 3, 4, 5});
  EXPECT_TRUE(deque1.size() == 5);
  EXPECT_TRUE(deque1.empty() == false);
  EXPECT_TRUE(deque1.front() == 1);
  EXPECT_TRUE(deque1.back() == 5);

  s21::deque<double> deque2(
      s21::deque<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001});
  EXPECT_TRUE(deque2.size() == 5);
  EXPECT_TRUE(deque2.empty() == false);
  EXPECT_TRUE(deque2.front() == 1.5);
  EXPECT_TRUE(deque2.back() == 5.000001);

  s21::deque<char> deque3(s21::deque<char>{'a', 'b', 'c', 'd', 'e'});
  EXPECT_TRUE(deque3.size() == 5);
  EXPECT_TRUE(deque3.empty() == false);
  EXPECT_TRUE(deque3.front() == 'a');
  EXPECT_TRUE(deque3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::deque<std::string> deque4(s21::deque<std::string>{str1, str2, str3});
  EXPECT_TRUE(deque4.size() == 3);
  EXPECT_TRUE(deque4.empty() == false);
  EXPECT_TRUE(deque4.front() == str1);
  EXPECT_TRUE(deque4.back() == str3);
}

// operator=(deque &&other) test
TEST(TestDeque, TestDequeOperatorEq) {
  s21::deque<int> deque1 = s21::deque<int>{1, 2, 3, 4, 5};
  EXPECT_TRUE(deque1.size() == 5);
  EXPECT_TRUE(deque1.empty() == false);
  EXPECT_TRUE(deque1.front() == 1);
  EXPECT_TRUE(deque1.back() == 5);

  s21::deque<double> deque2 =
      s21::deque<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001};
  EXPECT_TRUE(deque2.size() == 5);
  EXPECT_TRUE(deque2.empty() == false);
  EXPECT_TRUE(deque2.front() == 1.5);
  EXPECT_TRUE(deque2.back() == 5.000001);

  s21::deque<char> deque3 = s21::deque<char>{'a', 'b', 'c', 'd', 'e'};
  EXPECT_TRUE(deque3.size() == 5);
  EXPECT_TRUE(deque3.empty() == false);
  EXPECT_TRUE(deque3.front() == 'a');
  EXPECT_TRUE(deque3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::deque<std::string> deque4 = s21::deque<std::string>{str1, str2, str3};
  EXPECT_TRUE(deque4.size() == 3);
  EXPECT_TRUE(deque4.empty() == false);
  EXPECT_TRUE(deque4.front() == str1);
  EXPECT_TRUE(deque4.back() == str3);
}

// push_back(const_reference value) test
TEST(DequeTest, DequeTestPushBack1) {
  s21::deque<int> int_deque;

  int_deque.push_back(1);
  EXPECT_TRUE(int_deque.back() == 1);
  EXPECT_TRUE(int_deque.size() == 1);

  int_deque.push_back(2);
  EXPECT_TRUE(int_deque.back() == 2);
  EXPECT_TRUE(int_deque.size() == 2);

  int_deque.push_back(3);
  EXPECT_TRUE(int_deque.back() == 3);
  EXPECT_TRUE(int_deque.size() == 3);

  EXPECT_TRUE(int_deque.front() == 1);
  EXPECT_TRUE(int_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushBack2) {
  s21::deque<double> double_deque;

  double_deque.push_back(1.0000001);
  EXPECT_TRUE(double_deque.back() == 1.0000001);
  EXPECT_TRUE(double_deque.size() == 1);

  double_deque.push_back(3.1415926);
  EXPECT_TRUE(double_deque.back() == 3.1415926);
  EXPECT_TRUE(double_deque.size() == 2);

  double_deque.push_back(5.0);
  EXPECT_TRUE(double_deque.back() == 5.0);
  EXPECT_TRUE(double_deque.size() == 3);

  EXPECT_TRUE(double_deque.front() == 1.0000001);
  EXPECT_TRUE(double_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushBack3) {
  s21::deque<char> char_deque;

  char_deque.push_back('a');
  EXPECT_TRUE(char_deque.back() == 'a');
  EXPECT_TRUE(char_deque.size() == 1);

  char_deque.push_back('x');
  EXPECT_TRUE(char_deque.back() == 'x');
  EXPECT_TRUE(char_deque.size() == 2);

  char_deque.push_back(127);
  EXPECT_TRUE(char_deque.back() == 127);
  EXPECT_TRUE(char_deque.size() == 3);

  EXPECT_TRUE(char_deque.front() == 'a');
  EXPECT_TRUE(char_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushBack4) {
  s21::deque<std::string> string_deque;

  string_deque.push_back("some_string1");
  EXPECT_TRUE(string_deque.back() == "some_string1");
  EXPECT_TRUE(string_deque.size() == 1);

  string_deque.push_back("some_string2");
  EXPECT_TRUE(string_deque.back() == "some_string2");
  EXPECT_TRUE(string_deque.size() == 2);

  string_deque.push_back("");
  EXPECT_TRUE(string_deque.back() == "");
  EXPECT_TRUE(string_deque.size() == 3);

  EXPECT_TRUE(string_deque.front() == "some_string1");
  EXPECT_TRUE(string_deque.empty() == false);
}

// push_front(const_reference value) test
TEST(DequeTest, DequeTestPushFront1) {
  s21::deque<int> int_deque;

  int_deque.push_front(1);
  EXPECT_TRUE(int_deque.front() == 1);
  EXPECT_TRUE(int_deque.size() == 1);

  int_deque.push_front(2);
  EXPECT_TRUE(int_deque.front() == 2);
  EXPECT_TRUE(int_deque.size() == 2);

  int_deque.push_front(3);
  EXPECT_TRUE(int_deque.front() == 3);
  EXPECT_TRUE(int_deque.size() == 3);

  EXPECT_TRUE(int_deque.back() == 1);
  EXPECT_TRUE(int_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushFront2) {
  s21::deque<double> double_deque;

  double_deque.push_front(1.0000001);
  EXPECT_TRUE(double_deque.front() == 1.0000001);
  EXPECT_TRUE(double_deque.size() == 1);

  double_deque.push_front(3.1415926);
  EXPECT_TRUE(double_deque.front() == 3.1415926);
  EXPECT_TRUE(double_deque.size() == 2);

  double_deque.push_front(5.0);
  EXPECT_TRUE(double_deque.front() == 5.0);
  EXPECT_TRUE(double_deque.size() == 3);

  EXPECT_TRUE(double_deque.back() == 1.0000001);
  EXPECT_TRUE(double_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushFront3) {
  s21::deque<char> char_deque;

  char_deque.push_front('a');
  EXPECT_TRUE(char_deque.front() == 'a');
  EXPECT_TRUE(char_deque.size() == 1);

  char_deque.push_front('x');
  EXPECT_TRUE(char_deque.front() == 'x');
  EXPECT_TRUE(char_deque.size() == 2);

  char_deque.push_front(127);
  EXPECT_TRUE(char_deque.front() == 127);
  EXPECT_TRUE(char_deque.size() == 3);

  EXPECT_TRUE(char_deque.back() == 'a');
  EXPECT_TRUE(char_deque.empty() == false);
}

TEST(DequeTest, DequeTestPushFront4) {
  s21::deque<std::string> string_deque;

  string_deque.push_front("some_string1");
  EXPECT_TRUE(string_deque.front() == "some_string1");
  EXPECT_TRUE(string_deque.size() == 1);

  string_deque.push_front("some_string2");
  EXPECT_TRUE(string_deque.front() == "some_string2");
  EXPECT_TRUE(string_deque.size() == 2);

  string_deque.push_front("");
  EXPECT_TRUE(string_deque.front() == "");
  EXPECT_TRUE(string_deque.size() == 3);

  EXPECT_TRUE(string_deque.back() == "some_string1");
  EXPECT_TRUE(string_deque.empty() == false);
}

// pop_front() test
TEST(DequeTest, DequeTestPopFront1) {
  std::initializer_list<int> items = {1, 2, 3};
  s21::deque<int> int_deque(items);

  int_deque.pop_front();
  EXPECT_TRUE(int_deque.size() == 2);
  EXPECT_TRUE(int_deque.front() == 2);

  int_deque.push_front(4);
  int_deque.push_front(5);
  int_deque.pop_front();
  EXPECT_TRUE(int_deque.size() == 3);
  EXPECT_TRUE(int_deque.front() == 4);

  while (int_deque.size()) int_deque.pop_front();
  EXPECT_TRUE(int_deque.size() == 0);
  EXPECT_ANY_THROW(int_deque.front());
}

TEST(DequeTest, DequeTestPopFront2) {
  std::initializer_list<double> items = {1.00001, 2.5, 3.14};
  s21::deque<double> double_deque(items);

  double_deque.pop_front();
  EXPECT_TRUE(double_deque.size() == 2);
  EXPECT_TRUE(double_deque.front() == 2.5);

  double_deque.push_front(4.44);
  double_deque.push_front(5.505);
  double_deque.pop_front();
  EXPECT_TRUE(double_deque.size() == 3);
  EXPECT_TRUE(double_deque.front() == 4.44);

  while (double_deque.size()) double_deque.pop_front();
  EXPECT_TRUE(double_deque.size() == 0);
  EXPECT_ANY_THROW(double_deque.front());
}

TEST(DequeTest, DequeTestPopFront3) {
  std::initializer_list<char> items = {'z', '[', ')'};
  s21::deque<char> char_deque(items);

  char_deque.pop_front();
  EXPECT_TRUE(char_deque.size() == 2);
  EXPECT_TRUE(char_deque.front() == '[');

  char_deque.push_front('@');
  char_deque.push_front('o');
  char_deque.pop_front();
  EXPECT_TRUE(char_deque.size() == 3);
  EXPECT_TRUE(char_deque.front() == '@');

  while (char_deque.size()) char_deque.pop_front();
  EXPECT_TRUE(char_deque.size() == 0);
  EXPECT_ANY_THROW(char_deque.front());
}

TEST(DequeTest, DequeTestPopFront4) {
  std::string str1 = "some_string1", str2 = "some_string2", str3 = "";
  std::initializer_list<std::string> items = {str1, str2, str3};
  s21::deque<std::string> str_deque(items);

  str_deque.pop_front();
  EXPECT_TRUE(str_deque.size() == 2);
  EXPECT_TRUE(str_deque.front() == str2);

  str_deque.push_front("push front");
  str_deque.push_front("pop front");
  str_deque.pop_front();
  EXPECT_TRUE(str_deque.size() == 3);
  EXPECT_TRUE(str_deque.front() == "push front");

  while (str_deque.size()) str_deque.pop_front();
  EXPECT_TRUE(str_deque.size() == 0);
  EXPECT_ANY_THROW(str_deque.front());
}

// swap(deque &other) test
TEST(DequeTest, DequeTestSwap1) {
  s21::deque<int> deque1{1, 2, 3}, deque2{4, 5, 6, 7};

  deque1.swap(deque2);

  EXPECT_TRUE(deque1.size() == 4);
  EXPECT_TRUE(deque2.size() == 3);

  EXPECT_TRUE(deque1.front() == 4);
  EXPECT_TRUE(deque1.back() == 7);
  EXPECT_TRUE(deque2.front() == 1);
  EXPECT_TRUE(deque2.back() == 3);

  deque1.pop_front();
  EXPECT_TRUE(deque1.front() == 5);

  deque2.pop_front();
  EXPECT_TRUE(deque2.front() == 2);
}

TEST(DequeTest, DequeTestSwap2) {
  std::string str1 = "123", str2 = "", str3 = "\nsome text\n", str4 = "four";
  s21::deque<std::string> deque1{str1, str2}, deque2{str3, str4};

  deque1.swap(deque2);

  EXPECT_TRUE(deque1.size() == 2);
  EXPECT_TRUE(deque2.size() == 2);

  EXPECT_TRUE(deque1.front() == "\nsome text\n");
  EXPECT_TRUE(deque1.back() == "four");
  EXPECT_TRUE(deque2.front() == "123");
  EXPECT_TRUE(deque2.back() == "");

  deque1.pop_front();
  EXPECT_TRUE(deque1.front() == "four");

  deque2.pop_front();
  EXPECT_TRUE(deque2.front() == "");
}