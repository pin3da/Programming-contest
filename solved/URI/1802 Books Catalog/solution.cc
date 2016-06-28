#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<vector<int>> a(5);
  long long ans = 0;
  for (auto &i : a) {
    int t; cin >> t;
    i.resize(t);
    for (auto &j : i) cin >> j;
  }

  int k; cin >> k;
  int j = 0;
  long long accum = 0;
  vector<long long> tmp;
  for (auto &i1 : a[0])
  for (auto &i2 : a[1])
  for (auto &i3 : a[2])
  for (auto &i4 : a[3])
  for (auto &i5 : a[4])
    tmp.emplace_back(i1 + i2 + i3 + i4 + i5);

  sort(tmp.rbegin(), tmp.rend());

  for (int i = 0; i < k; ++i)
    accum += tmp[i];
  cout << accum << endl;
  return 0;
}
