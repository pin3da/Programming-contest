#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long v[10], t[10];
  for (int i = 0; i < 10; ++i) {
    if (i) {
      v[i] = v[i - 1] * 26;
      t[i] = t[i - 1] * 10;
    } else {
      v[i] = t[i] = 1;
    }
  }
  int tc; cin >> tc;
  while (tc--) {
    long long c, d;
    cin >> c >> d;
    if ((c + d) == 0)
      cout << 0 << endl;
    else
      cout << v[c] * t[d] << endl;
  }
  return 0;
}
