using namespace std;
#include <bits/stdc++.h>

const int N = 100000 + 10;
const int mod = 1000000007;

struct FenwickTree{
  long long v[N];
  int maxSize;

  FenwickTree() {}
  void init(int _maxSize) {
    maxSize = _maxSize+1;
    memset(v, 0, sizeof v);
  }

  void add(int where, long long what){
    for (where++; where <= maxSize; where += where & -where){
      v[where] = (v[where] + what) % mod;
    }
  }

  long long query(int where){
    long long sum = v[0];
    for (where++; where > 0; where -= where & -where){
      sum = (sum + v[where]) % mod;
    }
    return sum % mod;
  }

  long long query(int from, int to){
    return query(to) - query(from-1);
  }

};

struct entry{
  int val, index;
  entry () {}
  entry(int a, int b) : val(a), index(b) {}
  bool operator < (const entry &o) const {
    if (val == o.val)
      return index > o.index;
    return val < o.val;
  }
};

FenwickTree tree;

void solve() {
  int n, t;
  cin >> n;
  tree.init(n);
  vector<entry> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    a[i] = entry(t, i);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); ++i)
    tree.add(a[i].index, tree.query(a[i].index) + 1);
  printf("%lld\n", tree.query(n) % mod);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
