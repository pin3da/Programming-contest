using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

string a, b, t;


int dp[222][222];

bool go(int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (i + j == t.size())
    return dp[i][j] =  true;

  bool ans = false;
  if (i < a.size() && a[i] == t[i + j])
    ans = ans || go(i + 1, j);

  if (j < b.size() && b[j] == t[i + j])
    ans = ans || go(i, j + 1);

  return dp[i][j] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc, ds = 1;
  cin >> tc;
  while (tc --) {
    cin >> a >> b >> t;
    memset(dp, -1, sizeof dp);
    cout << "Data set " << ds << ": ";
    if (go(0, 0))
      cout << "yes" << endl;
    else
      cout << "no" << endl;
    ds++;
  }
  return 0;
}
