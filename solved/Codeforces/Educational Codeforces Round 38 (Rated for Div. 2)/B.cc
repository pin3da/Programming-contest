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


const int MN = 1000000;
void solve() {
  int n; cin >> n;

  vector<int> pos; pos.push_back(1);

  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    pos.push_back(t);
  }

  pos.push_back(MN);

  int best = MN;
  for (int i = 1; i < int(pos.size()); i++) {
    int cur = max(pos[i - 1] - 1, MN - pos[i]);
    best = min(best, cur);
  }

  cout << best << endl;
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

