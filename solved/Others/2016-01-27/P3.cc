#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
typedef unsigned long long ull;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int t; cin >> t;
    ull x = 1, y = 0;
    for (int i = 0; i < t; ++i) {
      y += x;
      x <<= 1;
    }
    cout << y / 12000 << " kg" << endl;
  }
  return 0;
}
