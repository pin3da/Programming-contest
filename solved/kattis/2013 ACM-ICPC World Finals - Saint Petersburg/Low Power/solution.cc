#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

bool f(vector<int> &data, int n, int k, int delta) {
  int extra = 2 * k - 2;
  int cur = 0;
  int machines = 0;

  for (int i = 0; i + 1 < int(data.size()) && machines < n; i++) {
    if (data[i + 1] - data[i] <= delta) {
      machines++;
      cur += extra;
      i++;
    } else {
      if (!cur) {
        return false;
      } else {
        cur--;
      }
    }
  }

  return machines == n;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, k;
  cin >> n >> k;
  vector<int> data(2 * n * k);
  for (auto &i : data) cin >> i;
  sort(data.begin(), data.end());

  if (f(data, n, k, 0)) {
    cout << 0 << endl;
    return 0;
  }

  long long lo = 0, hi = int(1e9);
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (!f(data, n, k, mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  cout << lo << endl;
  return 0;
}
