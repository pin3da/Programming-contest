#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int MN = 123;

int pre[11][MN][MN];


int get(int c, int x1, int y1, int x2, int y2) {
  int ans = pre[c][x2][y2]
    - pre[c][x2][y1 - 1] - pre[c][x1 - 1][y2]
    + pre[c][x1 - 1][y1 - 1];
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, q, c;
  cin >> n >> q >> c;
  // [0, c]
  c++;

  for (int i = 0; i < n; ++i) {
    int x, y, s; cin >> x >> y >> s;
    pre[s][x][y]++;
  }

  for (int i = 0; i < c; ++i) {
    for (int x = 1; x < MN; x++) {
      for (int y = 1; y < MN; y++) {
        pre[i][x][y] = pre[i][x][y]
          + pre[i][x - 1][y] + pre[i][x][y - 1]
          - pre[i][x - 1][y - 1];
      }
    }
  }


  while (q--) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    t %= c;

    long long ans = 0;
    for (int i = 0; i < c; ++i) {
      int frec = get(i, x1, y1, x2, y2);
      int val = (i + t) % c;
      ans += val * frec;
    }
    cout << ans << endl;
  }

  return 0;
}
