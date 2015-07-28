using namespace std;
#include <vector>
#include <iostream>
// #define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

const int MN = 1001;

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, t, q; cin >> n;
    vector<int> frec(MN, 0);
    for (int i = 0; i < n; ++i) {
      cin >> t;
      frec[t]++;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
      cin >> t;
      long long ans = 0;
      for (int j = 0; j < MN; ++j) {
        if (frec[j]) {
          int k = t - j;
          if (k < 0) continue;
          if (k >= MN) continue;
          if (k != j) {
            ans += frec[j] * frec[k];
          } else
            ans += (frec[j] * frec[j]) - frec[j];
        }
      }
      cout << ans << endl;
    }

  }
  return 0;
}
