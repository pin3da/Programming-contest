// http://codeforces.com/contest/552/problem/C

using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

typedef unsigned long long ull;
ull w, m;

bool go(vector<ull> &n, int i, long long sum) {
  if (sum == m)
    return true;
  if (i == n.size())
    return false;
  return (go(n, i + 1, sum + n[i]) || go(n, i + 1, sum - n[i]) || go(n, i + 1, sum));
}

int main() {
  cin >> w >> m;
  if (w == 2 || w == 3) {
    cout << "YES" << endl;
    return 0;
  }
  vector<ull> n;
  ull cur = 1;
  for (int i = 0; cur <= w * m && n.size() < 32; ++i) {
    n.push_back(cur);
    cur *= w;
  }

  bool ans = go(n, 0, 0);
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}