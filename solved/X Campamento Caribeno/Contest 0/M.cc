#include <bits/stdc++.h>

using namespace std;

void debug_out() { cerr << endl; }
template <typename H, typename... T> void debug_out(H h, T... t) {  cerr << " " << (h);  debug_out(t...); }

#ifndef LOCAL
#define endl '\n'
#define debug(...) //
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif


int MN = 10000000;

int val(int x) {
  if (x < 0)
    return x + MN;
  return x;
}
void solve() {
  int n; cin >> n;
  deque<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> q[i];
    q[i]--;
  }

  sort(q.begin(), q.end());

  int mid = (n - 1) >> 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += llabs(q[i] - q[mid]);
  }
  cout << ans << endl;
}

int main() {
#ifndef LOCAL
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  //int tc; cin >> tc;
  //while (tc--)
  solve();
  return 0;
}

