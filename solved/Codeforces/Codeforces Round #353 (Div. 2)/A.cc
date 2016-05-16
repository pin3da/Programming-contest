#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long a, b, c;
  while (cin >> a >> b >> c) {
    if (c == 0) {
      if (a == b) cout << "YES"  << endl;
      else cout << "NO" << endl;
      continue;
    }

    if ((b < a && c > 0) || (b > a && c < 0)) {
      cout << "NO" << endl;
      continue;
    }

    if ((b - a) % c == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
