#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double a, b, c;
  while(cin >> a >> b >> c) {
    long double h = sqrt(a * a + 12 * 12);
    if (12 / b >= h / c)
      cout << "S";
    else
      cout << "N";
    cout << endl;
  }
  return 0;
}

