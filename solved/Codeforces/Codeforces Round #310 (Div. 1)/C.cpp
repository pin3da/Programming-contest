// http://codeforces.com/contest/555/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct entry {
  long long x, y;
  bool operator < (const entry &o) const {
    if (x == o.x)
      return y < o.y;
    return x < o.x;
  }
};

void d_tree(set<long long> &t) {
  for (auto &i : t)
    cout << i <<  " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, q;
  cin >> n >> q;
  set<entry> seen;
  seen.insert((entry) {0, 1});
  seen.insert((entry) {n + 1, 0});
  map<long long, int> t;
  while (q--) {
    int x, y;
    char op;
    cin >> x >> y >> op;
    if (t.count(x)) {
      cout << 0 << endl;
      continue;
    }
    if (op == 'U') {
      auto cur = *seen.lower_bound((entry) {x, -1});
      if (cur.y == 1)
        t[x] = cur.x - x + t[cur.x];
      else
        t[x] = cur.x - x;
      seen.insert((entry) {x, 1});
    } else {
      auto cur = seen.lower_bound((entry) {x, -1});
      cur--;
      if (cur-> y == 0)
        t[x] = x - cur-> x + t[cur-> x];
      else
        t[x] = x - cur-> x;
      seen.insert((entry) {x, 0});
    }
    cout << t[x] << endl;
  }
  return 0;
}
