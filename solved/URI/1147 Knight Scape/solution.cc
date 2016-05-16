#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

bool valid(int nx, int ny) {
  return (nx >= 0 && nx < 8 && ny >=0 && ny < 8);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int tc = 0;
  while (cin >> line && line != "0") {
    vector<vector<int>> a(8, vector<int>(8));
    int x = line[0] - '1', y = line[1] - 'a';
    for (int i = 0; i < 8; ++i) {
      cin >> line;
      int xx = line[0] - '1', yy = line[1] - 'a';
      a[xx][yy] = 1;
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (valid(nx, ny)) {
        int tx = nx + 1, ty = ny - 1;
        int ok = true;
        if (valid(tx, ty) && a[tx][ty]) ok = false;
        ty = ny + 1;
        if (valid(tx, ty) && a[tx][ty]) ok = false;
        if (ok) ans++;
      }
    }
    cout << "Caso de Teste #" << ++tc << ": ";
    cout << ans << " movimento(s)." << endl;

  }
  return 0;
}
