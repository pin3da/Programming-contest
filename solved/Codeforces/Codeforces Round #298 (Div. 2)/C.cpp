// http://codeforces.com/contest/534/problem/C

using namespace std;
#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b;
  while (cin >> a >> b) {
    long long sum = 0;
    vector<long long> nums(a);
    for (auto &i : nums) {
      cin >> i;
      sum += i;
    }

    for (int i = 0; i < a; ++i) {
      long long mmin = max(1LL, b - (sum - nums[i]));
      long long mmax = min(nums[i], b - a + 1LL);
      if (i) cout << " ";
      cout << nums[i] - (mmax - mmin + 1);
    }
    cout << endl;
  }
  return 0;
}
