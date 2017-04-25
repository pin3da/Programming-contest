// http://codeforces.com/contest/730/problem/G

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define foreach(it, x) for (typeof (x).begin() it = x.begin(); it != x.end(); ++it)

struct inter { // [b, e)
  long long b, e;
  inter(long long x, long long y): b(x), e(y) {}
  bool operator < (const inter &o) const {
    if (b == o.b) return e < o.e;
    return b < o.b;
  }
};


void replace(set<inter> &av, inter cur, int s, int d) {
  long long x = cur.b, y = s;
  if (y > x) av.insert(inter(x, y));
  x = s + d, y = cur.e;
  if (y > s) av.insert(inter(x, y));
  x = cur.b, y = cur.e;
  av.erase(inter(x, y));
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  set<inter> av;
  av.insert(inter(1, 1LL << 50));

  int n; cin >> n;
  vector<int> start(n), end(n);
  for (int i = 0; i < n; ++i) {
    long long s, d;
    cin >> s >> d;
    int can = 0;
    foreach(cur, av) {
      if (cur-> b <= s && cur-> e > s) {
        if (cur-> e - s >= d) {
          replace(av, *cur, s, d);
          can = 1;
          start[i] = s;
          end[i] = s + d - 1;
          break;
        }
      }
    }

    if (!can) {
      foreach(cur, av) {
        if ((cur-> e - cur-> b) >= d) {
          replace(av, *cur, cur-> b, d);
          start[i] = cur-> b;
          end[i] = cur-> b + d - 1;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << start[i] << ' ' << end[i] << endl;
  }
  return 0;
}
