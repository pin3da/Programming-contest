#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long long ll;
const int MN = 1111;
int g[MN][MN];
int g2[MN][MN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int c; cin >> c;
    memset(g, 0, sizeof g);
    memset(g2, 0, sizeof g2);

    int x = MN / 2, y = MN / 2;
    int border = 0, inside = 0;
    for (int k = 0; k < c; k++) {
      char op; int l;
      cin >> op >> l;
      int sgn = l > 0 ? 1 : -1;
      border += abs(l);
      for (int i = 0; i < abs(l); i++) {
        if (op == 'x') {
          x += sgn;
        } else if (op == 'y') {
          if (sgn < 0)
            g[y][x] = 1;
          y += sgn;
          if (sgn > 0)
            g[y][x] = 1;
        } else {
          if (sgn < 0)
            g2[y][x] = 1;
          x -= sgn;
          y += sgn;
          if (sgn > 0)
            g2[y][x] = 1;
        }
      }
    }

    for (int i = 0; i < MN; i++) {
      int open = 0;
      for (int j = 0; j < MN; j++) {
        if (g[i][j])  open ^= 1;
        if (open) inside++;
        if (g2[i][j]) open ^= 1;
        if (open) inside++;
      }
      assert(open == 0);
    }

    cout << inside << endl;
    // ll A = inside + border / 2 - 1;
    // cout << (A * 2 + (border & 1)) << endl;
  }
  return 0;
}
