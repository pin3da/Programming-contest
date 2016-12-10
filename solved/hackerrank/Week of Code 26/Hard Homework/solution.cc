#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

typedef long double ld;
const int MN = 3000000 + 1000;
ld s[MN];

ld fun(int a, int b, int c) {
  return s[a] + s[b] + s[c];
}

int dx[] = {1, 1, -1, -1, 0, 0};
int dy[] = {-1, 0, 1, 0, -1, 1};
int dz[] = {0, -1, 0, 1, 1, -1};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  srand(time(0));
  int n; cin >> n;
  for (int i = 1; i <= n; ++i)
    s[i] = sin(i);

  ld best = 0;
  for (int iters = 4975341; iters >= 0; --iters) {
    int a = (random() % (n - 2)) + 1;
    int b = (random() % (n - a - 1)) + 1;
    int c = n - a - b;
    while (true) {
      ld cur = fun(a, b, c);
      int id_best = -1;
      for (int i = 0; i < 6; ++i) {
        int x = a + dx[i],
        y = b + dy[i],
        z = c + dz[i];
        if (x > 0 && x < n && y > 0 &&
            y < n && z > 0 && z < n) {
          if (fun(x, y, z) > cur) {
            cur = fun(x, y, z);
            id_best = i;
          }
        }
      }
      if (id_best == -1) break;
      a += dx[id_best];
      b += dy[id_best];
      c += dz[id_best];
    }
    best = max(best, fun(a, b, c));
  }
  cout << fixed << setprecision(9) << best + 1e-15 << endl;

  return 0;
}
