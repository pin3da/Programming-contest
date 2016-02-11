#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int q;
  while (cin >> q && q) {
    int id = 1;
    while (q--) {
      long double a, b, c;
      cin >> a >> b >> c;
      cout << "Size #" << id++ << ":" << endl;
      cout << "Ice Cream Used: ";
      cout << fixed << setprecision(2) << a * (c + b) * 2.5;
      cout << " cm2" << endl;
    }
    cout << endl;
  }

  return 0;
}
