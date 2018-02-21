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

int val[100];

int holes(int x) {
  if (x == 0) return val[x];
  int ans = 0;
  while (x > 0) {
    ans += val[x % 10];
    x /= 10;
  }
  return ans;
}

void solve() {
  val[6] = 1;
  val[0] = 1;
  val[9] = 1;
  val[8] = 2;
  int a, b; read(a, b);

  int ans = a, best = 0;
  for (int i = a; i <= b; i++) {
    if (holes(i) > best) {
      best = holes(i);
      ans = i;
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

