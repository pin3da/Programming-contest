#include "solution.cc"

#include <iostream>
#include <cassert>

int main() {
  Solution sol;

  vector<int> input = {0, 1, 3, 5, 6, 8, 12, 17};
  assert(sol.canCross(input));
  input = {0,1,2,3,4,8,9,11};
  assert(sol.canCross(input) == false);
  return 0;
}
