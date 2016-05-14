#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    int id = 1, ans = 0;
    do {
      if (id <= (n >> 1)) id <<= 1;
      else id = ((id - (n >> 1)) << 1) - 1;
      ans++;
    } while (id != 1);
    cout << ans << endl;
  }
  return 0;
}
