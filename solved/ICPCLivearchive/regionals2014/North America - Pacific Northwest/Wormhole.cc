using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

map<string, int> cod;
int get_id(const string &s) {
  int id = cod.size();
  if (cod.count(s) == 0) cod[s] = id;
  return cod[s];
}

double comp_d(vector<int> &x, vector<int> &y, vector<int> &z, int i, int j) {
  double dx = x[i] - x[j],
         dy = y[i] - y[j],
         dz = z[i] - z[j];
  return sqrt(dx * dx + dy * dy + dz * dz);
}

void solve() {
  int n; cin >> n;
  vector<int> x(n), y(n), z(n);
  string name;
  for (int i = 0; i < n; ++i) {
    cin >> name >> x[i] >> y[i] >> z[i];
    get_id(name);
  }
  vector<vector<double>> dist(n, vector<double>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      dist[i][j] = comp_d(x, y, z, i, j);
    }
  }

  int q; cin >> q;
  string from, to;
  for (int i = 0; i < q; ++i) {
    cin >> from >> to;
    dist[get_id(from)][get_id(to)] = 0;
  }

  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> from >> to;
    int a = get_id(from), b = get_id(to);
    cout << "The distance from " << from << " to " << to << " is ";
    cout << (long long) llround(dist[a][b] + 1e-10) << " parsecs." << endl;
  }
}

int main() {
  int n;cin >> n;
  for (int i = 0; i < n; ++i) {
    printf("Case %d:\n", i + 1);
    cod.clear();
    solve();
  }
  return 0;
}
