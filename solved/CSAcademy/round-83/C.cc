#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {
  cerr << " " << (h);
  debug_out(t...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

typedef long long int64;

const int MN = 2*1e5 + 10;
const int ML = 17;

int64 sum[MN][ML];
bool neg[MN][ML];

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#define endl '\n'
#endif

  int n;
  cin >> n;

  vector<int> sum(2 * n + 10);
  vector<int> len(2 * n + 10);

  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t == -1) sum[2 * i + 1] = sum[2 * i + 2] = 1;
    if (t == 0) sum[2 * i + 2] = -1;
    if (t == 1) sum[2 * i + 1] = sum[2 * i + 2] = -1;
  }

  int best = 0, last = 0, start = 0;

  for (int i = 0; i <= 2 * n; i++) {
    last += sum[i];
    if (last < 0) {
      last = 0;
      start = i;
    } else if (sum[i]) {
      best = max(best, i - start);
    }
  }

  cout << best / 2.0 << endl;

  return 0;
}
