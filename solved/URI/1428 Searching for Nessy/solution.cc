#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    long long x, y;
    cin >> x >> y;
    x = x / 3;
    y = y / 3;
    cout << x * y << endl;
  }

  return 0;
}
