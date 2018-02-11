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



int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    vector<int> H(n), R(n), T(n);
    for (int i = 0; i < n; i++)
      cin >> H[i] >> R[i] >> T[i];

    int longest = *max_element(H.begin(), H.end());
    const int MAXN = 1825 * longest;
    vector<int> all(MAXN);


    for (int i = 0; i < n; i++) {
      int h = H[i], r = R[i], t = T[i];

      r = (r + 1) % h;

      vector<int> temp(h);
      for (int i = r; i != t; i = (i + 1) % h) {
        temp[i] = true;
      }

      int start = 0;
      while (start < MAXN) {
        for (int i = 0; i < h && (i + start) < MAXN; i++) {
          all[start + i] |= temp[i];
        }
        start += h;
      }
    }

    int ans = -1;
    for (int i = 0; i < MAXN; i++) {
      if (all[i] == 0) {
        ans = i;
        break;
      }
    }

    if (ans == -1) {
      cout << "impossible" << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
