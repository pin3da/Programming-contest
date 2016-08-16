#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<int> ans;
    int t;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> t;
      t--;
      p[t] = i;
    }

    set<int> mmax;
    mmax.insert(p[0]);
    for (int i = 1; i < n; ++i) {
      set<int>::iterator it = mmax.end();
      it--;
      if (*it > p[i]) ans.push_back(i + 1);
      mmax.insert(p[i]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
      cout << ans[i] << endl;
  }
  return 0;
}
