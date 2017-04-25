// http://codeforces.com/contest/658/problem/B

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

struct st {
  int id, val;
  bool operator < (const st &o) const {
    return val < o.val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, q, k;
  while (cin >> n >> k >> q) {
    vector<st> t(n);
    for (auto &i : t) cin >> i.val;
    for (int i = 0; i < n; ++i) t[i].id = i + 1;

    vector<st> alive;
    int op, id;
    while (q--) {
      cin >> op >> id;
      if (op == 1) {
        alive.push_back(t[id - 1]);
        sort(alive.rbegin(), alive.rend());
        if (alive.size() > k)
          alive.pop_back();
      } else {
        int seen = false;
        for (int i = 0; i < alive.size() && !seen; ++i) {
          if (alive[i].id == id) {
            cout << "YES"  << endl;
            seen = true;
          }
        }
        if (!seen) {
          cout << "NO" << endl;
        }
      }
    }
  }
  return 0;
}
