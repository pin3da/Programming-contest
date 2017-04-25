// http://codeforces.com/contest/295/problem/A

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
    if (!from) return query(to);
    return query(to) - query(from-1);
  }

};

struct op {
  long long l, r, d;
};

const int MN = 100010;

FenwickTree data(MN), frec(MN);

void solve(int n) {
  int m, k; cin >> m >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<op> b(m);
  for (auto &i : b) {
    cin >> i.l >> i.r >> i.d;
    i.l--; i.r--;
  }
  int x, y;
  for (int i = 0; i < k; ++i) {
    cin >> x >> y;
    x--; y --;
    frec.add(x, 1);
    frec.add(y + 1, -1);
  }
  for (int i = 0; i < m; ++i) {
    b[i].d *= frec.query(0, i);
    data.add(b[i].l, b[i].d);
    data.add(b[i].r + 1, -b[i].d);
  }

  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    cout << a[i] + data.query(0, i);
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; while (cin >> n)  solve(n);
  return 0;
}
