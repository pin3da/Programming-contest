#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << (x) << endl

int main() {
#ifdef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int cost[3][3];
  int best = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
       cin >> cost[i][j];
    }
    best += *min_element(cost[i], cost[i] + 3);
  }
  cout << best << endl;
  return 0;
}
