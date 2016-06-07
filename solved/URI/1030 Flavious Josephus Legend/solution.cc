#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int joseph(int n, int k) {
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans = (ans + k) % i;
    }
    return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  cout << joseph(n, k) + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << i + 1 << ": ";
    solve();
  }
  return 0;
}
