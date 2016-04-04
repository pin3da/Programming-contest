#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int p;
  while (cin >> line >> p) {
    int ans = 0, b = 0;
    for (auto &i : line) {
      if (i == 'W') {
        ans++;
        ans += (b + p - 1) / p;
        b = 0;
      } else
        b++;
    }

    cout << ans + (b + p - 1) / p << endl;
  }
  return 0;
}
