#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

typedef long double ld;

const int N = 2 * 1e5 + 100;  // limit for array size
int n;  // array size
int t[2 * N];

void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int m;
  cout << fixed << setprecision(8);
  while (cin >> m) {
    n = m + 10;
    ld total = 0;
    memset(t, 0, sizeof t);
    int t, a, x;
    int k = 1;
    for (int i = 0; i < m; ++i) {
      cin >> t;
      if (t == 1) {
        cin >> a >> x;
        modify(0, a, x);
        total += a * x;
      } else if(t == 2) {
        cin >> a;
        modify(k, k + 1, a);
        k++;
        total += a;
      } else {
        long long last = query(k - 1);
        k--;
        modify(k, k + 1, -last);
        total -= last;
      }
      // cout << total / ld(k) << endl;
      printf("%.9lf\n", double(total / k));
    }
  }
  return 0;
}
