using namespace std;
#include <bits/stdc++.h>

int main() {
  int n, k;
  while (cin >> n >> k) {
    long long ans = n;
    while (n >= k) {
      ans += (n / k);
      n = (n / k) + (n % k);
    }
    cout << ans << endl;
  }
  return 0;
}
