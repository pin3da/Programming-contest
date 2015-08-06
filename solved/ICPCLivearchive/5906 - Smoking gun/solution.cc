using namespace std;
#include <bits/stdc++.h>
#define endl '\n'

const double eps = 1e-9;

double dist(double x, double y) {
  return sqrt(x * x + y * y);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> name(n);
  map<string, int> dec;
  vector<int> x(n), y(n), alive(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> name[i] >> x[i] >> y[i];
    dec[name[i]] = i;
  }

  string a, b, c, d;
  vector<vector<double>> dt(n, vector<double> (n, 1e100));
  for (int i = 0; i < m; ++i) {
    cin >> a >> d >> b >> d >> d >> c;
    int p = dec[a], q = dec[b], r = dec[c];
    dt[r][q] = min(dt[r][q], dist(x[p] - x[r], y[p] - y[r]) - dist(x[p] - x[q], y[p] - y[q]));
    alive[q] = true;
    alive[r] = true;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i)  if (alive[i]) {
      for (int j = 0; j < n; ++j) if (alive[j]) {
        dt[i][j] = min(dt[i][j], dt[i][k] + dt[k][j]);
      }
    }
  }

  for (int i = 0; i < n; ++i) if (alive[i]) {
    if (dt[i][i] < eps) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  vector<int> ans;
  int top = count(alive.begin(), alive.end(), 1);

  for (int k = 0; k < top; ++k) {
    int id = -1;
    for (int i = 0; i < n; ++i) if (alive[i]) {
      bool ok  = true;
      for (int j = 0; j < n; ++j) if (alive[j] && i != j) {
        if (dt[j][i] > eps)
          ok = false;
      }
      if (ok) {
        id = i;
        break;
      }
    }

    if (id == -1) {
      cout << "UNKNOWN" << endl;
      return;
    }
    alive[id] = false;
    ans.push_back(id);
  }

  for (int i = 0; i < ans.size(); ++i) {
    if (i) cout << " ";
    cout << name[ans[i]];
  }
  cout << endl;

}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--)
    solve();
  return 0;
}
