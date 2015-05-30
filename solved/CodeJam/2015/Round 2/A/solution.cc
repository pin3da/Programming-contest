using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

char g[111][111];
bool vi[111][111];
int dx [] = {0, 0, -1, 1};
int dy [] = {-1, 1, 0, 0};
char nc [] = {'<', '>', '^', 'v'};

int ans;
int n, c;

bool fix(int i, int j) {
  int seen = false;
  int cost = true;
  for (int delta = 1; delta < 101; ++delta) {
    for (int k = 0; k < 4; ++k) {
      int x = i + delta * dx[k];
      int y = j + delta * dy[k];
      if (x >= 0 && x < n && y >= 0 && y < c) {
        if (g[x][y] != '.') {
          seen = true;
          if (g[i][j] == nc[k])
            cost = false;
        }
      }
    }
  }
  if (!seen) {
    // cout << "IMPOSSIBLE" << endl;
    return false;
  }

  if (cost) {
    // cout << "at " << i << " : " << j << endl;
    ans++;
  }
  return true;
}

void solve() {
  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> g[i][j];
    }
  }

  memset(vi, 0, sizeof vi);
  ans = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < c; ++j) {
      if (g[i][j] != '.') {
        if (vi[i][j]) break;
        if (!fix(i, j)) {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        vi[i][j] = true;
        break;
      }
    }

    for (int j = c - 1; j >= 0; --j) {
      if (g[i][j] != '.') {
        if (vi[i][j]) break;
        if (!fix(i, j)) {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        vi[i][j] = true;
        break;
      }
    }
  }

  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < n; ++i) {
      if (g[i][j] != '.') {
        if (vi[i][j]) break;
        if (!fix(i, j)) {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        vi[i][j] = true;
        break;
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      if (g[i][j] != '.') {
        if (vi[i][j]) break;
        if (!fix(i, j)) {
          cout << "IMPOSSIBLE" << endl;
          return;
        }
        vi[i][j] = true;
        break;
      }
    }
  }


  cout << ans << endl;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" <<  i + 1 << ": ";
    solve();
  }
  return 0;
}
