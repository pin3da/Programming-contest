#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc --) {
    int k;
    cin >> k;
    int q = k - 2015;
    if (q < 0) {
      cout << -q << " D.C." << endl;
    } else {
      cout << q + 1<< " A.C." << endl;
    }
  }
  return 0;
}
