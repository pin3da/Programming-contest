#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct ev {
  int x, y, t, id;
  ev(int a, int b, int c, int d) : x(a), y(b), t(c), id(d) {}
  bool operator < (const ev &o) const {
    if (y == o.y) {
      return t < o.t;
    }
    return y < o.y;
  }
};

class FenwickTree{
  vector<long long> v;
  int maxSize;

public:
  FenwickTree(int _maxSize) : maxSize(_maxSize+1) {
    v = vector<long long>(maxSize, 0LL);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] += what;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum += v[where];
    }
    return sum;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    map<long long, int> cc;
    vector<ev> line;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      cc[x + y] = cc[y - x] = 0;
      line.emplace_back(x + y, y - x, 0, -1);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      cc[x + y] = cc[y - x] = 0;
      line.emplace_back(x + y, y - x, 1, i);
    }
    int id = 5;
    for (auto &it : cc) {
      it.second = id++;
    }
    for (int i = 0; i < line.size(); ++i) {
      line[i].x = cc[line[i].x];
      line[i].y = cc[line[i].y];
    }

    sort(line.begin(), line.end());
    vector<int> ans(n);
    FenwickTree tree(cc.size() + 10);
    for (auto &e : line) {
      if (e.t == 0) {
        tree.add(e.x, 1);
      } else {
        long long cur = tree.query(e.x);
        ans[e.id] = cur;
      }
    }

    for (int i = 0; i < ans.size(); ++i)
      cout << ans[i] << endl;

  }
  return 0;
}
