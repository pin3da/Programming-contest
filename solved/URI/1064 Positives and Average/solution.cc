#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<double> p;
  double x;
  int t = 6;
  while (t--) {
    cin >> x;
    if (x > 0)
      p.emplace_back(x);
  }
  double sum = accumulate(p.begin(), p.end(), 0.0);
  cout << p.size() << " valores positivos" << endl;
  cout << fixed << setprecision(1) << sum / p.size() << endl;

  return 0;
}
