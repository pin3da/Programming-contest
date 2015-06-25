using namespace std;
#include <bits/stdc++.h>

void solve() {
  int n;
  cin >> n;
  long long mmax = 0, t;
  deque<pair<int, int> > q;
  q.push_back(make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (t > q.back().first) {
      q.push_back(make_pair(t, i));
    } else {
      int last = i;
      while (t <= q.back().first) {
        mmax = max(mmax, (long long)q.back().first * (i - q.back().second));
        last = min(last, q.back().second);
        q.pop_back();
      }
      q.push_back(make_pair(t, last));
    }
  }

  while (q.size() > 0) {
    mmax = max(mmax, (long long)q.back().first * (n - q.back().second));
    q.pop_back();
  }

  printf("%lld\n", mmax);
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
