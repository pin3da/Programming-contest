using namespace std;
#include <bits/stdc++.h>


typedef unsigned int u32;
typedef long long i64;
// I/O
#define BUF 65536
struct Reader {
  char buf[BUF]; char b; int bi, bz;
  Reader() { bi=bz=0; read(); }
  void read() {
    if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
    b = bz ? buf[bi++] : 0; }
  void skip() { while (b > 0 && b <= 32) read(); }
  u32 nextU32() {
    u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
};


void solve(Reader &in) {
  int n = in.nextU32(), q =  in.nextU32();
  vector<long long> data(n);
  for (int i = 0; i < n; ++i)
    data[i] = in.nextU32();

  long long pos = 0, neg = 0;

  for (int i = 0; i < n; ++i)
    pos += data[i] * (n - i - 1);

  for (int i = 1; i < n; ++i)
    neg += i * data[i];

  int op, x, v;
  for (int i = 0; i < q; ++i) {
    op = in.nextU32();
    if (op)
      printf("%lld\n",  pos - neg);
    else {
      x = in.nextU32();
      v = in.nextU32();
      pos -= data[x] * (n - x - 1);
      neg -= x * data[x];
      data[x] = v;
      pos += data[x] * (n - x - 1);
      neg += x * data[x];
    }
  }
}

int main() {

  Reader in;
  int t = in.nextU32();
  for (int i = 0; i < t; ++i) {
    printf("Case %d:\n", (i + 1));
    solve(in);
  }
  return 0;
}
