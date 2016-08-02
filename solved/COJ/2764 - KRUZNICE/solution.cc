#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

const int MN = 300333;

int p[MN];


struct ev {
  int x, id;
  ev(int a, int b) : x(a), id(b) {}
  bool operator < (const ev &o) const {
    if (x == o.x) return id < o.id;
    return x < o.x;
  }
};

int fs(int x) {
  return x == p[x] ? x : p[x] = fs(p[x]);
}

int js(int x, int y) {
  p[fs(x)] = fs(y);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<ev> line;

    for (int i = 0; i < n + 10; ++i) p[i] = i;
    for (int i = 0; i < n; ++i) {
      int x, r; cin >> x >> r;
      line.emplace_back(x - r, i);
      line.emplace_back(x + r, i);
    }
    sort(line.begin(), line.end());

    set<int> nodes;
    nodes.insert(line[0].x);
    for (int i = 1; i < line.size(); ++i) {
      if (line[i].x == line[i - 1].x) {
        js(line[i].id, line[i - 1].id);
      }
      nodes.insert(line[i].x);
    }

    set<int> cc;
    for (int i = 0; i < n; ++i) cc.insert(fs(i));

    /*
    debug(2 * n);
    debug(nodes.size());
    debug(cc.size());
    */

    cout << 2 * n - nodes.size() + cc.size() + 1 << endl;
  }
  return 0;
}
