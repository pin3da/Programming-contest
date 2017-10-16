#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

double prob[1 << 7][1 << 7];

vector<int> get_alive(int mask, vector<int> a) {
  vector<int> ans;
  for (int i = 0; i < (int) a.size(); i += 2) {
    int j = i >> 1;
    if ((mask >> j) & 1)
      ans.push_back(a[i]);
    else
      ans.push_back(a[i + 1]);
  }
  return ans;
}

vector<double> update_carry(int mask, vector<int> a, vector<double> carry) {
  vector<double> ans = carry;
  for (int i = 0; i < (int) a.size(); i += 2) {
    int j = i >> 1;
    if ((mask >> j) & 1) {
      ans[a[i]] *= prob[a[i]][a[i + 1]] / 100.0;
      ans[a[i + 1]] = 0;
    } else {
      ans[a[i + 1]] *= prob[a[i + 1]][a[i]] / 100.0;
      ans[a[i]] = 0;
    }
  }
  return ans;
}

double compute_cost(int mask, vector<int> a, vector<double> carry, int score) {
  double ans = 0;
  for (int i = 0; i < (int) a.size(); i += 2) {
    int x = a[i], y = a[i + 1];
    int j = i >> 1;
    if ((mask >> j) & 1)
      ans += prob[x][y] / 100.0 * carry[x] * score;
    else
      ans += prob[y][x] / 100.0 * carry[y] * score;
  }
  return ans;
}

double go(int past, vector<int> alive, vector<double> carry, int score, int level) {
  if (alive.size() == 1) return 0;
  double best = 0;
  for (int mask = 0; mask < (1 << (level)); mask++) {
    auto next_carry = update_carry(mask, alive, carry);
    best = max(best, go(mask, get_alive(mask, alive), next_carry, score << 1, level - 1) + compute_cost(mask, alive, carry, score));
  }
  debug(past);
  debug(best);
  return best;
}

void printvec(auto vec) {
  for (auto i: vec) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> alive;
  vector<double> carry;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      cin >> prob[i][j];
    }
    alive.push_back(i);
    carry.push_back(1);
  }

  double best = 0;
  for (int mask = 0; mask < (1 << (n)); mask++) {
    auto next_carry = update_carry(mask, alive, carry);
    debug(compute_cost(mask, alive, carry, 1));
    printvec(next_carry);
    best = max(best, go(mask, get_alive(mask, alive), next_carry, 2, n - 1)
        + compute_cost(mask, alive, carry, 1));
  }
  cout << best << endl;
  return 0;
}
