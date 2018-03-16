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

int get(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';
  return c - 'A' + 10;
}

void solve() {
  string line;
  cin >> line;
  int mmax = 2;
  for (auto c : line)
    mmax = max(mmax, get(c) + 1);

  for (int base = mmax; base <= 36; base++) {
    int mod = base - 1;
    int cur = 0;
    for (auto c : line) {
      cur = (cur * base) % mod;
      cur = (cur + get(c)) % mod;
    }
    if (cur == 0) {
      cout << base << endl;
      return;
    }
  }
  cout << "No solution." << endl;
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

