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

const int MN = 1e6 + 100;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> A(MN), B(MN);
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    A[t]++;
  }

  for (int i = 0; i < m; i++) {
    int t; cin >> t;
    B[t]++;
  }

  long long ans = 0;
  for (long long i = 1; i < MN; i++) {
    long long j = i;
    while (j < MN) {
      ans += (j / i) * A[j] * B[i];
      j += i;
    }
  }
  cout << ans << endl;
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

