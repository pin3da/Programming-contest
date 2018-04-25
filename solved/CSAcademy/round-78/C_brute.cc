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

int banned[11];

bool valid(int x) {
  string s = to_string(x);
  for (auto it : s) {
    if (banned[(it - '0')])
      return false;
  }
  return true;
}

void solve() {
  for (int i = 0; i < 10; i++) {
    cin >> banned[i];
  }
  int top; cin >> top;
  int ans = 0;
  for (int i = 0; i < top; i++) {
    if (valid(i)) ans++;
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

