#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool can(vector<pair<int, int>> &a, long long val) {
  for (auto i : a) {
    if (val < i.second) return false;
    val -= i.first;
  }
  return true;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  long long total = 0;
  for (auto &i : a) {
    cin >> i.second >> i.first;
    total += i.second;
  }
  sort(a.begin(), a.end());

  long long lo = 0, hi = total + 1;
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (can(a, mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << lo << endl;
  return 0;
}
