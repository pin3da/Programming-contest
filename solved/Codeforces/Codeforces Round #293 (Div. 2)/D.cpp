// http://codeforces.com/contest/518/problem/D

using namespace std;
#include <bits/stdc++.h>


const int MN = 0b11111011111;
double p;
int n;
double dp[MN][MN];
double go(int t, int i) {
  if (t == 0 || i >= n)
    return 0;
  if (dp[t][i] > -0.5)
    return dp[t][i];
  return dp[t][i] = p * (go(t - 1, i + 1) + 1)  + (1.0 - p) * go(t - 1, i);
}

int main() {
  int t;
  cin >> n >> p >> t;
  for (int i = 0; i < MN; i++)
    for (int j = 0; j < MN; j++)
      dp[i][j] = -1;

  cout << fixed << setprecision(10) << go(t, 0) << endl;
  return 0;
}