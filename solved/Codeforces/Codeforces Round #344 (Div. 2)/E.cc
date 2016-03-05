// WA

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

// RMQ.
const int MN = 200000 + 20; // Max number of elements
const int ML = 21; // ceil(log2(MN));

struct st {
  long long data[MN];
  int Mi[MN][ML];
  int Ma[MN][ML];
  int n;

  void init(vector<long long> &d) {
    n = d.size();
    for (int i = 0; i < n; ++i)
      data[i] = d[i];
  }

  void build() {
    for (int i = 0; i < n; ++i)
      Mi[i][0] = Ma[i][0] = i;
    for (int j = 1, p = 2, q = 1; p <= n; ++j, p <<= 1, q <<= 1)
      for (int i = 0; i + p - 1 < n; ++i) {
        if (data[Mi[i][j - 1]] < data[Mi[i + q][j - 1]])
          Mi[i][j] = Mi[i][j - 1];
        else
          Mi[i][j] = Mi[i + q][j - 1];
        if (data[Ma[i][j - 1]] >= data[Ma[i + q][j - 1]])
          Ma[i][j] = Ma[i][j - 1];
        else
          Ma[i][j] = Ma[i + q][j - 1];
      }
  }
  int query(int b, int e, int t = 0) {
    int k = log2(e - b + 1);
    if (t) {
      if (data[Ma[b][k]] >= data[Ma[e + 1 - (1<<k)][k]])
        return Ma[b][k];
      return Ma[e + 1 - (1<<k)][k];
    } else {
      if (data[Mi[b][k]] < data[Mi[e + 1 - (1<<k)][k]])
        return Mi[b][k];
      return Mi[e + 1 - (1<<k)][k];
    }
  }
};

long long ps[MN];

long long get_ps(int a, int b) {
  long long ans = ps[b];
  if (a)
    ans -= ps[a - 1];
  return ans;
}

st rmq;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    vector<long long> a(n);
    for (auto &i: a) cin >> i;
    ps[0] = a[0];
    for (int i = 1; i < n; ++i)
      ps[i] = ps[i - 1] + a[i];

    long long best = 0;
    for (int i = 0; i < n; ++i)
      best += a[i] * (i + 1);

    long long original = best;

    rmq.init(a);
    rmq.build();

    for (int i = 0; i < n; ++i) {
      int l = i - 1;
      int r = i + 1;
      long long cur = original;
      if (l > 0) {
        long long tmp = cur;
        int id = rmq.query(0, l, 1);
        long long dist = i - id;
        tmp += a[id] * dist;
        tmp -= get_ps(id + 1, i);
        best = max(best, tmp);
      }
      if (r < n) {
        long long tmp = cur;
        int id = rmq.query(r, n - 1, 0);
        long long dist = id - i;
        tmp -= a[id] * dist;
        tmp += get_ps(i, id - 1);
        best = max(best, tmp);
      }
    }
    cout << best << endl;
  }
  return 0;
}
