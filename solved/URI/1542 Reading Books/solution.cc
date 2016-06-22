#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int q, d, p;
  while (cin >> q && q) {
    cin >> d >> p;
    int ans = d * p * q / (p - q);
    cout << ans << " pagina";
    if (ans != 1)
      cout << 's';
    cout << endl;
  }
  return 0;
}
