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


long long get(vector<long long> &a, int b, int e) {
  long long ans = a[e];
  if (b) return ans - a[b - 1];
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> all(n);
  read(all);
  vector<long long> awake(n);
  read(awake);

  vector<long long> sleep(n);
  for (int i = 0; i < n; i++) {
    sleep[i] = all[i] * (awake[i]);
  }

  for (int i = 1; i < n; i++) {
    all[i] += all[i -1];
    sleep[i] += sleep[i -1];
  }

  long long total = sleep[n - 1];
  long long ans = 0;
  for (int i = 0; i + k <= n; i++) {
    long long cur = total - get(sleep, i, i + k -1) + get(all, i, i + k - 1);
    ans = max(ans, cur);
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

