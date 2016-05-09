#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    double x, y;
    cin >> x >> y;
    if (y == 0)
      cout << "divisao impossivel" << endl;
    else
      cout << fixed << setprecision(1) << x / y << endl;
  }
  return 0;
}
