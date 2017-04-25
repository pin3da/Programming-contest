// http://codeforces.com/contest/730/problem/J

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct btl {
  int a, b;
  btl () {}
  btl(int x, int y) : a(x), b(y) {}
  bool operator < (const btl &o) const {
    if (a == o.a) return b > o.b;
    return a > o.a;
  }
};


const int inf = 100000;
const int M = 10001;
const int MC = 2 * M;

int seen[123][MC];
pair<int, int> dp[123][MC + 10];

pair<int, int> go(vector<btl> &a, int i, int cap) {
  if (i == (int)a.size()) {
    if (cap < 0)
      return make_pair(inf, inf);
    return make_pair(0, 0);
  }

  if (seen[i][cap + M]) {
    return dp[i][cap + M];
  }
  seen[i][cap + M] = true;
  pair<int, int> s1(inf, inf);
  pair<int, int> t = go(a, i + 1, cap - a[i].a);
  t.second += a[i].a;
  s1 = min(s1, t);

  pair<int, int> s2 = go(a, i + 1, cap + a[i].b - a[i].a);
  s2.first++;
  return dp[i][cap + M] = min(s1, s2);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int n;
  while (cin >> n) {
    vector<btl> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i].a;

    for (int i = 0; i < n; ++i)
      cin >> a[i].b;

    pair<int, int> ans = go(a, 0, 0);
    cout << ans.first << " " << ans.second << endl;
  }

  return 0;
}
