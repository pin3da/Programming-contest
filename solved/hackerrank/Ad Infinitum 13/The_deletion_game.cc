using namespace std;
#include <bits/stdc++.h>

bool go(int i, int c, int n, int k) {
  if (i == n + 1)
    return c == k;
  return go(i + 1, c - i, n, k) || go(i + 1, c + i, n, k);
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    long long n, k;
    cin >> n >> k;
    k = llabs(k);
    if (((n * (n + 1)) >> 1) >= k) {
      int ini = !(((n + 1) >> 1) & 1);
      // assert( ini ^ (k & 1) ==  go(0, 0, n, k));
      cout << ((ini ^ (k & 1)) ? "YES" : "NO") << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
