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

int test(multiset<int> &dist, int d1) {
  dist.erase(dist.find(d1));
  int b = *(--dist.end());
  dist.erase(--dist.end());
  int c = (b + 1) / 2;
  dist.insert(c);

  int ans = *(--dist.end());

  dist.erase(dist.find(c));
  dist.insert(b);
  dist.insert(d1);

  return ans;
}

void solve() {
  int n; cin >> n;
  vector<int> all(n);
  read(all);

  multiset<int> dist;
  for (int i = 1; i < n; i++) {
    dist.insert(all[i] - all[i - 1]);
  }

  int ans = test(dist, all[1] - all[0]);
  ans = min(ans, test(dist, all[n - 1] - all[n - 2]));

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

