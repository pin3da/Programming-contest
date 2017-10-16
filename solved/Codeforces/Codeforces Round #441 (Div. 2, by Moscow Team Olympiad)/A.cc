#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int dist[3][3];

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      int t; cin >> t;
      dist[i][j] = t;
      dist[j][i] = t;
    }
  }
  int st = 0;
  long long ans = 0;
  while (--n > 0) {
    int best = 1000, j = -1;
    for (int i = 0; i < 3; i++) {
      if (i == st) continue;
      if (dist[st][i] < best) {
        best = dist[st][i];
        j = i;
      }
    }
    ans += best;
    st = j;
  }

  cout << ans << endl;

  return 0;
}
