#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct snake {
  int a, b, c, d;

  snake() {}
  snake(int w, int x, int y, int z) : a(w), b(x), c(y), d(z) {}
  void read(set<int> &num_x, set<int> &num_y) {
    cin >> a >> b >> c >> d;
    num_x.insert(a);
    num_y.insert(b);
    num_x.insert(c);
    num_y.insert(d);
  }

  void paint_vert(vector<vector<int>> &g) {
    int start = min(b, d), end = max(b, d);
    for (int i = start; i <= end; ++i)
      g[a][i]++;
  }

  void paint_hori(vector<vector<int>> &g) {
    int start = min(a, c), end = max(a, c);
    for (int i = start; i <= end; ++i)
      g[i][b]++;
  }

  void paint(vector<vector<int>> &g) {
    if (a == c) paint_vert(g);
    else paint_hori(g);
  }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void print_mat(vector<vector<int>> &g) {
  for (int i = 0; i < (int)g.size(); ++i) {
    for (int j = 0; j < (int)g[0].size(); ++j) {
      cout << g[i][j];
    }
    cout << endl;
  }
}

void solve() {
  snake a, b;
  set<int> num_x, num_y;
  a.read(num_x, num_y);
  b.read(num_x, num_y);
  map<int, int> cod_x, cod_y;
  int id = 0;
  for (int val: num_x) cod_x[val] = id++;
  id = 0;
  for (int val: num_y) cod_y[val] = id++;

  snake first(cod_x[a.a], cod_y[a.b], cod_x[a.c], cod_y[a.d]);
  snake second(cod_x[b.a], cod_y[b.b], cod_x[b.c], cod_y[b.d]);
  vector<vector<int>> g(4, vector<int>(4));
  first.paint(g);
  second.paint(g);

  int have_inter = 0;
  int degree = true;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      have_inter |= (g[i][j] == 2);
      int nei = 0;
      if (g[i][j] == 0) continue;
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k], ny = j + dy[k];
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
          nei += (g[nx][ny] != 0);
        }
      }
      if (nei > 2) {
        degree = false;
      }
    }
  }

  if (have_inter && degree) {
    puts("yes");
  } else {
    puts("no");
  }
}

int main() {
  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}
