#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int perm[4];
int side;

struct card {
  int n, s;
  card() {}
  card(int a, int b) : n(a), s(b) {}
  bool operator < (const card &o) const {
    if (s == o.s) {
      return (n < o.n) ^ ((side >> s) & 1);
    }
    return perm[s] < perm[o.s];
  }
};

int f(char c) {
  if (c >= '0' && c <= '9' ) return c - '0';
  if (c == 'T') return 10;
  if (c == 'J') return 11;
  if (c == 'Q') return 12;
  if (c == 'K') return 13;
  return 14;
}

int g(char c) {
  if (c == 's') return 0;
  if (c == 'h') return 1;
  if (c == 'd') return 2;
  return 3;
}


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    vector<card> a(n);
    for (int i = 0; i < n; ++i) {
      string c; cin >> c;
      a[i].n = f(c[0]);
      a[i].s = g(c[1]);
    }
    int best = n * n * n;
    for (int i = 0; i < 4; ++i)
      perm[i] = i;

    do {
      for (int i = 0; i < (1 << 4); ++i) {
        side = i;
        vector<int> len(n + 10);
        for (int j = 0; j < n; ++j) {
          len[j] = 1;
          for (int k = 0; k < j; ++k)
            if (a[j] < a[k])
              len[j] = max(len[j], len[k] + 1);
          best = min(best, n - len[j]);
        }
      }
    } while (next_permutation(perm, perm + 4));
    cout << best << endl;
  }
  return 0;
}
