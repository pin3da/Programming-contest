using namespace std;
#include <bits/stdc++.h>

typedef unsigned int u32;
struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar_unlocked(); }
  void skip() { while (b >= 0 && b <= 32) read(); }
  u32 next_u32() {
    u32 v = 0; for (skip(); b > 32; read()) v = 10*v+b-48; return v; }
};

Reader rd;

const int MN = 555;

struct st {
  int data[MN];
  int M[MN][15];
  int n;

  void read(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i)
      data[i] = rd.next_u32();
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = max(M[i][j - 1], M[i + q][j - 1]);
  }
  int query(int b, int e) {
    int k = log2(e - b + 1);
    return max(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};

st rmq[MN];

void solve() {
  int n = rd.next_u32(), q = rd.next_u32();
  for (int i = 0; i < n; ++i) {
    rmq[i].read(n);
    rmq[i].build();
  }

  int a, b, s;
  for (int i = 0; i < q; ++i) {
    a = rd.next_u32(); b = rd.next_u32(); s = rd.next_u32();
    a--; b--;
    int mmax = 0;
    for (int j = a; j < a + s; ++j) {
      mmax = max(mmax, rmq[j].query(b, b + s - 1));
    }
    printf("%d\n", mmax);
  }
}



int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = rd.next_u32();
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
