#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

// RMQ.
const int MN = 1e5 + 10; // Max number of elements
const int ML = 18; // ceil(log2(MN));

struct st_max {
  int data[MN];
  int M[MN][ML];
  int n;

  void init(vector<int> &d) {
    n = d.size();
    for (int i = 0; i < n; ++i)
      data[i] = d[i];

    build();
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = max(M[i][j - 1], M[i + q][j - 1]);
  }
  int query(int b, int e) {
    int k = log2(e - b + 1);
    return max(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};

struct st_gcd {
  int data[MN];
  int M[MN][ML];
  int n;

  void init(vector<int> &d) {
    n = d.size();
    for (int i = 0; i < n; ++i)
      data[i] = abs(d[i]);

    build();
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = data[i];
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i)
        M[i][j] = __gcd(M[i][j - 1], M[i + q][j - 1]);
  }

  int query(int b, int e) {
    int k = log2(e - b + 1);
    return __gcd(M[b][k], M[e + 1 - (1<<k)][k]);
  }
};

struct st_sum {
  int data[MN];
  long long M[MN];
  int n;

  void init(vector<int> &d) {
    n = d.size();
    for (int i = 0; i < n; ++i)
      data[i] = d[i];

    build();
  }

  void build() {
    for (int i = 0; i < n; ++i) {
      M[i] = data[i];
      if (i) M[i] += M[i - 1];
    }
  }

  long long query(int b, int e) {
    long long ans = M[e];
    if (b)
      return ans - M[b - 1];
    return ans;
  }
};


st_max mmax;
st_gcd ggcd;
st_sum ssum;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;


  mmax.init(a);
  ggcd.init(a);
  ssum.init(a);

  long long best = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long long a = ggcd.query(i, j);
      long long b = ssum.query(i, j);
      long long c = mmax.query(i, j);

      // cout << a << " " << b << " " << c << " " << a * (b - c) << endl;
      best = max(best, a * (b - c));
    }
  }

  cout << best << endl;
  return 0;
}
