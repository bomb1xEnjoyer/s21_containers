#include "tests.h"

// constructor queue() test
TEST(QueueTest, QueueTestInit1) {
  s21::queue<int> queue1;
  EXPECT_TRUE(queue1.size() == 0);
  EXPECT_TRUE(queue1.empty() == true);
  EXPECT_ANY_THROW(queue1.front());
  EXPECT_ANY_THROW(queue1.back());

  s21::queue<double> queue2;
  EXPECT_TRUE(queue2.size() == 0);
  EXPECT_TRUE(queue2.empty() == true);
  EXPECT_ANY_THROW(queue2.front());
  EXPECT_ANY_THROW(queue2.back());

  s21::queue<char> queue3;
  EXPECT_TRUE(queue3.size() == 0);
  EXPECT_TRUE(queue3.empty() == true);
  EXPECT_ANY_THROW(queue3.front());
  EXPECT_ANY_THROW(queue3.back());

  s21::queue<std::string> queue4;
  EXPECT_TRUE(queue4.size() == 0);
  EXPECT_TRUE(queue4.empty() == true);
  EXPECT_ANY_THROW(queue4.front());
  EXPECT_ANY_THROW(queue4.back());
}

// constructor queue(std::initializer_list<value_type> const &items) test
TEST(QueueTest, QueueTestInit2) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::queue<int> queue1(items1);
  EXPECT_TRUE(queue1.size() == 5);
  EXPECT_TRUE(queue1.empty() == false);
  EXPECT_TRUE(queue1.front() == 1);
  EXPECT_TRUE(queue1.back() == 5);

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::queue<double> queue2(items2);
  EXPECT_TRUE(queue2.size() == 5);
  EXPECT_TRUE(queue2.empty() == false);
  EXPECT_TRUE(queue2.front() == 1.5);
  EXPECT_TRUE(queue2.back() == 5.000001);

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> queue3(items3);
  EXPECT_TRUE(queue3.size() == 5);
  EXPECT_TRUE(queue3.empty() == false);
  EXPECT_TRUE(queue3.front() == 'a');
  EXPECT_TRUE(queue3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::queue<std::string> queue4(items4);
  EXPECT_TRUE(queue4.size() == 3);
  EXPECT_TRUE(queue4.empty() == false);
  EXPECT_TRUE(queue4.front() == str1);
  EXPECT_TRUE(queue4.back() == str3);
}

// constructor queue(const queue &other) test
TEST(QueueTest, QueueTestInit3) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::queue<int> other1(items1), queue1(other1);
  EXPECT_TRUE(queue1.size() == other1.size());
  EXPECT_TRUE(queue1.front() == other1.front());
  EXPECT_TRUE(queue1.back() == other1.back());

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::queue<double> other2(items2), queue2(other2);
  EXPECT_TRUE(queue2.size() == other2.size());
  EXPECT_TRUE(queue2.front() == other2.front());
  EXPECT_TRUE(queue2.back() == other2.back());

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::queue<char> other3(items3), queue3(other3);
  EXPECT_TRUE(queue3.size() == other3.size());
  EXPECT_TRUE(queue3.front() == other3.front());
  EXPECT_TRUE(queue3.back() == other3.back());

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::queue<std::string> other4(items4), queue4(other4);
  EXPECT_TRUE(queue4.size() == other4.size());
  EXPECT_TRUE(queue4.front() == other4.front());
  EXPECT_TRUE(queue4.back() == other4.back());

  s21::queue<char> other5, queue5(other5);
  EXPECT_TRUE(queue5.size() == other5.size());
  EXPECT_TRUE(queue5.empty() == other5.empty());
  EXPECT_ANY_THROW(queue5.front());
  EXPECT_ANY_THROW(queue5.back());
}

// constructor queue(queue &&other) test
TEST(QueueTest, QueueTestInit4) {
  s21::queue<int> queue1(s21::queue<int>{1, 2, 3, 4, 5});
  EXPECT_TRUE(queue1.size() == 5);
  EXPECT_TRUE(queue1.empty() == false);
  EXPECT_TRUE(queue1.front() == 1);
  EXPECT_TRUE(queue1.back() == 5);

  s21::queue<double> queue2(
      s21::queue<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001});
  EXPECT_TRUE(queue2.size() == 5);
  EXPECT_TRUE(queue2.empty() == false);
  EXPECT_TRUE(queue2.front() == 1.5);
  EXPECT_TRUE(queue2.back() == 5.000001);

  s21::queue<char> queue3(s21::queue<char>{'a', 'b', 'c', 'd', 'e'});
  EXPECT_TRUE(queue3.size() == 5);
  EXPECT_TRUE(queue3.empty() == false);
  EXPECT_TRUE(queue3.front() == 'a');
  EXPECT_TRUE(queue3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::queue<std::string> queue4(s21::queue<std::string>{str1, str2, str3});
  EXPECT_TRUE(queue4.size() == 3);
  EXPECT_TRUE(queue4.empty() == false);
  EXPECT_TRUE(queue4.front() == str1);
  EXPECT_TRUE(queue4.back() == str3);
}

// operator=(queue &&other) test
TEST(QueueTest, QueueTestOperatorEq) {
  s21::queue<int> queue1 = s21::queue<int>{1, 2, 3, 4, 5};
  EXPECT_TRUE(queue1.size() == 5);
  EXPECT_TRUE(queue1.empty() == false);
  EXPECT_TRUE(queue1.front() == 1);
  EXPECT_TRUE(queue1.back() == 5);

  s21::queue<double> queue2 =
      s21::queue<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001};
  EXPECT_TRUE(queue2.size() == 5);
  EXPECT_TRUE(queue2.empty() == false);
  EXPECT_TRUE(queue2.front() == 1.5);
  EXPECT_TRUE(queue2.back() == 5.000001);

  s21::queue<char> queue3 = s21::queue<char>{'a', 'b', 'c', 'd', 'e'};
  EXPECT_TRUE(queue3.size() == 5);
  EXPECT_TRUE(queue3.empty() == false);
  EXPECT_TRUE(queue3.front() == 'a');
  EXPECT_TRUE(queue3.back() == 'e');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::queue<std::string> queue4 = s21::queue<std::string>{str1, str2, str3};
  EXPECT_TRUE(queue4.size() == 3);
  EXPECT_TRUE(queue4.empty() == false);
  EXPECT_TRUE(queue4.front() == str1);
  EXPECT_TRUE(queue4.back() == str3);
}

// push(const_reference value) test
TEST(QueueTest, QueueTestPush1) {
  s21::queue<int> int_queue;

  int_queue.push(1);
  EXPECT_TRUE(int_queue.back() == 1);
  EXPECT_TRUE(int_queue.size() == 1);

  int_queue.push(2);
  EXPECT_TRUE(int_queue.back() == 2);
  EXPECT_TRUE(int_queue.size() == 2);

  int_queue.push(3);
  EXPECT_TRUE(int_queue.back() == 3);
  EXPECT_TRUE(int_queue.size() == 3);

  EXPECT_TRUE(int_queue.front() == 1);
  EXPECT_TRUE(int_queue.empty() == false);
}

TEST(QueueTest, QueueTestPush2) {
  s21::queue<double> double_queue;

  double_queue.push(1.0000001);
  EXPECT_TRUE(double_queue.back() == 1.0000001);
  EXPECT_TRUE(double_queue.size() == 1);

  double_queue.push(3.1415926);
  EXPECT_TRUE(double_queue.back() == 3.1415926);
  EXPECT_TRUE(double_queue.size() == 2);

  double_queue.push(5.0);
  EXPECT_TRUE(double_queue.back() == 5.0);
  EXPECT_TRUE(double_queue.size() == 3);

  EXPECT_TRUE(double_queue.front() == 1.0000001);
  EXPECT_TRUE(double_queue.empty() == false);
}

TEST(QueueTest, QueueTestPush3) {
  s21::queue<char> char_queue;

  char_queue.push('a');
  EXPECT_TRUE(char_queue.back() == 'a');
  EXPECT_TRUE(char_queue.size() == 1);

  char_queue.push('x');
  EXPECT_TRUE(char_queue.back() == 'x');
  EXPECT_TRUE(char_queue.size() == 2);

  char_queue.push(127);
  EXPECT_TRUE(char_queue.back() == 127);
  EXPECT_TRUE(char_queue.size() == 3);

  EXPECT_TRUE(char_queue.front() == 'a');
  EXPECT_TRUE(char_queue.empty() == false);
}

TEST(QueueTest, QueueTestPush4) {
  s21::queue<std::string> string_queue;

  string_queue.push("some_string1");
  EXPECT_TRUE(string_queue.back() == "some_string1");
  EXPECT_TRUE(string_queue.size() == 1);

  string_queue.push("some_string2");
  EXPECT_TRUE(string_queue.back() == "some_string2");
  EXPECT_TRUE(string_queue.size() == 2);

  string_queue.push("");
  EXPECT_TRUE(string_queue.back() == "");
  EXPECT_TRUE(string_queue.size() == 3);

  EXPECT_TRUE(string_queue.front() == "some_string1");
  EXPECT_TRUE(string_queue.empty() == false);
}

// pop() test
TEST(QueueTest, QueueTestPop1) {
  std::initializer_list<int> items = {1, 2, 3};
  s21::queue<int> int_queue(items);

  int_queue.pop();
  EXPECT_TRUE(int_queue.size() == 2);
  EXPECT_TRUE(int_queue.front() == 2);

  int_queue.push(4);
  int_queue.push(5);
  int_queue.pop();
  EXPECT_TRUE(int_queue.size() == 3);
  EXPECT_TRUE(int_queue.front() == 3);

  while (int_queue.size()) int_queue.pop();
  EXPECT_TRUE(int_queue.size() == 0);
  EXPECT_ANY_THROW(int_queue.front());
}

TEST(QueueTest, QueueTestPop2) {
  std::initializer_list<double> items = {1.00001, 2.5, 3.14};
  s21::queue<double> double_queue(items);

  double_queue.pop();
  EXPECT_TRUE(double_queue.size() == 2);
  EXPECT_TRUE(double_queue.front() == 2.5);

  double_queue.push(4.44);
  double_queue.push(5.505);
  double_queue.pop();
  EXPECT_TRUE(double_queue.size() == 3);
  EXPECT_TRUE(double_queue.front() == 3.14);

  while (double_queue.size()) double_queue.pop();
  EXPECT_TRUE(double_queue.size() == 0);
  EXPECT_ANY_THROW(double_queue.front());
}

TEST(QueueTest, QueueTestPop3) {
  std::initializer_list<char> items = {'z', '[', ')'};
  s21::queue<char> char_queue(items);

  char_queue.pop();
  EXPECT_TRUE(char_queue.size() == 2);
  EXPECT_TRUE(char_queue.front() == '[');

  char_queue.push('@');
  char_queue.push('o');
  char_queue.pop();
  EXPECT_TRUE(char_queue.size() == 3);
  EXPECT_TRUE(char_queue.front() == ')');

  while (char_queue.size()) char_queue.pop();
  EXPECT_TRUE(char_queue.size() == 0);
  EXPECT_ANY_THROW(char_queue.front());
}

TEST(QueueTest, QueueTestPop4) {
  std::string str1 = "some_string1", str2 = "some_string2", str3 = "";
  std::initializer_list<std::string> items = {str1, str2, str3};
  s21::queue<std::string> str_queue(items);

  str_queue.pop();
  EXPECT_TRUE(str_queue.size() == 2);
  EXPECT_TRUE(str_queue.front() == str2);

  str_queue.push("push front");
  str_queue.push("pop front");
  str_queue.pop();
  EXPECT_TRUE(str_queue.size() == 3);
  EXPECT_TRUE(str_queue.front() == "");

  while (str_queue.size()) str_queue.pop();
  EXPECT_TRUE(str_queue.size() == 0);
  EXPECT_ANY_THROW(str_queue.front());
}

// swap(queue &other) test
TEST(QueueTest, QueueTestSwap1) {
  s21::queue<int> queue1{1, 2, 3}, queue2{4, 5, 6, 7};

  queue1.swap(queue2);

  EXPECT_TRUE(queue1.size() == 4);
  EXPECT_TRUE(queue2.size() == 3);

  EXPECT_TRUE(queue1.front() == 4);
  EXPECT_TRUE(queue1.back() == 7);
  EXPECT_TRUE(queue2.front() == 1);
  EXPECT_TRUE(queue2.back() == 3);

  queue1.pop();
  EXPECT_TRUE(queue1.front() == 5);

  queue2.pop();
  EXPECT_TRUE(queue2.front() == 2);
}

TEST(QueueTest, QueueTestSwap2) {
  std::string str1 = "123", str2 = "", str3 = "\nsome text\n", str4 = "four";
  s21::queue<std::string> queue1{str1, str2}, queue2{str3, str4};

  queue1.swap(queue2);

  EXPECT_TRUE(queue1.size() == 2);
  EXPECT_TRUE(queue2.size() == 2);

  EXPECT_TRUE(queue1.front() == "\nsome text\n");
  EXPECT_TRUE(queue1.back() == "four");
  EXPECT_TRUE(queue2.front() == "123");
  EXPECT_TRUE(queue2.back() == "");

  queue1.pop();
  EXPECT_TRUE(queue1.front() == "four");

  queue2.pop();
  EXPECT_TRUE(queue2.front() == "");
}

// void insert_many_back(Args&&... args) test
TEST(QueueTest, QueueInsertMany1) {
  s21::queue<int> int_queue;

  int_queue.insert_many_back(1, 2, 3);
  EXPECT_TRUE(int_queue.front() == 1);
  EXPECT_TRUE(int_queue.back() == 3);

  int_queue.pop();
  EXPECT_TRUE(int_queue.front() == 2);

  int_queue.push(10);
  EXPECT_TRUE(int_queue.back() == 10);
}

TEST(QueueTest, QueueInsertMany2) {
  s21::queue<double> double_queue;

  double_queue.insert_many_back(1.15, 2.789, 3.14);
  EXPECT_TRUE(double_queue.front() == 1.15);
  EXPECT_TRUE(double_queue.back() == 3.14);

  double_queue.pop();
  EXPECT_TRUE(double_queue.front() == 2.789);

  double_queue.push(10.00);
  EXPECT_TRUE(double_queue.back() == 10.00);
}

TEST(QueueTest, QueueInsertMany3) {
  s21::queue<char> char_queue;

  char_queue.insert_many_back('a', '=', '*');
  EXPECT_TRUE(char_queue.front() == 'a');
  EXPECT_TRUE(char_queue.back() == '*');

  char_queue.pop();
  EXPECT_TRUE(char_queue.front() == '=');

  char_queue.push(105);
  EXPECT_TRUE(char_queue.back() == 105);
}

TEST(QueueTest, QueueInsertMany4) {
  std::string str1 = "first", str2 = "second", str3 = "last";
  s21::queue<std::string> string_queue;

  string_queue.insert_many_back(str1, str2, str3);
  EXPECT_TRUE(string_queue.front() == "first");
  EXPECT_TRUE(string_queue.back() == "last");

  string_queue.pop();
  EXPECT_TRUE(string_queue.front() == "second");

  string_queue.push("12345");
  EXPECT_TRUE(string_queue.back() == "12345");
}