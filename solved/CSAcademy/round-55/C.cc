#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl


long long get_parts(vector<long long> &data, long long h) {
  long long ans = 0;
  for (auto &i : data) ans += i / h;
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  long long k;
  cin >> n >> k;
  vector<long long> data(n);
  for (auto &i : data) cin >> i;

  long long total = accumulate(data.begin(), data.end(), 0LL);
  if (total < k) {
    cout << 0 << endl;
    return 0;
  }

  long long lo = 1, hi = 1e10;
  while (lo < hi) {
    long long mid = (lo + hi + 1) >> 1;
    long long parts = get_parts(data, mid);
    if (parts < k) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  cout << lo << endl;

  return 0;
}
