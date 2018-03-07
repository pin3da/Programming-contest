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

long long get(vector<long long> &acc, int i, int j) {
  if (i > j) swap(i, j);
  j--;
  long long ans = acc[j];
  if (i) ans -= acc[i - 1];
  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  read(a);

  long long total = accumulate(a.begin(), a.end(), 0);

  vector<long long> acc(n);
  for (int i = 0; i < n; i++) {
    acc[i] = a[i];
    if (i) acc[i] += acc[i - 1];
  }


  long long best = 1e10, ans = 0;
  for (int i = 0; i < n; i++) {
    long long cur = 0;
    for (int j = 0; j < n; j++) {
      long long a = get(acc, i, j);
      cur = max(cur, min(a, total - a));
    }
    debug(i, cur);
    if (cur < best) {
      best = cur;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
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

