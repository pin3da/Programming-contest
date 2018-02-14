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


void solve() {
  int n; cin >> n;

  if (n > 2 * 18) {
    cout << -1 << endl;
    return;
  }

  while (n >= 2) {
    cout << 8;
    n -= 2;
  }

  if (n)
    cout << 9;

  cout << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
//   int tc; cin >> tc;
//  while (tc--)
    solve();
  return 0;
}

