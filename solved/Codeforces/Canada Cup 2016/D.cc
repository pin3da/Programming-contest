#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 3 * 1e5 + 100;

struct team {
  long long b, w;
  int id;
  team() {}
  team(long long x, long long y) : b(x), w(y) {}
  bool operator < (const team &o) const {
    if (b == o.b) {
      if (w == o.w)
        return id < o.id;
      return w < o.w;
    }
    return b > o.b;
  }
};

struct T {
  long long b, w;
  T () {}
  T(long long x, long long y) : b(x), w(y) {}
  bool operator < (const T &o) const {
    return (w - b) > (o.w - o.b);
  }
};

team a[MN];
int n;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  while (cin >> n) {
    team mio(0, 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].b >> a[i].w;
      a[i].id = i;
      if (i == 0) {
        mio = a[i];
      }
    }
    if (n == 1) {
      cout << 1 << endl;
      continue;
    }

    sort(a, a + n);
    int best = n;
    for (int i = 0; i < n; ++i) {
      if (a[i].b == mio.b) {
        best = i;
        break;
      }
    }

    priority_queue<T> q;
    for (int i = 0; i < best; ++i) {
      q.push(T(a[i].b, a[i].w));
    }

    int place = best;
    int rem = 1;
    while (!q.empty()) {
      T cur = q.top(); q.pop();
      long long need = cur.w - cur.b + 1;
      if (mio.b - need >= 0) {
        mio.b -= need;
        rem++;
        while (place < n && a[place].b > mio.b) {
          if (a[place].id != 0)
            q.push(T(a[place].b, a[place].w));
          place++;
        }
        best = min(best, place - rem);
      }
    }

    cout << best + 1 << endl;
  }
  return 0;
}
