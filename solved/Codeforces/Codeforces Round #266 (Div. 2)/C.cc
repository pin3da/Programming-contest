#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

const int MN = 5 * 1e5 + 100;
long long a[MN];
long long b[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    long long total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      total += a[i];
      b[i] = a[i];
      if (i) b[i] += b[i - 1];
    }
    if ((total % 3) || n < 3) {
      cout << 0 << endl;
    } else {
      long long ans = 0;
      long long acc = 0;
      long long a1 = total / 3;
      long long a2 = a1 + total / 3;
      for (int i = n - 1; i >= 0; --i) {
        if (b[i] == a1) {
          ans += acc;
        } if (i < n - 1 && b[i] == a2)
          acc++;
      }
      cout << ans << endl;
    }
  }

  return 0;
}
