#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve() {
  long long a, b;
  double c, d;
  cin >> a >> b >> c >> d;
  long long ap = round(c * 10) + 1000;
  long long bp = round(d * 10) + 1000;
  for (int i = 0; i < 101; ++i) {
    if (a > b) {
      cout << i << " anos." << endl;
      return;
    }
    a = (a * ap) / 1000;
    b = (b * bp) / 1000;
  }
  cout << "Mais de 1 seculo." << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--)
    solve();
  return 0;
}
