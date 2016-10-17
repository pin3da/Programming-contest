#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 200002;

pair<long long, int> a[MN];
long long b[MN];

struct st {
  long long cap, cost;
  int id;

  st () {}
  st (long long a, long long b, int c) : cap(a), cost(b), id(c) {}
  bool operator < (const st &o) const {
    if (cap == o.cap) {
      if (cost == o.cost)
        return id < o.id;
      return cost < o.cost;
    }
    return cap > o.cap;
  }
};

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#endif

  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }

    for (int i = 0; i < m; ++i)
      cin >> b[i];

    sort(a, a + n);
    reverse(a, a + n);

    set<st> s;
    for (int i = 0; i < m; ++i) {
      s.insert(st(b[i], 0, i));
    }


    long long c = 0, u = 0;
    vector<long long> ans(m);
    vector<int> ansb(n);

    for (int i = 0; i < n;) {
      if (s.size() == 0) break;
      st t = *s.begin();
      if (a[i].first > t.cap) {
        i++;
        continue;
      }
      if (a[i].first == t.cap) {
        c++;
        u += t.cost;
        ans[t.id] = t.cost;
        ansb[a[i].second] = t.id + 1;
        s.erase(s.begin());
        i++;
      } else { // cap > a[i]
        s.erase(s.begin());
        if (t.cap > 1)
          s.insert(st((t.cap + 1) / 2, t.cost + 1, t.id));
      }
    }
    cout << c << ' ' << u << endl;
    for (int i = 0; i < m; ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << ansb[i];
    }
    cout << endl;
  }

  return 0;
}
