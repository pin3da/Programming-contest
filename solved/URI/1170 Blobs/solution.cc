#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    double x;
    cin >> x;
    int ans = 0;
    while (x > 1.0) {
      ans++;
      x *= 0.5;
    }
    cout << ans << " dias" << endl;
  }
  return 0;
}

