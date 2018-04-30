#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}
template <typename H, typename... T> void read(vector<H> &h, T&... t) { for (auto &i : h) read(i); read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif

struct st {
  long long h, d;
  st() {}
  bool operator < (const st &o) const {
    return (h - d) > (o.h - o.d);
  }
};


const int MN = 3 * 1e5 + 100;
long long h[MN], d[MN];
int n;

long long dp[MN][22];

long long go(int id, int a, int b) {
  if (id == n) return 0;
  if (dp[id][a] != -1) return dp[id][a];
  long long best = d[id] + go(id + 1, a, b);
  long long cur = 2;
  for (int i = 1; i <= a; i++) {
    best = max(best, h[id] * cur + go(id + 1, a - i, b - 1));
    cur <<= 1;
  }
  return dp[id][a] = best;
}

long long test(vector<st> all, long long b) {
  int n = all.size();
  sort(all.begin(), all.end());
  for (int i = 0; i < n && b; i++) {
    all[i].d = max(all[i].d, all[i].h);
    b--;
  }
  long long total = 0;
  for (auto it : all) {
    total += it.d;
  }
  return total;
}

void solve() {
  cin >> n;
  long long a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> d[i];
  }
  vector<st> all(n);
  for (int i = 0; i < n; i++) {
    all[i].h = h[i];
    all[i].d = d[i];
  }
  long long best = test(all, b);

  memset(dp, -1, sizeof dp);
  a = min(a, b);
  int id = 0, aa = a, bb = b;
  go(0, a, b);
  debug(aa);
  while (id < n) {
    if (go(id, aa, bb) == (d[id] + go(id + 1, aa, bb))) {
      id++;
    } else {
      long long cur = 2;
      for (int i = 1; i <= a; i++) {
        if ((h[id] * cur + go(id + 1, aa - i, bb - 1)) == go(id, aa, bb)) {
          d[id] = h[id] * cur;
          h[id] *= cur;
          id++;
          aa -= i;
          bb -= 1;
          break;
        }
        cur <<= 1;
      }
    }
  }

  debug(aa);

  for (int i = 0; i < n; i++) {
    all[i].h = h[i];
    all[i].d = d[i];
  }

  b -= a;
  sort(all.begin(), all.end());
  for (int i = 0; i < n && b; i++) {
    all[i].d = max(all[i].d, all[i].h);
    b--;
  }
  long long total = 0;
  for (auto it : all) {
    total += it.d;
  }
  cout << max(best, total) << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

