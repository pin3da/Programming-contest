#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  while (cin >> n) {
    long long ans = 1;
    while (n > 0) {
      ans *= 3LL;
      n--;
    }
    cout << ans << endl;
  }
  return 0;
}
