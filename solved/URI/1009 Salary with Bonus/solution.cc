#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  double a, b;
  while (cin >> line >> a >> b)
    cout << "TOTAL = R$ " << fixed << setprecision(2) << a + b * 0.15 << endl;

  return 0;
}
