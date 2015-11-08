using namespace std;
#include <bits/stdc++.h>

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int>> task(n);
    for (auto &i : task) cin >> i.first >> i.second;
    sort(task.begin(), task.end(),
        [] (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    });

    int ans = 0;
    multiset<int, greater<int>> time;
    for (const auto &x : task) {
      auto it = time.lower_bound(x.first);
      if (it != time.end()) time.erase(it);
      if (time.size() < k) {
        time.insert(x.second);
        ++ans;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
