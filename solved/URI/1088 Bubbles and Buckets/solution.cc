#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

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
    if (from == 0) return query(to);
    return query(to) - query(from-1);
  }

};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, t;
  while (cin >> n && n) {
    FenwickTree tree(n + 10);
    long long s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> t;
      s += tree.query(t, n);
      tree.add(t, 1);
    }
    if (s & 1) {
      cout << "Marcelo" << endl;
    } else {
      cout << "Carlos" << endl;
    }
  }
  return 0;
}
