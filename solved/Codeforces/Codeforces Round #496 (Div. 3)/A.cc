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

  int n;
  cin >> n;
  vector<int> ans;

  int last;
  cin >> last;
  for (int i = 1; i < n; i++) {
    int t;
    cin >> t;
    if (t <= last) {
      ans.emplace_back(last);
      last = 1;
    } else {
      last = t;
    }
  }
  ans.emplace_back(last);
  cout << ans.size() << endl;
  for (auto it : ans)
    cout << it << " ";
  cout << endl;
  return 0;
}
