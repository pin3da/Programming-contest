#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b;
  while (cin >> a >> b) {
    int q, r;

    for (r = 0; r < abs(b); ++r) {
      if (((a - r) % b) == 0) {
        q = (a - r) / b;
        break;
      }
    }
    cout << q << ' ' << r << endl;
  }
  return 0;
}
