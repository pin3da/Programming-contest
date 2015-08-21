using namespace std;
#include <bits/stdc++.h>
#define foreach(x, b) for (typeof (b).begin() x = (b).begin(); x != (b).end(); ++x)


typedef unsigned int u32;
struct Reader {
    char b; Reader() { read(); }
    void read() { int r = fgetc_unlocked(stdin); b = r == EOF ? 0 : r; }
    void skip() { while (b > 0 && b <= 32) read(); }
    u32 next_u32() {
        u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
};

Reader r;

void solve() {
  int n = r.next_u32();
  map<int, vector<int> > ev;
  int s, t;
  for (int i = 0; i < n; ++i) {
    s = r.next_u32(); t = r.next_u32();
    if (!ev.count(s))
      ev[s] = vector<int> (2, 0);

    if (!ev.count(t))
      ev[t] = vector<int> (2, 0);

    ev[s][0]++;
    ev[t][1]++;
  }

  int best = 0, open = 0;
  foreach(it, ev) {
    open += it->second[0];
    best = max(best, open);
    open -= it->second[1];
  }
  printf("%d\n", best);
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc = r.next_u32();
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
