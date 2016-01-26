#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  double a = 1, b = 1, s = 0;
  for (int i = 1; i < 40; i += 2) {
    s += a / b;
    a += 2;
    b *= 2;
  }
  cout << fixed << setprecision(2) << s << endl;

  return 0;
}
