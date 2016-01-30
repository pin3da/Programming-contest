#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double x;
  vector<double> a;
  while (true) {
    a.clear();
    while (a.size() < 2) {
      cin >> x;
      if (x < 0 || x > 10)
        cout << "nota invalida" << endl;
      else
        a.emplace_back(x);
    }
    cout << "media = " << fixed << setprecision(2) << (a[0] + a[1]) * 0.5 << endl;
    int y;
    cout << "novo calculo (1-sim 2-nao)" << endl;
    while (cin >> y) {
      if (y == 2)
        return 0;
      if (y == 1)
        break;
      cout << "novo calculo (1-sim 2-nao)" << endl;
    }
  }
  return 0;
}
