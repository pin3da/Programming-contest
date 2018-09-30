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

int count(const string &b, const vector<int> &frec, const int l) {
  int len = b.size();
  vector<int> cur(30);
  string s = b.substr(0, l);
  for (auto c : s) cur[c - 'A']++;
  if (cur == frec) return true;
  for (int i = 0; i + l < len; i++) {
    cur[b[i] - 'A']--;
    cur[b[i + l] - 'A']++;
    if (cur == frec) return true;
  }
  return false;
}

void solve() {
  int len; cin >> len;
  string a, b; cin >> a >> b;

  long long ans = 0;
  for (int l = 1; l <= len; l++) {
    vector<int> frec(30);
    string s = a.substr(0, l);
    for (auto c : s) frec[c - 'A']++;
    ans += count(b, frec, l);
    for (int i = 0; i + l < len; i++) {
      frec[a[i] - 'A']--;
      frec[a[i + l] - 'A']++;
      ans += count(b, frec, l);
    }
  }
  cout << ans << endl;
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

