#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct fenwick_tree{
  vector<long long> v;
  int maxSize;

  fenwick_tree(int _maxSize) : maxSize(_maxSize+1) {
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

  int get_first(int q, int mv) {
    int lo = 0, hi = mv;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (query(mid) < q)
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }

  void print(int n) {
    for (int i = 0; i <= n; ++i)
      cout << query(i) << ' ';
    cout << endl;
  }

};

static fenwick_tree tree(100000 + 10);

bool check(vector<long long> &a) {
  sort(a.begin(), a.end());
  int n = a.size();

  for (int i = 0; i < tree.v.size(); ++i)
    tree.v[i] = 0;


  for (int i = 0; i < n; ++i) {
    tree.add(i, a[i]);
    tree.add(i + 1, -a[i]);
  }

  for (n--; n >= 0; --n) {
    // tree.print(n);
    long long val = tree.query(n);

    if (val == 0)
      return true;
    if (val >= (n + 1) || tree.query(n - val) == 0)
      return false;

    int idx = n - val;
    long long k = tree.query(n - val);

    int i = tree.get_first(k, n),
        j = tree.get_first(k + 1, n);


    tree.add(j, -1);
    tree.add(i, - 1);
    tree.add(i + val - (n - j), 1);
    tree.add(n, - tree.query(n));
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long long n;
  while (cin >> n) {
    long long e = 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      e += a[i];
    }
    if (e & 1) {
      cout << "impossivel" << endl;
    } else {
      if (check(a))
        cout << "possivel" << endl;
      else
        cout << "impossivel" << endl;
    }

  }
  return 0;
}
