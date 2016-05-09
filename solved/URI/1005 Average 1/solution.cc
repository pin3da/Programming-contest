#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a, b;
  while (cin >> a >> b) {
    a *= 3.5;
    b *= 7.5;
    cout << "MEDIA = " << fixed << setprecision(5) << (a + b) / 11 << endl;
  }
  return 0;
}
