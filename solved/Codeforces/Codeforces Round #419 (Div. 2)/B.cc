#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 200000 + 100;

int all[MN];
int ans[MN];
int n, k;


int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int q;
  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    all[a]++;
    all[b + 1]--;
  }
  for (int i = 1; i < MN; ++i) {
    all[i] += all[i - 1];
    if (all[i] >= k) ans[i] = 1;
    ans[i] += ans[i - 1];
  }

  while (q--) {
    int a, b; cin >> a >> b;
    cout << ans[b] - ans[a - 1] << endl;
  }
  return 0;
}
