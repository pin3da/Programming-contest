#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int hand(char c) {
  return (c == 'd') || (c == 'f');
}

int cost(const string &s) {
  int total = 2;
  for (int i = 1; i < int(s.size()); i++) {
    total += 2;
    if (hand(s[i - 1]) == hand(s[i])) total += 2;
  }
  return total;
}

void solve() {
  int n;
  cin >> n;
  map<string, int> prev;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    if (prev.count(line)) total += prev[line] / 2;
    else {
      long long c = cost(line);
      prev[line] = c;
      total += c;
    }
  }
  cout << total << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int tc;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
