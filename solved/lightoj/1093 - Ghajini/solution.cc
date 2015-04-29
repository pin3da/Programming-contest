using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

vector<int> sliding_window_minmax(vector<int> & ARR, int K, bool mx) {
  deque< pair<int, int> > window;
  vector<int> ans;
  for (int i = 0; i < ARR.size(); i++) {
    if (mx) {
      while (!window.empty() && window.back().first <= ARR[i])
        window.pop_back();
    } else {
      while (!window.empty() && window.back().first >= ARR[i])
        window.pop_back();
    }
    window.push_back(make_pair(ARR[i], i));

    while(window.front().second <= i - K)
      window.pop_front();

    ans.push_back(window.front().first);
  }
  return ans;
}

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> num(n);
  for (int i = 0; i < n; ++i) {
    cin >> num[i];
  }

  vector<int> mmin = sliding_window_minmax(num, d, false);
  vector<int> mmax = sliding_window_minmax(num, d, true);

  int best = 0;
  for (int i = 0; i < mmin.size(); ++i)
    best = max(best, mmax[i] - mmin[i]);
  printf("%d\n", best);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
