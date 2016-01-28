#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long r, x, y;
  int it = 1;
  while (cin >> r && r) {
    r *= 2;
    cin >> x >> y;
    if (x * x + y * y <= r * r)
      cout << "Pizza " << it << " fits on the table." << endl;
    else
      cout << "Pizza " << it << " does not fit on the table." << endl;
    it++;
  }
  return 0;
}
