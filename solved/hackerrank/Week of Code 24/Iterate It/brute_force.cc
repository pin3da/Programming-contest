#include <bits/stdc++.h>

using namespace std;

void debug_vec(vector<int> &t) {
  for (size_t i = 0; i < t.size(); ++i) {
    if (i) cout << ' ';
    cout << t[i];
  }
  cout << endl;
}


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 0;
  while (a.size()) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    // debug_vec(a);
    vector<int> b;
    for (size_t i = 0; i < a.size(); ++i) {
      for (size_t j = i + 1; j < a.size(); ++j) {
        if (a[j] == a[i]) continue;
        b.push_back(a[j] - a[i]);
      }
    }
    a = b;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
