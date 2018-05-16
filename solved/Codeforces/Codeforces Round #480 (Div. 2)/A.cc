#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void solve() {
  int frec[] = {0, 0};
  string line;
  cin >> line;
  for (auto c : line) {
    frec[c == 'o']++;
  }

  int parts = frec[1];
  if (parts == 0 || (frec[0] % parts) == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

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

