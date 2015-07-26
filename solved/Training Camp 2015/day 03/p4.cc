using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
// #define endl '\n'

// RMQ.
const int MN = 100000 + 10; // Max number of elements
const int ML = 20; // ceil(log2(MN));

long long gcd(long long x, long long y) {
  if (x<y)
    return gcd(y,x);
  if (y==0)
    return x;
  return gcd(y,x%y);
}

struct st {
  long long data[MN];
  long long M[ML][MN];
  int n;

  void read(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i) {
      //cin >> data[i];
      scanf("%lld", data + i);
      M[0][i] = data[i];
    }
    data[n] = M[0][n] = 1;
  }

  void build() {
    // for (int i = 0; i < n; ++i)
    //  M[0][i] = data[i];

    int k = 1;
    while((1 << k) <= n) {
      int d = 1 << (k - 1);
      for(int i = 0; i + 2 * d <= n + 1; i++)
        M[k][i] = __gcd(M[k-1][i], M[k-1][i+d]);
      k++;
    }

    //for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
    //  for (int i = 0; i + p - 1 < n; ++i)
    //    M[j][i] = __gcd(M[j - 1][i], M[j - 1][i + q]);

  }

  long long query(int b, int e) {
    int x = 0;
    while(b+(1<<x)<=e+1)
      x++;
    x--;
    int d = 1 << x;
    return __gcd(M[x][b],M[x][e-d+1]);

    // int k = log2(e - b + 1);
    //return __gcd(M[k][b], M[k][e + 1 - (1<<k)]);
  }
};

st tree;

void solve() {
  int n;
  // cin >> n;
  scanf("%d", &n);
  tree.read(n);
  tree.build();

  long long best = 1;
  for (int i = 0; i < n; ++i) {
    long long need = tree.data[i];
    int j = i;
    while (j < n) {
      int lo = j, hi = n - 1;
      while (lo < hi) {
       //  D(lo);D(hi);
        int mid = (lo + hi + 1) >> 1;
        if (tree.query(i, mid) == need) {
          lo = mid;
        } else {
          hi = mid - 1;
        }
      }

      best = max(best, need * (lo - i + 1));
      j = lo + 1;
      if (j < n)
        need = tree.query(i, j);
    }
  }

  // cout << best << endl;
  printf("%lld\n", best);
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc;
  scanf("%d", &tc);
  //cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
