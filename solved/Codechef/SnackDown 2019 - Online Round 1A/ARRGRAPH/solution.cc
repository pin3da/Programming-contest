#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct Dsu {
  vector<int> p;

  Dsu(int n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

  int Join(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return 0;
    p[px] = py;
    return 1;
  }
};

bool connected(const vector<int>& a) {
  int n = a.size();
  Dsu dsu(n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (__gcd(a[i], a[j]) == 1) dsu.Join(i, j);

  set<int> r;
  for (int i = 0; i < n; i++) r.insert(dsu.Find(i));
  return r.size() == 1;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (connected(a)) {
    cout << 0 << endl;
  } else {
    int ans = -1;
    for (int i = 2; i <= 50; i++) {
      int pos = true;
      for (int j = 0; j < n; j++) {
        pos &= (__gcd(a[j], i) == 1);
      }
      if (pos) {
        ans = i;
        break;
      }
    }
    a[0] = ans;
    assert(ans != -1);
    cout << 1 << endl;
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
