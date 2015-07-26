using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

// RMQ.
const int MN = 100000 + 10; // Max number of elements
const int ML = 18; // ceil(log2(MN));

struct st {
  long long data[MN];
  long long M[MN][ML];
  int n;

  void read(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i)
      cin >> data[i];
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = __gcd(M[i][j - 1], M[i + q][j - 1]);
  }

  long long query(int b, int e) {
    int k = log2(e - b + 1);
    return __gcd(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};

st tree;

void solve() {
  int n;
  cin >> n;
  tree.read(n);
  tree.build();

  long long best = 0;
  for (int i = 0; i < n; ++i) {
    long long need = tree.data[i];
    int flag = true;
    best = max(best, tree.query(i, n - 1) * (n - i));
    // cout << "start at " << (i) << " : " ;
    while (tree.query(i, n - 1) < need) {

      int lo = i, hi = n - 1;
      while (lo < hi) {
       //  D(lo);D(hi);
        if (lo + 1 == hi) {
          if (tree.query(i, lo) >= need)
            lo = hi;
          break;
        }
        int mid = (lo + hi) >> 1;
        if (tree.query(i, mid) < need) {
          hi = mid;
        } else {
          lo = mid + 1;
        }
      }

      best = max(best, tree.query(i, lo - 1) * (lo - i));
      need = tree.query(i, lo);

      /*for (int j = i; j < n; ++j) {
        if (tree.query(i, j) < need) {
          cout << " from " << i << " to " << j - 1 << endl;
          best = max(best, tree.query(i, j - 1) * (j - i));
          need = tree.query(i, j);
          break;
        }
      }
      */
    }
    // cout << endl;
  }

  cout << best << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
