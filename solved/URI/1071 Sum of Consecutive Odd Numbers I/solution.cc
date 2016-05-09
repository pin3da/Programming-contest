#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  while (cin >> a >> b) {
    if (a > b) swap(a, b);
    long long ans = 0;
    for (int i = a + 1; i < b; ++i)
      if (i & 1) ans += i;
    cout << ans << endl;
  }
  return 0;
}
