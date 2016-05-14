#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct elf {
  string name;
  int a, w;
  double h;
  elf() {}
  bool operator < (const elf &o) const {
    if (w == o.w) {
      if (a == o.a)  {
        if (h == o.h)
          return name < o.name;
        return h < o.h;
      }
      return a < o.a;
    }
    return w > o.w;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t; cin >> t;
  int tc = 0;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<elf> a(n);
    for (auto &i : a)
      cin >> i.name >> i.w >> i.a >> i.h;
    sort(a.begin(), a.end());
    cout << "CENARIO {" << ++tc << "}" << endl;
    for (int i = 0; i < m; ++i) {
      cout << (i + 1) << " - " << a[i].name << endl;
    }
  }
  return 0;
}
