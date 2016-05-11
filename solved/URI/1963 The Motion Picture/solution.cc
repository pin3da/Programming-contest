#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b;
  while (cin >> a >> b) {
    cout << fixed << setprecision(2) << ((b - a) / a)* 100 << "%" << endl;
  }

  return 0;
}
