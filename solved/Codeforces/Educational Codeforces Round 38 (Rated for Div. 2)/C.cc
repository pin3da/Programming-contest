#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
void read() {}
template <typename H, typename... T> void read(H &h, T&... t) { cin >> h; read(t...) ;}

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


const long long MN = 1e10;

bool test(long long b, long long n, long long m) {
  n /= m;
  return n * n >= b;
}

void solve() {
  vector<long long> sq;
  map<long long, int> inv;
  for (long long i = 1; i * i <= MN; i++) {
    sq.emplace_back(i * i);
    inv[i * i] = i;
  }
  int t; cin >> t;

  while (t--) {
    long long x; cin >> x;

    vector<pair<long long, long long>> ans;


    for (int i = 0; i < int(sq.size()); i++) {
      long long b = sq[i] - x;

      if (b < 0 || inv.count(b) == 0) continue;


      long long n = i + 1;
      if (b == 1) {
        ans.emplace_back(n, n);
        break;
      }

      long long lo = 1, hi = n - 1;
      while (lo < hi) {
        long long mid = (lo + hi + 1) >> 1;
        if (test(b, n , mid)) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }

      long long t = n / lo;
      if (t * t == b) {
        ans.emplace_back(n, lo);
        break;
      }
    }

    if (ans.size() == 0) {
      cout << -1 << endl;
    } else {
      cout << ans[0].first << " " << ans[0].second << endl;
    }
  }
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

