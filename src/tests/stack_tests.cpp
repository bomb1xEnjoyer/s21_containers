#include "tests.h"

// constructor stack() test
TEST(StackTest, StackTestInit1) {
  s21::stack<int> stack1;
  EXPECT_TRUE(stack1.size() == 0);
  EXPECT_TRUE(stack1.empty() == true);
  EXPECT_ANY_THROW(stack1.top());

  s21::stack<double> stack2;
  EXPECT_TRUE(stack2.size() == 0);
  EXPECT_TRUE(stack2.empty() == true);
  EXPECT_ANY_THROW(stack2.top());

  s21::stack<char> stack3;
  EXPECT_TRUE(stack3.size() == 0);
  EXPECT_TRUE(stack3.empty() == true);
  EXPECT_ANY_THROW(stack3.top());

  s21::stack<std::string> stack4;
  EXPECT_TRUE(stack4.size() == 0);
  EXPECT_TRUE(stack4.empty() == true);
  EXPECT_ANY_THROW(stack4.top());
}

// constructor stack(std::initializer_list<value_type> const &items) test
TEST(StackTest, StackTestInit2) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::stack<int> stack1(items1);
  EXPECT_TRUE(stack1.size() == 5);
  EXPECT_TRUE(stack1.empty() == false);
  EXPECT_TRUE(stack1.top() == 1);

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::stack<double> stack2(items2);
  EXPECT_TRUE(stack2.size() == 5);
  EXPECT_TRUE(stack2.empty() == false);
  EXPECT_TRUE(stack2.top() == 1.5);

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::stack<char> stack3(items3);
  EXPECT_TRUE(stack3.size() == 5);
  EXPECT_TRUE(stack3.empty() == false);
  EXPECT_TRUE(stack3.top() == 'a');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::stack<std::string> stack4(items4);
  EXPECT_TRUE(stack4.size() == 3);
  EXPECT_TRUE(stack4.empty() == false);
  EXPECT_TRUE(stack4.top() == str1);
}

// constructor stack(const stack &other) test
TEST(StackTest, StackTestInit3) {
  std::initializer_list<int> items1 = {1, 2, 3, 4, 5};
  s21::stack<int> other1(items1), stack1(other1);
  EXPECT_TRUE(stack1.size() == other1.size());
  EXPECT_TRUE(stack1.top() == other1.top());

  std::initializer_list<double> items2 = {1.5, 2.123, 3.987765, 4.0001,
                                          5.000001};
  s21::stack<double> other2(items2), stack2(other2);
  EXPECT_TRUE(stack2.size() == other2.size());
  EXPECT_TRUE(stack2.top() == other2.top());

  std::initializer_list<char> items3 = {'a', 'b', 'c', 'd', 'e'};
  s21::stack<char> other3(items3), stack3(other3);
  EXPECT_TRUE(stack3.size() == other3.size());
  EXPECT_TRUE(stack3.top() == other3.top());

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  std::initializer_list<std::string> items4 = {str1, str2, str3};
  s21::stack<std::string> other4(items4), stack4(other4);
  EXPECT_TRUE(stack4.size() == other4.size());
  EXPECT_TRUE(stack4.top() == other4.top());

  s21::stack<char> other5, stack5(other5);
  EXPECT_TRUE(stack5.size() == other5.size());
  EXPECT_TRUE(stack5.empty() == other5.empty());
  EXPECT_ANY_THROW(stack5.top());
}

// constructor stack(stack &&other) test
TEST(StackTest, StackTestInit4) {
  s21::stack<int> stack1(s21::stack<int>{1, 2, 3, 4, 5});
  EXPECT_TRUE(stack1.size() == 5);
  EXPECT_TRUE(stack1.empty() == false);
  EXPECT_TRUE(stack1.top() == 1);

  s21::stack<double> stack2(
      s21::stack<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001});
  EXPECT_TRUE(stack2.size() == 5);
  EXPECT_TRUE(stack2.empty() == false);
  EXPECT_TRUE(stack2.top() == 1.5);

  s21::stack<char> stack3(s21::stack<char>{'a', 'b', 'c', 'd', 'e'});
  EXPECT_TRUE(stack3.size() == 5);
  EXPECT_TRUE(stack3.empty() == false);
  EXPECT_TRUE(stack3.top() == 'a');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::stack<std::string> stack4(s21::stack<std::string>{str1, str2, str3});
  EXPECT_TRUE(stack4.size() == 3);
  EXPECT_TRUE(stack4.empty() == false);
  EXPECT_TRUE(stack4.top() == str1);
}

// operator=(stack &&other) test
TEST(StackTest, StackTestOperatorEq) {
  s21::stack<int> stack1 = s21::stack<int>{1, 2, 3, 4, 5};
  EXPECT_TRUE(stack1.size() == 5);
  EXPECT_TRUE(stack1.empty() == false);
  EXPECT_TRUE(stack1.top() == 1);

  s21::stack<double> stack2 =
      s21::stack<double>{1.5, 2.123, 3.987765, 4.0001, 5.000001};
  EXPECT_TRUE(stack2.size() == 5);
  EXPECT_TRUE(stack2.empty() == false);
  EXPECT_TRUE(stack2.top() == 1.5);

  s21::stack<char> stack3 = s21::stack<char>{'a', 'b', 'c', 'd', 'e'};
  EXPECT_TRUE(stack3.size() == 5);
  EXPECT_TRUE(stack3.empty() == false);
  EXPECT_TRUE(stack3.top() == 'a');

  std::string str1 = "abc", str2 = "def", str3 = "ghj";
  s21::stack<std::string> stack4 = s21::stack<std::string>{str1, str2, str3};
  EXPECT_TRUE(stack4.size() == 3);
  EXPECT_TRUE(stack4.empty() == false);
  EXPECT_TRUE(stack4.top() == str1);
}

// push(const_reference value) test
TEST(StackTest, StackTestPush1) {
  s21::stack<int> int_stack;

  int_stack.push(1);
  EXPECT_TRUE(int_stack.top() == 1);
  EXPECT_TRUE(int_stack.size() == 1);

  int_stack.push(2);
  EXPECT_TRUE(int_stack.top() == 2);
  EXPECT_TRUE(int_stack.size() == 2);

  int_stack.push(3);
  EXPECT_TRUE(int_stack.top() == 3);
  EXPECT_TRUE(int_stack.size() == 3);

  EXPECT_TRUE(int_stack.empty() == false);
}

TEST(StackTest, StackTestPush2) {
  s21::stack<double> double_stack;

  double_stack.push(1.0000001);
  EXPECT_TRUE(double_stack.top() == 1.0000001);
  EXPECT_TRUE(double_stack.size() == 1);

  double_stack.push(3.1415926);
  EXPECT_TRUE(double_stack.top() == 3.1415926);
  EXPECT_TRUE(double_stack.size() == 2);

  double_stack.push(5.0);
  EXPECT_TRUE(double_stack.top() == 5.0);
  EXPECT_TRUE(double_stack.size() == 3);

  EXPECT_TRUE(double_stack.empty() == false);
}

TEST(StackTest, StackTestPush3) {
  s21::stack<char> char_stack;

  char_stack.push('a');
  EXPECT_TRUE(char_stack.top() == 'a');
  EXPECT_TRUE(char_stack.size() == 1);

  char_stack.push('x');
  EXPECT_TRUE(char_stack.top() == 'x');
  EXPECT_TRUE(char_stack.size() == 2);

  char_stack.push(127);
  EXPECT_TRUE(char_stack.top() == 127);
  EXPECT_TRUE(char_stack.size() == 3);

  EXPECT_TRUE(char_stack.empty() == false);
}

TEST(StackTest, StackTestPush4) {
  s21::stack<std::string> string_stack;

  string_stack.push("some_string1");
  EXPECT_TRUE(string_stack.top() == "some_string1");
  EXPECT_TRUE(string_stack.size() == 1);

  string_stack.push("some_string2");
  EXPECT_TRUE(string_stack.top() == "some_string2");
  EXPECT_TRUE(string_stack.size() == 2);

  string_stack.push("");
  EXPECT_TRUE(string_stack.top() == "");
  EXPECT_TRUE(string_stack.size() == 3);

  EXPECT_TRUE(string_stack.empty() == false);
}

// pop() test
TEST(StackTest, StackTestPop1) {
  std::initializer_list<int> items = {1, 2, 3};
  s21::stack<int> int_stack(items);

  int_stack.pop();
  EXPECT_TRUE(int_stack.size() == 2);
  EXPECT_TRUE(int_stack.top() == 2);

  int_stack.push(4);
  int_stack.push(5);
  int_stack.pop();
  EXPECT_TRUE(int_stack.size() == 3);
  EXPECT_TRUE(int_stack.top() == 4);

  while (int_stack.size()) int_stack.pop();
  EXPECT_TRUE(int_stack.size() == 0);
  EXPECT_ANY_THROW(int_stack.top());
}

TEST(StackTest, StackTestPop2) {
  std::initializer_list<double> items = {1.00001, 2.5, 3.14};
  s21::stack<double> double_stack(items);

  double_stack.pop();
  EXPECT_TRUE(double_stack.size() == 2);
  EXPECT_TRUE(double_stack.top() == 2.5);

  double_stack.push(4.44);
  double_stack.push(5.505);
  double_stack.pop();
  EXPECT_TRUE(double_stack.size() == 3);
  EXPECT_TRUE(double_stack.top() == 4.44);

  while (double_stack.size()) double_stack.pop();
  EXPECT_TRUE(double_stack.size() == 0);
  EXPECT_ANY_THROW(double_stack.top());
}

TEST(StackTest, StackTestPop3) {
  std::initializer_list<char> items = {'z', '[', ')'};
  s21::stack<char> char_stack(items);

  char_stack.pop();
  EXPECT_TRUE(char_stack.size() == 2);
  EXPECT_TRUE(char_stack.top() == '[');

  char_stack.push('@');
  char_stack.push('o');
  char_stack.pop();
  EXPECT_TRUE(char_stack.size() == 3);
  EXPECT_TRUE(char_stack.top() == '@');

  while (char_stack.size()) char_stack.pop();
  EXPECT_TRUE(char_stack.size() == 0);
  EXPECT_ANY_THROW(char_stack.top());
}

TEST(StackTest, StackTestPop4) {
  std::string str1 = "some_string1", str2 = "some_string2", str3 = "";
  std::initializer_list<std::string> items = {str1, str2, str3};
  s21::stack<std::string> str_stack(items);

  str_stack.pop();
  EXPECT_TRUE(str_stack.size() == 2);
  EXPECT_TRUE(str_stack.top() == str2);

  str_stack.push("push front");
  str_stack.push("pop front");
  str_stack.pop();
  EXPECT_TRUE(str_stack.size() == 3);
  EXPECT_TRUE(str_stack.top() == "push front");

  while (str_stack.size()) str_stack.pop();
  EXPECT_TRUE(str_stack.size() == 0);
  EXPECT_ANY_THROW(str_stack.top());
}

// swap(stack &other) test
TEST(StackTest, StackTestSwap1) {
  s21::stack<int> stack1{1, 2, 3}, stack2{4, 5, 6, 7};

  stack1.swap(stack2);

  EXPECT_TRUE(stack1.size() == 4);
  EXPECT_TRUE(stack2.size() == 3);

  EXPECT_TRUE(stack1.top() == 4);
  EXPECT_TRUE(stack2.top() == 1);

  stack1.pop();
  EXPECT_TRUE(stack1.top() == 5);

  stack2.pop();
  EXPECT_TRUE(stack2.top() == 2);
}

TEST(StackTest, StackTestSwap2) {
  std::string str1 = "123", str2 = "", str3 = "\nsome text\n", str4 = "four";
  s21::stack<std::string> stack1{str1, str2}, stack2{str3, str4};

  stack1.swap(stack2);

  EXPECT_TRUE(stack1.size() == 2);
  EXPECT_TRUE(stack2.size() == 2);

  EXPECT_TRUE(stack1.top() == "\nsome text\n");
  EXPECT_TRUE(stack2.top() == "123");

  stack1.pop();
  EXPECT_TRUE(stack1.top() == "four");

  stack2.pop();
  EXPECT_TRUE(stack2.top() == "");
}