#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, l; cin >> n >> l;
  deque<int> all(n);
  for (auto &i : all) cin >> i;
  all.push_front(0);
  all.push_back(l);
  sort(all.begin(), all.end());
  int m = all.size();
  double ans1 = max(all[1] - all[0], all[m - 1] - all[m - 2]);
  double ans2 = 0;

  for (int i = 0; i + 1 < (int) all.size(); i++)
    ans2 = max<double>(ans2, all[i + 1] - all[i]);
  cout << fixed << setprecision(12) << max(ans1, ans2 * 0.5) << endl;
  return 0;
}
