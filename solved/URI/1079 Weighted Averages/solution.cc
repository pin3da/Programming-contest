#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  long double a, b, c;
  while (n --) {
    cin >> a >> b >> c;
    cout << fixed << setprecision(1) << (a * 2 + b * 3 + c * 5) / (10.0) << endl;
  }
  return 0;
}
