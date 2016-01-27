#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

void solve(int n) {
  long long mmax = 0, t;
  deque<pair<long long, int>> q;
  q.push_back(make_pair(0, 0));
  for (int i = 0; i < n; ++i) {
    cin >> t;
    if (q.empty() || t > q.back().first) {
      q.push_back(make_pair(t, i));
    } else {
      int last = i;
      while (!q.empty() && t <= q.back().first) {
        mmax = max(mmax, q.back().first * (i - q.back().second));
        last = min(last, q.back().second);
        q.pop_back();
      }
      q.push_back(make_pair(t, last));
    }
  }

  while (q.size() > 0) {
    mmax = max(mmax, q.back().first * (n - q.back().second));
    q.pop_back();
  }

  printf("%lld\n", mmax);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    solve(n);
  }
  return 0;
}
