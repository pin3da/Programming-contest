#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2000 * 1000 + 100;
bool sieve[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    memset(sieve, 0, sizeof sieve);
    int n; cin >> n;
    int t;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      if (t < MN)
        sieve[t] = true;
    }
    if (sieve[1] == 0)
      cout << 0 << endl;
    else {
      int seen = 0;
      for (int i = 2; i < MN && !seen; ++i) {
        if (sieve[i] == 0) {
          cout << i - 1 << endl;
          seen = 1;
        } else {
          for (int j = i + i; j < MN; j += i) {
            sieve[j] = true;
          }
        }
      }
    }
  }
  return 0;
}
