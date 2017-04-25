// http://codeforces.com/contest/689/problem/A

#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

pair<int, int> get_pos(int n) {
  if (n > 0 && n <= 3)
    return make_pair(0, n - 1);
  if (n > 3 && n <= 6)
    return make_pair(1, n - 4);
  if (n > 6 && n <= 9)
    return make_pair(2, n - 7);
  return make_pair(3, 1);
}

bool valid(pair<int, int> &a) {
  if (a.first >= 0 && a.first < 3 && a.second >= 0 && a.second < 3)
    return true;
  if (a.first == 3 && a.second == 1)
    return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  string line;
  while (cin >> n >> line) {
    vector<pair<int, int>> pos;
    for (auto &i : line) {
      pos.emplace_back(get_pos(i - '0'));
    }
    vector<pair<int, int>> delta;
    for (int i = 1; i < pos.size(); ++i)
      delta.emplace_back(pos[i].first - pos[i - 1].first, pos[i].second - pos[i - 1].second);

    int ways = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 3; ++j) {
        pair<int, int> cur(i, j);
        if (!valid(cur)) continue;
        int ok = true;
        for (auto d : delta) {
          cur.first += d.first;
          cur.second += d.second;
          if (!valid(cur)) {
            ok = false;
            break;
          }
        }
        ways += ok;
      }
    }
    if (ways > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
