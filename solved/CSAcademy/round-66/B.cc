#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  long long x;
  cin >> n >> x;

  vector<pair<int, int>> a(n);
  for (auto &i : a) {
    cin >> i.first >> i.second;
  }
  sort(a.begin(), a.end());

  int i = 0;
  long long back = 0;
  while (i < n && a[i].first <= x) {
    back += a[i].second;
    i++;
  }

  long long best = x - back;

  for (; i < n; i++) {
    x = a[i].first;
    back += a[i].second;
    best = min(best, x - back);
  }

  cout << best << endl;
  return 0;
}
