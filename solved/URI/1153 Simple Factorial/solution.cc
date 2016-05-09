#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    long long ans = 1;
    n++;
    while (n-- > 1)
      ans *= n;
    cout << ans << endl;
  }
  return 0;
}
