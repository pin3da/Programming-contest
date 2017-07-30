#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, a;
  cin >> n >> a;
  string line;
  cin >> line;
  vector<int> seen(30);
  vector<pair<int, int>> ev;
  for (int i = 0; i < n; ++i) {
    if (seen[line[i] - 'A']) continue;
    seen[line[i] - 'A'] = true;
    ev.emplace_back(i, -1);
  }

  seen.assign(30, 0);
  for (int i = n - 1; i >= 0; --i) {
    if (seen[line[i] - 'A']) continue;
    seen[line[i] - 'A'] = true;
    ev.emplace_back(i, 1);
  }

  sort(ev.begin(), ev.end());

  int best = 0;
  int total = 0;
  for (auto e : ev) {
    total -= e.second;
    best = max(best, total);
  }

  puts(best > a ? "YES" : "NO");

  return 0;
}
