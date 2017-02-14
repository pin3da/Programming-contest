#include <bits/stdc++.h>

using namespace std;
const int MN = 123;

int cur[MN][MN];
int old[MN][MN];

int main() {

  int w, h, b;
  cin >> h >> w >> b;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j< h; ++j) {
      cin >> cur[i][j];
    }
  }
  while (b--) {
    memset(old, 0, sizeof old);
    for (int i = 0; i < w; ++i) {
      for (int j = 0; j< h; ++j) {
        for (int x = -1; x < 2; ++x) {
          for (int y = -1; y < 2; ++y) {
            int nx = (i + x + w) % w;
            int ny = (j + y + h) % h;
            old[i][j] += cur[nx][ny];
          }
        }
      }
    }

    for (int i = 0; i < w; ++i)
      for (int j = 0; j< h; ++j)
        cur[i][j] = old[i][j];
  }

  set<int> ans;
  for (int i = 0; i < w; ++i)
    for (int j = 0; j< h; ++j)
      ans.insert(cur[i][j]);

  cout << ans.size() << endl;

  return 0;
}
