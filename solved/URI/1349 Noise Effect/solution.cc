#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int fun(vector<vector<int>> &a,  vector<vector<int>> &b) {
  int n = a.size();
  int cool = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (abs(a[i][j] - b[i][j]) <= 100)
        cool++;
  return cool;
}

vector<vector<int>> rotate(vector<vector<int>> &b) {
  vector<vector<int>> c = b;
  int n = b.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      c[j][n - 1 - i] = b[i][j];
  return c;
}


vector<vector<int>> rotate2(vector<vector<int>> &b) {
  vector<vector<int>> c = b;
  int n = b.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      c[i][n - 1 - j] = b[i][j];
  return c;
}

void solve(int n) {
  vector<vector<int>> a(n, vector<int> (n));
  vector<vector<int>> b(n, vector<int> (n));

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> a[i][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> b[i][j];

  int best = 0;

  best = max(best, fun(a, b));
  for (int i = 0; i < 4; ++i) {
    b = rotate(b);
    best = max(best, fun(a, b));
  }
  b = rotate2(b);
  best = max(best, fun(a, b));
  for (int i = 0; i < 4; ++i) {
    b = rotate(b);
    best = max(best, fun(a, b));
  }

  printf("%.2lf\n", best / double(n * n) * 100 + 1e-10);

}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    solve(n);
  }
  return 0;
}
