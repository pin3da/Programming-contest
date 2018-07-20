#include <vector>
#include <deque>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  vector<int> all;

  pair<int, int> makePalindrome(int i) {
    string right = to_string(i);
    string left = right;
    reverse(left.begin(), left.end());
    return {stoi(right + left), stoi(right.substr(0, right.size() - 1) + left)};
  }

  bool isPrime(int N) {
    if (N < 2) return false;
    for (int i = 2; i * i <= N; i++) {
      if ((N % i) == 0) return false;
    }
    return true;
  }

  public:
  int primePalindrome(int N) {
    int top = min<int>(20001, 10 * ceil(sqrt(N)));
    for (int i = 1; i <= top; i++) {
      auto nums = makePalindrome(i);
      if (nums.second >= N && isPrime(nums.second)) all.emplace_back(nums.second);
      if (nums.first >= N && isPrime(nums.first)) all.emplace_back(nums.first);
    }
    sort(all.begin(), all.end());
    return *lower_bound(all.begin(), all.end(), N);
  }
};

int main () {
  Solution sol;
  cout << sol.primePalindrome(7256528) << endl;
  return 0;
}
