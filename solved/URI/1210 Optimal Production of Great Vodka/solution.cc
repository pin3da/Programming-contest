#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 2002;
int cost[MN], price[MN];

int N, T, M, P;

int dp[MN][MN];
int go(int i, int age) {
  if (i == N) return dp[i][age] = 0;

  if (dp[i][age] != -1)
    return dp[i][age];
  if (age == M) {
    return dp[i][age] = go(i + 1, 1) + P - price[age - 1] + cost[0];
  }
  int op1 = go(i + 1, 1) + P - price[age - 1] + cost[0];
  int op2 = go(i + 1, age + 1) + cost[age];
  return dp[i][age] = min(op1, op2);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  while (cin >> N >> T >> M >> P) {
    for (int i = 0; i < M; ++i)
      cin >> cost[i];
    for (int i = 0; i < M; ++i)
      cin >> price[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, T) << endl;
    int i = 0, a = T;

    vector<int> ans;
    for (int i = 0; i < MN; ++i) dp[N][i] = 0;
    while (i < N) {
      if (a == M) {
        ans.push_back(i + 1);
        a = 1;
      } else {
        int op1 = dp[i + 1][1] + P - price[a - 1] + cost[0];
        int op2 = dp[i + 1][a + 1] + cost[a];
        if (op1 <= op2) {
          ans.push_back(i + 1);
          a = 1;
        } else {
          a++;
        }
      }
      i++;
    }
    if (ans.size() == 0) {
      cout << 0 << endl;
      continue;
    }
    for (int i = 0; i < ans.size(); ++i) {
      if (i) cout << ' ';
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}
