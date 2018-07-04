#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  long long n, m;
  cin >> n >> m;
  vector<long long> data(n);
  vector<long long> mex(n);
  vector<long long> extra;

  for (auto &it : data) {
    cin >> it;
    if (it >= n) extra.push_back(it);
    else        mex[it] = true;
  }

  long long ans = 0;
  long long seen = 0;
  for (int i = 1; i < n && seen < m; i++) {
    if (!mex[i]) {
      ans += i;
      seen++;
    }
  }

  sort(extra.begin(), extra.end());

  long long missing = m - seen;
  long long target = n + missing - 1;

  long long sobra = 0;
  for (auto it : extra) {
    if (it > target) {
      break;
    } else {
      target++;
      sobra += it;
    }
  }

  ans += (target * (target + 1)) / 2;
  ans -= sobra;
  ans -= n * (n - 1) / 2;

  cout << ans << endl;


  return 0;
}
