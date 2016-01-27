#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long x;
  while (cin >> x && x) {
    long long ans = 0;
    if (x & 1) x++;
    for (int i = 0; i < 10; i += 2)
      ans += x + i;
    cout << ans << endl;
  }
  return 0;
}
