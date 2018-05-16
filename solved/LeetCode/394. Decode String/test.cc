#include "./solution.cc"
#include <cassert>

int main() {
  Solution sol;
  assert(sol.decodeString("3[a]2[bc]") == "aaabcbc");
  assert(sol.decodeString("3[a2[c]]") == "accaccacc");
  assert(sol.decodeString("2[abc]3[cd]ef") == "abcabccdcdcdef");
  return 0;
}
