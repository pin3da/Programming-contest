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


string vow = "aeiouy";

void solve() {
  int n; cin >> n;
  string line; cin >> line;

  char last= 'x';
  vector<char> ans;
  for (int i = line.size() - 1; i >= 0; i--) {
    if (vow.find(line[i]) == string::npos) {
      if (last != 'x') ans.push_back(last);
      ans.push_back(line[i]);
      last = 'x';
    } else {
      last = line[i];
    }
  }

  if (last != 'x') ans.push_back(last);

  reverse(ans.begin(), ans.end());
  for (auto it : ans) cout << it;
  cout << endl;
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

