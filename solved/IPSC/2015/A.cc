using namespace std;
#include <bits/stdc++.h>

long long f(const string &s, int mask, int t) {
  deque<int> q;
  for (int i = 0; i < s.size(); ++i) {
    if (((mask >> i) & 1) == t)
      q.push_back(s[i] - '0');
  }
  sort(q.rbegin(), q.rend());
  long long ans = 0;
  for (int i = 0; i < q.size(); ++i) {
    ans *= 10;
    ans += q[i];
  }
  return ans;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    string line;
    cin >> line;
    int top = (1 << line.size()) - 1;
    long long best = 0;
    for (int mask = 1; mask < top; ++mask) {
      long long a = f(line, mask, 0);
      long long b = f(line, mask, 1);
      best = max(best, a + b);
    }
    cout << best << endl;
  }
  return 0;
}
