#include "solution.cc"

#include <iostream>
#include <cassert>

void test1() {
  AllOne all_one;
  all_one.inc("hello");
  all_one.inc("goodbye");
  all_one.inc("hello");
  all_one.inc("hello");
  cout << all_one.getMaxKey() << endl;
  all_one.inc("leet");
  all_one.inc("code");
  all_one.inc("leet");
  all_one.dec("hello");
  all_one.inc("leet");
  all_one.inc("code");
  // all_one.inc("code");
  cout << all_one.getMaxKey() << endl;
  cout << all_one.getMinKey() << endl;
}

void test2() {
  AllOne all_one;
  all_one.inc("hello");
  all_one.inc("hello");
  cout << all_one.getMaxKey() << endl;
  cout << all_one.getMinKey() << endl;
  all_one.inc("leet");
  cout << all_one.getMaxKey() << endl;
  cout << all_one.getMinKey() << endl;
}

void test3() {
  AllOne all_one;
  all_one.inc("hello");
  all_one.inc("hello");
  all_one.inc("world");
  all_one.inc("world");
  all_one.inc("hello");
  all_one.dec("world");

  assert("hello" ==  all_one.getMaxKey());
  assert("world" ==  all_one.getMinKey());

  all_one.inc("world");
  all_one.inc("world");
  all_one.inc("leet");

  auto ans = all_one.getMaxKey();
  assert("world" == ans || "hello" == ans);
  assert("leet" == all_one.getMinKey());
}

void test4() {
  AllOne all_one;
  all_one.inc("a");
  all_one.inc("b");
  all_one.inc("b");
  all_one.inc("b");
  all_one.inc("b");
  all_one.dec("b");
  all_one.dec("b");

  assert("b" == all_one.getMaxKey());
  assert("a" == all_one.getMinKey());

}

int main() {
  // test1();
  // test2();
  test3();
  test4();
  return 0;
}
