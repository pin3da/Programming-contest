using namespace std;
#include <bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

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

int main() { ___

  int m, t, r;
  cin >> m >> t >> r;
  FenwickTree tree(302);
  int tmp;
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    tree.add(tmp, -r);
    tree.add(tmp + 1, r);
  }
  if (t <= r) {
    cout << -1 << endl;
    return 0;
  }

  int ans = 0;
  for (int i = 0; i < 301; ++i) {
    if (tree.query(i) < 0) {
      int need = -(tree.query(i));
      // cout << "need " << need << " at " << i << endl;
      ans += need;
      for (int k = need - 1; k >= 0; --k) {
        tree.add(i, 1);
        tree.add(i + (t - k), -1);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
