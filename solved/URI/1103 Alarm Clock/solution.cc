#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c, d;
  while (cin >> a >> b >> c >> d && (a + b + c + d)) {
    int x = a * 60 + b,
        y = c * 60 + d;
    if (y <= x) y += 24 * 60;
    cout << y - x << endl;
  }
  return 0;
}
