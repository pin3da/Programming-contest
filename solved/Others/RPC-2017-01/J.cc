#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const int N = 1e6 + 100;  // limit for array size
int n;  // array size
long long t[2 * N];

// Single modification, range query.
void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

long long query(int l, int r) {  // max on interval [l, r)
  long long res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

int W[N];
int F[N];
int idx[N];

int main() {
  int k; cin >> k;
  int max_t = 0;
  for (int i = 0; i < k; ++i) {
    int t; cin >> t;
    idx[t] = i + 1;
    max_t = max(t, max_t);
    cin >> F[i + 1] >> W[i + 1];
  }

  int end = max_t + 1;
  n = max_t + 1;
  for (int i = max_t; i >= 0; --i) {
    int t_ant = i + W[idx[i]];
    long long ans = 0;
    if (t_ant >= 0) {
      ans = F[idx[i]] + query(t_ant, end);
    }
    ans = max(ans, query(i + 1, end));
    modify(i, ans);
  }

  cout << query(0, max_t + 1) << endl;

  return 0;
}
