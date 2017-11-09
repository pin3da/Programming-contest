#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

bool is_in(int x, vector<int> &r) {
  for (auto i : r) {
    if (x == i) return true;
  }
  return false;
}

bool can(int x, vector<vector<int>> &cubes) {

  vector<int> order;
  vector<int> need;
  for (int i = 0; i < (int)cubes.size(); i++)
    order.push_back(i);


  while (x > 0) {
    need.push_back(x % 10);
    x /= 10;
  }

  if (order.size() < need.size()) return false;

  do {
    int all = true;
    for (int i = 0; i < (int)need.size(); i++) {
      if (!is_in(need[i], cubes[order[i]]))
        all = false;
    }
    if (all) return true;
  } while (next_permutation(order.begin(), order.end()));

  return false;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<vector<int>> cubes(n, vector<int>(6));
  for (auto &cube : cubes) {
    for (int i = 0; i < 6; i++)
      cin >> cube[i];
  }

  for (int i = 1; i < 1000; i++) {
    if (!can(i, cubes)) {
      cout << i - 1 << endl;
      return 0;
    }
  }
  return 0;
}
