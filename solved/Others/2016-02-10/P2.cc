#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  int best = 10000;
  int id_best = -1;
  int t;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (abs(k - t) < best) {
      best = abs(k - t);
      id_best = i + 1;
    }
  }
  cout << id_best << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
