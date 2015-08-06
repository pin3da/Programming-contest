using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

bool mat[21][21];
int n;

long long dp[(1 << 20) + 10];
long long go(int mask) {

  int idx = __builtin_popcount(mask);
  if (idx == n) return 1;

  if (dp[mask] != -1)
    return dp[mask];

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (((mask >> i) & 1) == 0 && mat[idx][i]) {
      ans += go(mask | (1 << i));
    }
  }
  return dp[mask] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int c;cin>>c;

  while(c--){

    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
      }
    }

    memset(dp, -1, sizeof dp);
    cout<< go(0) << endl;
  }
  return 0;
}

