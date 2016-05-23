#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;
struct plane {
  int a, b, c, d;
  bool eval(int x, int y, int z) {
    return (a * x + b * y + c * z) > d;
  }
};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<plane> p(n);
    vector<int> f(n);
    for (auto &i: p) cin >> i.a >> i.b >> i.c >> i.d;
    int x, y, z;
    unordered_map<long long, int> ans;
    long long base = 3;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y >> z;
      long long region = 0;
      for (int j = 0; j < n; ++j) {
        region *= base;
        region += p[j].eval(x, y, z);
      }
      ans[region]++;
    }
    int best = 0;
    for (auto &i : ans) best = max(i.second, best);
    cout << best << endl;
  }

  return 0;
}
