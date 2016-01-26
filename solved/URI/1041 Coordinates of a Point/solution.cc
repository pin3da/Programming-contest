#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double x, y;
  cin >> x >> y;
  if (x == 0 && y == 0) {
    cout << "Origem" << endl;
    return 0;
  }
  if (x == 0) {
    cout << "Eixo Y" << endl;
    return 0;
  }
  if (y == 0) {
    cout << "Eixo X" << endl;
    return 0;
  }
  if (x * y > 0)
    if (x > 0)
      cout << "Q1" << endl;
    else
      cout << "Q3" << endl;
  else
    if (x < 0)
      cout << "Q2" << endl;
    else
      cout << "Q4" << endl;
  return 0;
}
