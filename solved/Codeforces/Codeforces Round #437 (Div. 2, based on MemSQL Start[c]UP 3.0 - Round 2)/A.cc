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

  int n;
  cin >> n;
  string a;
  cin >> a;

  int sf = 0, fs = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == 'S' && a[i] == 'F') sf++;
    if (a[i - 1] == 'F' && a[i] == 'S') fs++;
  }

  puts(sf > fs? "YES" : "NO");

  return 0;
}
