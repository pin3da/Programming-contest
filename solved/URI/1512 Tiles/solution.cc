#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n, a, b;
  while (cin >> n >> a >> b && (a + b)) {
    long long ans = (n / a) + (n / b) - (n / ((a * b) / __gcd(a, b)));
    cout << ans << endl;
  }

  return 0;
}
