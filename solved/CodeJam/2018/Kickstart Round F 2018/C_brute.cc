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

set<string> all;

bool isPalindrome(const string &s) {
  for (int i = 0; i < int(s.size() / 2); i++) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

void gen(int n, int len, string cur) {
  if (cur.size() && isPalindrome(cur)) all.insert(cur);
  if (len == 0) {
    return;
  }
  for (int i = 0; i < n; i++) {
    gen(n, len - 1, cur + char('a' + i));
  }
}

void solve() {
  int n, l;
  long long k;
  cin >> n >> l >> k;
  gen(n, l, "");
  cout << endl;
  for (auto a : all) {
    cout << a << endl;
  }
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    cout << "Case #" << (i + 1) << ": ";
    solve();
  }
  return 0;
}

