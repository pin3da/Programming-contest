using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n, q;
  cin >> n >> q;
  vector<long long> data(n);
  for (int i = 0; i < n; ++i)
    cin >> data[i];

  long long pos = 0, neg = 0;

  for (int i = 0; i < n; ++i)
    pos += data[i] * (n - i - 1);

  for (int i = 1; i < n; ++i)
    neg += i * data[i];

  int op, x, v;
  for (int i = 0; i < q; ++i) {
    cin >> op;
    if (op)
      printf("%lld\n",  pos - neg);
    else {
      cin >> x >> v;
      pos -= data[x] * (n - x - 1);
      neg -= x * data[x];
      data[x] = v;
      pos += data[x] * (n - x - 1);
      neg += x * data[x];
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d:\n", (i + 1));
    solve();
  }
  return 0;
}
