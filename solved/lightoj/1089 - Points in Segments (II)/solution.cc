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
};

const int MN = 50000 + 50;
struct ht {
  int _s[(MN + 10) >> 5];
  int len;
  void clear() {
    len = 0;
    memset(_s, 0, sizeof _s);
  }
  void insert(int id) {
    len++;
    _s[id >> 5] |= (1LL << (id & 31));
  }
  void erase(int id) {
    len--;
    _s[id >> 5] ^= (1LL << (id & 31));
  }

  size_t size() {
    return len;
  }

  bool count(int id) {
    return _s[id >> 5] & (1LL << (id & 31));
  }
};


struct entry {
  int x, type, idx;
  entry() {}
  entry(int a, int b) : x(a), type(b), idx(0) {}
  entry(int a, int b, int c) : x(a), type(b), idx(c) {}
  bool operator < (const entry &o) const {
    if (x == o.x)
      return type < o.type;
    return x < o.x;
  }
};

enum type {open, point, close};

Reader rd;
ht alive;
void solve() {
  alive.clear();
  int n = rd.next_u32(), q = rd.next_u32();
  // cin >> n >> q;
  int b, e;
  vector<entry> events;
  for (int i = 0; i < n; ++i) {
    b = rd.next_u32(); e = rd.next_u32();
    // cin >> b >> e;
    events.push_back(entry(b, open, i));
    events.push_back(entry(e, close, i));
  }

  for (int i = 0; i < q; ++i) {
    b = rd.next_u32();
    // cin >> b;
    events.push_back(entry(b, point, i));
  }

  sort(events.begin(), events.end());
  vector<int> ans(q);
  // set<int> alive;
  for (int i = 0; i < events.size(); ++i) {
    entry cur = events[i];
    // cout << "type : " << cur.type << " at : " << cur.x << " and id : " << cur.idx << " - ";
    // cout << "alive " << alive.size() << endl;
    if (cur.type == open)
      alive.insert(cur.idx);
    else if (cur.type == point)
      ans[cur.idx] = alive.size();
    else
      alive.erase(cur.idx);
  }
  for (int i = 0; i < ans.size(); ++i)
    printf("%d\n", ans[i]);
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
