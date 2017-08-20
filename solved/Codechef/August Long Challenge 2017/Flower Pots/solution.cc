#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const long long inf = 1000000000LL;

long long cost(vector<int> &a, int i, int j) {
  long long d = llabs(a[i] - a[j]);
  return d * d;
}

long long go(vector<int> &a, int id, int b) {
  if (id == ((int)a.size() - 1)) return 0;

  if (b == 0) return inf;
  long long best = inf;
  for (int i = id + 1; i < (int)a.size(); i++) {
    best = min(best, go(a, i, b - 1) + cost(a, id, i));
  }
  return best;
}

void solve() {
  int n, b, c;
  cin >> n >> b >> c;
  c--;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  cout << go(a, 0, b) << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
