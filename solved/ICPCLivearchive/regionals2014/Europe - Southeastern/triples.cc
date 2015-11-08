using namespace std;
#include <bits/stdc++.h>

int main() {
  long long n, m;
  while (cin >> m >> n) {
    long long ans = 0;
    for (int i = 0; i <= m; ++i) {
      for (int j = i; j <= m; ++j) {
        for (int k = j; k <= m; ++k) {
          if ((i * i + j * j) == (k * k)) {
            ans++;
          }
        }
      }
    }
    cout << ans + ((n - 2) * (m + 1)) << endl;
  }
  return 0;
}
