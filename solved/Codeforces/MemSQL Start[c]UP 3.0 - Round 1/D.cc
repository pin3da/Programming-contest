#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

double prob[1 << 7][1 << 7];

double cp(vector<int> alive, int winner) {
  if (alive.size() == 1) return 1;
  vector<int> l, r;
  int in_left = false;
  for (size_t i = 0; i < alive.size(); i++) {
    if (i < alive.size() / 2) {
      l.push_back(alive[i]);
      in_left |= alive[i] == winner;
     } else {
      r.push_back(alive[i]);
     }
  }
  double ans = 0;
  if (in_left) {
    for (auto t : r)
      ans += prob[winner][t] * cp(r, t) * cp(l, winner);
  } else {
    for (auto t : l)
      ans += prob[winner][t] * cp(l, t) * cp(r, winner);
  }
  return ans;
}

double go(vector<int> alive, int winner, int score) {
  if (alive.size() == 1) return 0;
  vector<int> l, r;
  int in_left = false;
  for (size_t i = 0; i < alive.size(); i++) {
    if (i < alive.size() / 2) {
      l.push_back(alive[i]);
      in_left |= alive[i] == winner;
     } else {
      r.push_back(alive[i]);
     }
  }
  double ans = 0;
  if (in_left) {
    for (auto t : r)
      ans = max(ans, score * prob[winner][t] * cp(r, t) * cp(l, winner) + go(l, winner, score >> 1));
  } else {
    for (auto t : l)
      ans = max(ans, score * prob[winner][t] * cp(l, t) * cp(r, winner) + go(r, winner, score >> 1));
  }
  return ans;
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  vector<int> alive;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < (1 << n); j++) {
      cin >> prob[i][j];
      prob[i][j] /= 100.0;
      debug(prob[i][j]);
    }
    alive.push_back(i);
  }

  double best = 0;
  for (int i = 0; i < (1 << n); i++) {
    best = max(best, go(alive, i, (1 << (n - 1))));
  }
  cout << best << endl;
  return 0;
}
