using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

map<char, double> cod;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cod['W'] = 1;
  cod['H'] = 1.0 / 2.0;
  cod['Q'] = 1.0 / 4.0;
  cod['E'] = 1.0 / 8.0;
  cod['S'] = 1.0 / 16.0;
  cod['T'] = 1.0 / 32.0;
  cod['X'] = 1.0 / 64.0;

  string line;
  while (cin >> line && line != "*" ) {
    double accum = 0;
    int ans = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '/') {
        if (fabs(accum - 1.0) < 1e-12) {
          ans++;
        }
        accum = 0;
      } else
        accum += cod[line[i]];
    }
    cout << ans << endl;
  }

  return 0;
}
