#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int K, R;
const int MN = 111;
int dp[MN][MN];

int go(vector<int> &cap, vector<int> &dam, int i, int acc) {
  if (cap.size() == i) {
      return 0;
  }

  if (dp[i][acc] != -1)
    return dp[i][acc];

  int ans = go(cap, dam, i  + 1, acc);
  if (acc + cap[i] <= K)
    ans = max(ans, go(cap, dam, i + 1, acc + cap[i]) + dam[i]);

  return dp[i][acc] = ans;
}
void solve() {
  int n;
  cin >> n;
  vector<int> cap(n), dam(n);
  for (int i = 0; i < n; ++i)
    cin >> dam[i] >> cap[i];

  cin >> K >> R;
  memset(dp, -1, sizeof dp);
  int ans = go(cap, dam, 0, 0);
  if (ans >= R)
    cout << "Missao completada com sucesso" << endl;
  else
    cout << "Falha na missao" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--)
    solve();

  return 0;
}
