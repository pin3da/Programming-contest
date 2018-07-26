#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int fix(char a, char b, char c, char d) {
  map<char, int> frec;
  frec[a]++; frec[b]++; frec[c]++; frec[d]++;
  if (frec.size() == 1) return 0;
  if (frec.size() == 4) return 2;
  if (frec.size() == 2) return frec[a] != 2;
  return 1 + (a == b);
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;

  int ans = 0;
  if (n & 1) {
    ans += (a[n / 2] != b[n / 2]);
  }

  for (int i = 0; i < n / 2; i++) {
    ans += fix(a[i], a[n - 1 - i], b[i], b[n - 1 - i]);
  }
  cout << ans << endl;
  return 0;
}
