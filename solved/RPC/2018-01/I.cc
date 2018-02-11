#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);   debug_out(t...); }

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) //
#define endl '\n'
#endif

const int oo = 1e9;

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int k; cin >> k;

  int ans, min_val = oo;
  for (int i = 0; i < n; i++) {
    if (k % v[i] < min_val) {
      min_val = k % v[i];
      ans = i;
    }
  }

  cout << v[ans] << endl;

  return 0;
}

