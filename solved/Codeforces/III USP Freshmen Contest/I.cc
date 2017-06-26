#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n; cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(b, a);
    int odd = (a + b) & 1;
    int target = (a + b) / 2;
    if (a == target && b == (target + odd)) {
      cout << "Ok" << endl;
    } else {
      cout << target << " " << target + odd << endl;
    }
  }
  return 0;
}
