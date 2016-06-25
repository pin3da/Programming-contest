#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    int j = 0;
    long long total = 0;
    for (auto &i : p) {
      cin >> i.first;
      total += i.first;
      i.second = ++j;
    }
    sort(p.rbegin(), p.rend());
    if (p[0].first == p[1].first) {
      cout << "no winner" << endl;
    } else {
      if (p[0].first * 2 > total)
        cout << "majority winner " << p[0].second << endl;
      else
        cout << "minority winner " << p[0].second << endl;
    }
  }

  return 0;
}
