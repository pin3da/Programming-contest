#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int r = 10, c, d;
    cout << "0.0";
    while (r != 1) {
      c = r * 10;
      d = c / n;
      cout << d;
      r = c - d * n;
    }
    cout << endl;
  }  
  return 0;
}
