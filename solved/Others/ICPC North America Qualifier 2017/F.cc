#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const int inf = 3000000;

string val[] = {"Forward", "Left",  "Right"};

int mx[] = {0, 1, 0, -1};
int my[] = {1, 0, -1, 0};

bool solve(vector<string> &inst, pair<int, int> pos) {
  int x = 0, y = 0, dir = 0;
  for (int i = 0; i < (int)inst.size(); i++) {
    if (inst[i] == "Forward") {
      x += mx[dir];
      y += my[dir];
    } else if (inst[i] == "Left") {
      dir--;
      if (dir < 0) dir = 3;
    } else {
      dir++;
      if (dir > 3) dir = 0;
    }
  }
  return ((x == pos.first) && (y == pos.second));
}
int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif
  int x, y, n;
  cin >> x >> y >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) cin >> s[i];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (s[i] == val[j]) continue;
      string tm = s[i];
      s[i] = val[j];
      if (solve(s, make_pair(x, y))) {
          cout << i + 1 << " " << val[j] << endl;
          return 0;
      }
      s[i] = tm;
    }
  }

  return 0;
}
