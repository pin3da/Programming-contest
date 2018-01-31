#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }

template <typename H, typename... T>
void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#endif


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  string line; cin >> line;
  vector<int> data(n);
  for (int i = 0; i < n; i++) {
    data[i] = line[i] == '1';
  }

  int flipped = false;
  for (int i = 0; i < n; i++) {
    if (data[i] ^ flipped) {
      flipped ^= 1;
    }
  }
  cout << flipped << endl;
  return 0;
}
