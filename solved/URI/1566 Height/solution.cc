#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n, t; cin >> n;
    vector<int> frec(233);
    while (n--) {
      cin >> t;
      frec[t]++;
    }
    int first = 1;
    for (int i = 0; i < frec.size(); ++i) {
      while (frec[i]--) {
        if (!first) cout << " ";
        cout << i;
        first = 0;
      }
    }
    cout << endl;
  }
  return 0;
}
