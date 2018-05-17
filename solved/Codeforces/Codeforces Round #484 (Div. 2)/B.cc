#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int n;
  cin >> n;
  set<pair<int, int>> intro, extro;
  for (int i = 0; i < n; i++) {
    int w; cin >> w;
    intro.insert({w, i + 1});
  }

  string line;
  cin >> line;
  for (auto c: line) {
    if (c == '0') {
      auto t = intro.begin();
      cout << t->second << " ";
      extro.insert({t->first, t->second});
      intro.erase(t);
    } else {
      auto t = --extro.end();
      cout << t->second << " ";
      extro.erase(t);
    }
  }
  cout << endl;

}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

