#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct line {
  long long m, b;
  line (long long a, long long c) : m(a), b(c) {}
  long long eval(long long x) {
    return m * x + b;
  }
};

long double inter(line a, line b) {
  long double den = a.m - b.m;
  long double num = b.b - a.b;
  return num / den;
}

struct convex_hull_trick {
  vector<line> ch;
  int idx; // id of last "best" in query
  convex_hull_trick() {
    idx = 0;
  }

  void add(line cur) {
    // new line's slope is less than all the previous
    while (ch.size() > 1 &&
       (inter(cur, ch[ch.size() - 2]) >= inter(cur, ch[ch.size() - 1]))) {
        // f(x) is better [inter(ch.back(), cur), inf)
        ch.pop_back();
    }

    ch.push_back(cur);
  }

  long long query(long long x) {
    // current x is greater than all the previous x, if that is not the case
    // we can make binary search.
    idx = min<int>(idx, ch.size() - 1);
    while (idx + 1 < (int)ch.size() && ch[idx + 1].eval(x) <= ch[idx].eval(x))
      idx++;

    return ch[idx].eval(x);
  }
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;

  convex_hull_trick dp;
  vector<long long> ans(n);
  ans[0] = b[0];
  dp.add(line(b[0], 0));

  for (int i = 1; i < n; ++i) {
    ans[i] = dp.query(a[i]);
    dp.add(line(b[i], ans[i]));
  }
  cout << ans[n - 1] << endl;

  return 0;
}
