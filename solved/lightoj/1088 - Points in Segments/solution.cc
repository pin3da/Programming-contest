using namespace std;
#include <bits/stdc++.h>

#define BUF 524288
typedef unsigned int u32;
struct Reader {
  char buf[BUF]; char b; int bi, bz;
  Reader() { bi=bz=0; read(); }
  void read() {
    if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
    b = bz ? buf[bi++] : 0; }
  void skip() { while (b > 0 && b <= 32) read(); }
  u32 next_u32() {
    u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
  char next_char() { skip(); char c = b; read(); return c; }
};

Reader rd;

void solve() {
  int n = rd.next_u32(), q = rd.next_u32();
  // cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    a[i] = rd.next_u32();
    //cin >> a[i];

  int b, e;
  while (q--) {
    b = rd.next_u32(); e = rd.next_u32();
    // cin >> b >> e;
    printf("%d\n", upper_bound(a.begin(), a.end(), e) - lower_bound(a.begin(), a.end(), b));
  }
}
int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = rd.next_u32();
  // cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
  return 0;
}
