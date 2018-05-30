#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <iostream>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

class Solution {
  long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);
    while (b > 0) {
      a %= b;
      swap(a, b);
    }
    return a;
  }

  map<pair<pair<int, int>, int>, bool> dp;

  bool go(vector<int> &a, int T, int id, int k) {
    if (id == (int)(a.size()))
        return (T == 0) && (k == 0);
    if (k == 0)
      return T == 0;

    pair<pair<int, int>, int> state = make_pair(make_pair(T, id), k);
    if (dp.count(state))
      return dp[state];

    bool can = go(a, T, id + 1, k);
    if (a[id] <= T)
      can |= go(a, T - a[id], id + 1, k - 1);
    return dp[state] = can;
  }

  public:
    bool splitArraySameAverage(vector<int>& A) {
      long long num = accumulate(A.begin(), A.end(), 0LL);
      long long den = A.size();
      long long g = gcd(num, den);
      num /= g;
      den /= g;

      int target = num;
      for (int i = den; i < int(A.size()); i += den) {
        dp.clear();
        // debug(target);
        // debug(i);
        if (go(A, target, 0, i))
          return true;
        target += num;
      }
      return false;
    }
};

int main() {

  Solution sol;
  vector<int> a = {18, 10, 5, 3};
  cout << sol.splitArraySameAverage(a) << endl;

  return 0;
}
