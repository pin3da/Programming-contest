#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  double a, b, c;
  while (cin >> a >> b >> c) {
    a = a * b * 100 / c;
    cout << int(sqrt(a)) << endl;
  }
  return 0;
}
