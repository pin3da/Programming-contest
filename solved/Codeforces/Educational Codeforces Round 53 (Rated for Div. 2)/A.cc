#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  string line;
  int len; cin >> len;
  cin >> line;
  for (int i = 1; i < (int)line.size(); i++) {
    if (line[i] != line[i -1]) {
      cout << "YES" << endl;
      cout << line[i -1] << line[i]<< endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
