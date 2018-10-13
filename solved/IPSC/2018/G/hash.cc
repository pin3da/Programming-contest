#include <bits/stdc++.h>

using namespace std;

int main() {
  char c;
  const long long mod = 1e9+7;
  long long p = 1, ans = 0;
  while (cin.get(c)) {
    ans = (ans + (p * c) % mod) % mod;
    p = (p + 1) % mod;
  }
  cout << ans << endl;
  return 0;
}
