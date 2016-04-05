#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

vector<long long> sliding_window(vector<long long> & ARR, int K, bool mx = true) {
  deque< pair<long long, long long> > window;
  vector<long long> ans;
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
  long long n, k, s;
  cin >> n >> k >> s;
  vector<long long> a(n);
  a[0] = s;
  for (int i = 1; i < n; ++i)
    a[i] = (1LL * a[i - 1] * 1103515245LL + 12345LL) % (2147483648LL);

  /*
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  cout << endl;
  */

  vector<long long> ans = sliding_window(a, k);
  long long sum = 0;
  for (int i = k - 1; i < n; ++i)
    sum += ans[i];
  cout << sum << endl;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}

