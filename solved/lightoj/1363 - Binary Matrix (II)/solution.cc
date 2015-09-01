using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

long long magic(vector<long long> &a, int t) {
  a[0] = 0;
  for (int i = 1; i < a.size(); ++i)
    a[i] = a[i - 1] + t - a[i];

  sort(a.begin(), a.end());
  long long ans = 0, p = (a[(a.size()) >> 1] + a[(a.size() - 1) >> 1]) >> 1;
  for (int i = 0; i < a.size(); ++i) {
    ans += fabs(a[i] - p);
  }
  return ans;
}

void solve() {
  int n, m;
  char t;
  cin >> n >> m;
  vector<long long> row(n), col(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> t;
      row[i] += (t == '1');
      col[j] += (t == '1');
    }
  }
  long long a = accumulate(row.begin(), row.end(), 0);
  long long b = accumulate(col.begin(), col.end(), 0);
  int type = 0;
  long long ans = 0;

  if ((a % n) == 0) {
    type |= 1;
    ans += magic(row, a / n);
  }

  if ((b % m) == 0) {
    type |= 2;
    ans += magic(col, b / m);
  }

  if (type == 0) {
    puts("impossible");
    return;
  }

  if (type == 1) {
    printf("row %d\n", ans);
    return;
  }

  if (type == 2) {
    printf("column %d\n", ans);
    return;
  }
  printf("both %d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
