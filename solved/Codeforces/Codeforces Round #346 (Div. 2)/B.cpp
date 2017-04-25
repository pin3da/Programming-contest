// http://codeforces.com/contest/659/problem/B

#include <bits/stdc++.h>

#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

struct st{
  int s;
  string name;
  st() {}
  st(string a, int b) : name(a), s(b) {}
  bool operator < (const st &o) const {
    if (s == o.s)
      return name < o.name;
    return s > o.s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<st>> a(m);
    string name;
    int r, s;
    for (int i = 0; i < n; ++i) {
      cin >> name >> r >> s;
      a[r - 1].emplace_back(st(name, s));
    }
    for (int i = 0; i < m; ++i) {
      sort(a[i].begin(), a[i].end());
      int best = a[i][0].s;
      int j = 0;
      while (j < a[i].size() && a[i][j].s == best) ++j;
      if (j > 2)
        cout << "?" << endl;
      else {
        best = a[i][1].s;
        j = 1;
        while (j < a[i].size() && a[i][j].s == best) ++j;
        if (j > 2)
          cout << "?" << endl;
        else
          cout << a[i][0].name << ' ' << a[i][1].name << endl;
      }
    }
  }
  return 0;
}
