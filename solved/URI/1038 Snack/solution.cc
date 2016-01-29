#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<double> c({4, 4.5, 5, 2, 1.5});
  int x, y;
  cin >> x >> y;
  x--;
  cout << "Total: R$ ";
  cout << fixed << setprecision(2) << c[x] * y << endl;
  return 0;
}
