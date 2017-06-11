#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 100000 + 10; // Max number of elements
const int ML = 18; // ceil(log2(MN));

struct st {
  int data[MN];
  int M[MN][ML];
  int n;

  void read(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i)
      cin >> data[i];
  }

  void build() {
    for (int i = 0; i < n; ++i)
      M[i][0] = i;
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i) {
        if (data[M[i][j - 1]] > data[M[i + q][j - 1]])
          M[i][j] = M[i][j - 1];
        else
          M[i][j] = M[i + q][j - 1];
      }
  }

  int query(int b, int e) {
    if (e < b) return -1;
    int k = log2(e - b + 1);
    if (data[M[b][k]] > data[M[e + 1 - (1<<k)][k]])
      return M[b][k];
    return M[e + 1 - (1<<k)][k];
  }
};

st table;

long long go(vector<long long> &acc, int a, int b) {
  int H = min(table.data[a], table.data[b]);
  int mid = table.query(a + 1, b - 1);
  if ((mid != -1) && table.data[mid] > H) {
    return go(acc, a, mid) + go(acc, mid, b);
  }
  return (acc[b] - acc[a]) * H;
}

void solve() {
  long long a, n;
  cin >> a >> n;
  vector<long long> w(n);
  vector<long long> acc(n + 2);
  for (auto &i : w) cin >> i;
  for (int i = 0; i < n; ++i) {
    acc[i + 1] = acc[i] + w[i];
  }
  table.read(n + 1);
  table.build();
  cout << a * go(acc, 0, n) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}
