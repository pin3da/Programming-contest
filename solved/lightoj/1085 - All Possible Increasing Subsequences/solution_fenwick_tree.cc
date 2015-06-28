using namespace std;
#include <bits/stdc++.h>

typedef unsigned int u32;
#define BUF 524288
struct Reader {
  char buf[BUF]; char b; int bi, bz;
  Reader() { bi=bz=0; read(); }
  void read() {
    if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
    b = bz ? buf[bi++] : 0; }
  void skip() { while (b > 0 && b <= 32) read(); }
  u32 next_u32() {
    u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
  int next_int() {
    int v = 0; bool s = false;
    skip(); if (b == '-') { s = true; read(); }
    for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
  char next_char() { skip(); char c = b; read(); return c; }
};

const int N = 100000 + 10;
const int mod = 1000000007;

struct FenwickTree{
  long long v[N];
  int maxSize;

  FenwickTree() {}
  void init(int _maxSize) {
    maxSize = _maxSize+1;
    memset(v, 0, sizeof v);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] = (v[where] + what) % mod;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum = (sum + v[where]) % mod;
    }
    return sum % mod;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};

struct entry{
  int val, index;
  entry () {}
  entry(int a, int b) : val(a), index(b) {}
  bool operator < (const entry &o) const {
    if (val == o.val)
      return index > o.index;
    return val < o.val;
  }
};

FenwickTree tree;

Reader rd;

void solve() {
  int n, t;
  n = rd.next_u32();
  // cin >> n;
  tree.init(n);
  vector<entry> a(n);
  for (int i = 0; i < n; ++i) {
    t = rd.next_int();
    // cin >> t;
    a[i] = entry(t, i);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i)
    tree.add(a[i].index, tree.query(a[i].index) + 1);
  printf("%lld\n", tree.query(n) % mod);
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int tc = rd.next_u32();
  // cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
