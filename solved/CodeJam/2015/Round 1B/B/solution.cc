using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl


int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int unhappiness(vector<vector<int> > &g) {
  int ans = 0;
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[0].size(); ++j) if (g[i][j]) {
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0  && x < g.size() && y >= 0 && y < g[0].size()) {
          if (g[x][y] > 0)
            ans++;
        }
      }
    }
  return (ans / 2);
}


void dbg(vector<vector<int> > &g) {
  for (int i = 0; i < g.size(); ++i) {
    for (int j = 0; j < g[0].size(); ++j) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int test(int r, int c, int n, int parity) {
  vector<vector<int> > g(r, vector<int>(c, 0));
  for (int i = 0; i < r && n; ++i) {
    for (int j = 0; j < c && n; ++j) {
      if ((i + j) % 2 == parity) {
        g[i][j] = 1;
        n--;
      }
    }
  }

  if (n > 0 && g[0][0] == 0) {
    g[0][0] = 1;
    n--;
  }

  if (n > 0 && g[0][c - 1] == 0) {
    g[0][c - 1] = 1;
    n--;
  }

  if (n > 0 && g[r - 1][0] == 0) {
    g[r - 1][0] = 1;
    n--;
  }

  if (n > 0 && g[r - 1][c - 1] == 0) {
    g[r - 1][c - 1] = 1;
    n--;
  }


  for (int i = 0; i < r && n; ++i) {
    if (g[i][0] == 0) {
      g[i][0] = 1;
      n--;
    }
  }

  for (int i = 0; i < r && n; ++i) {
    if (g[i][c - 1] == 0) {
      g[i][c - 1] = 1;
      n--;
    }
  }

  for (int i = 0; i < c && n; ++i) {
    if (g[0][i] == 0) {
      g[0][i] = 1;
      n--;
    }
  }

  for (int i = 0; i < c && n; ++i) {
    if (g[r - 1][i] == 0) {
      g[r - 1][i] = 1;
      n--;
    }
  }

  for (int i = 0; i < r && n; ++i) {
    for (int j = 0; j < c && n; ++j) {
      if (g[i][j] == 0) {
        g[i][j] = 1;
        n--;
      }
    }
  }
  return unhappiness(g);
}

void solve() {
  int r, c, n;
  cin >> r >> c >> n;
  cout << min(test(r, c, n, 0), test(r, c, n, 1)) << endl;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case #%d: ", i + 1);
    solve();
  }
  return 0;
}
