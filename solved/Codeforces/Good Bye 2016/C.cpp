// http://codeforces.com/contest/750/problem/C

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  int cur = 0;
  vector<pair<int, int> > a;
    int c, d;
  while (n--) {
    cin >> c >> d;
    a.push_back(make_pair(cur, d));
    cur += c;
  }
  sort(a.begin(), a.end());

  // for (int i = 0; i < (int)a.size(); ++i)
  //  cout << a[i].first << ' ' << a[i].second << endl;

  n = a.size();
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i + 1].second > a[i].second) {
      cout << "Impossible" << endl;
      return 0;
    }
  }

  int last = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i].second == 2)
      last = i;
  }

  if (last == -1) {
    cout << "Infinity" << endl;
    return 0;
  }

  int delta = cur - a[last].first;
  cout << 1899 + delta << endl;
  return 0;
}
