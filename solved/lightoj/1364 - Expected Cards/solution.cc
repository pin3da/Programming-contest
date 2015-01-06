using namespace std;
#include <bits/stdc++.h>

const double inf = 1000;
int tar[4];

double dp[14][14][14][14][3][3][3][3];
int    visited[14][14][14][14][3][3][3][3];

double go(vector<int> &state, vector<int> &jockers) {

  int a = state[0], b = state[1], c = state[2], d = state[3];
  int e = jockers[0], f = jockers[1], g = jockers[2], h = jockers[3];
  if (visited[a][b][c][d][e][f][g][h])
    return dp[a][b][c][d][e][f][g][h];

  visited[a][b][c][d][e][f][g][h] = true;

  bool win = true;
  for (int i = 0; i < 4; ++i)
    if (state[i] + jockers[i] < tar[i])
      win = false;

  if (win)
    return dp[a][b][c][d][e][f][g][h] = 0;

  double total = 54, ava_jock = 2;
  for (int i = 0; i < 4; ++i) {
    total -= state[i];
    total -= jockers[i];
    ava_jock  -= jockers[i];
  }

  double p_jocker = ava_jock / (total);
  vector<double> p(4);
  for (int i = 0; i < 4; ++i) {
    p[i] = (13 - state[i]) / total;
    if ((p[i] + p_jocker) == 0 && (tar[i] - state[i] - jockers[i]) > 0 )
      return dp[a][b][c][d][e][f][g][h] = inf;
  }

  double ans = 0;
  for (int i = 0; i < 4; ++i) {
    if (p[i] > 0) {
      state[i]++;
      ans += (go(state, jockers) + 1.0) * p[i];
      state[i]--;
    }
  }

  if (p_jocker > 0) {
    double best = inf;
    for (int i = 0; i < 4; i++) {
      jockers[i]++;
      best = min(best, go(state, jockers) + 1.0);
      jockers[i]--;
    }
    ans += best * p_jocker;
  }

  return dp[a][b][c][d][e][f][g][h] = ans;
}

bool solvable() {
  int total = 0;
  for (int i = 0; i < 4; ++i)
    total += tar[i];


  if (total > 54) return false;
  int jockers = 0;
  for (int i = 0; i < 4; ++i)
    if (tar[i] > 13) jockers += tar[i] - 13;

  return jockers < 3;
}

void solve() {
  cin >> tar[0] >> tar[1] >> tar[2] >> tar[3];

  vector<int> state(4,0), jockers(4,0);
  if (solvable()) {
    memset(visited, 0, sizeof visited);
    printf("%.10lf\n", go(state, jockers));
  } else
    printf("-1\n");
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
