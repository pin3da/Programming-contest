using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t, m, n, val; cin >> t;
  for (int k = 0; k < t; ++k) {
    int sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> val;
        if (val > -1) {
          if ((i + j) & 1)
            sum += val;
          else
            sum -= val;
        }
      }
    }
    cout << abs(sum) << endl;
  }

  return 0;
}
