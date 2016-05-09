#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b, c;
  while (cin >> a >> b >> c) {
    a *= 2;
    b *= 3;
    c *= 5;
    cout << "MEDIA = " << fixed << setprecision(1) << (a + b + c) / 10 << endl;
  }
  return 0;
}
