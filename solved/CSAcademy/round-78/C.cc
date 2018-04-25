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

string border;
int banned[11];

long long dp[20][3][3];

long long go(int pos, int top, int ban_zero) {
  if (pos == int(border.size()))
    return 1;

  if (dp[pos][top][ban_zero] != -1) {
    return dp[pos][top][ban_zero];
  }

  int end = top ? border[pos] - '0' : 9;
  long long ans = 0;
  for (int i = 0; i <= end; i++) {
    if (banned[i]) {
      if (i != 0 || (i == 0 && ban_zero)) continue;
    }
    ans += go(pos + 1, top && (i == end), ban_zero || (i != 0));
  }

  return dp[pos][top][ban_zero] = ans;
}

void solve() {
  for (int i = 0; i < 10; i++) {
    cin >> banned[i];
  }
  long long tt; cin >> tt;
  tt--;
  border = to_string(tt);
  memset(dp, -1, sizeof dp);
  cout << go(0, true, 0) - banned[0] << endl;
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

