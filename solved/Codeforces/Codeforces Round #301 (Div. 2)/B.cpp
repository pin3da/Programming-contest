// http://codeforces.com/contest/540/problem/B

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  int k, p, x, y;
  cin >> k >> p >> x >> y;
  vector<int> b(k);
  int wrong = 0;

  int total = 0;
  for (auto &i : b) {
    cin >> i;
    if (i < y)
      wrong++;
    total += i;
  }

  if (wrong > (n >> 1)) {
    cout << -1 << endl;
    return;
  }

  int av = n - k;
  int s = (n >> 1) - wrong;
  s = min(s, av);
  av -= s;
  if (total + s + y * av > x) {
    cout << -1 << endl;
    return;
  }

  for (int i = 0; i < s; ++i) {
    if (i) cout << " ";
    cout << 1;
  }

  for (int i = 0; i < av; ++i)
    cout << " " << y;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n) solve(n);
  return 0;
}
