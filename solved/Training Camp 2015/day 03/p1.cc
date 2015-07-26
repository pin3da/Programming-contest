using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const int MN = 222;
const long long mod = 1000000007;
// unordered_map<long long, long long> dp;
long long d[MN];
int n;


long long dp[3][100001 + 10];
long long run(int id, int s1) {
  memset(dp, 0, sizeof dp);

  int state = 0;
  dp[state][0] = 1;
  state ^= 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int a = 0; a <= s1; ++a) {
      dp[state][a] = dp[state ^ 1][a];
      if (d[i] > 0 && d[i] <= a)
        dp[state][a] = (dp[state][a] + dp[state ^ 1][a - d[i]]) % mod;

      if (((d[i] & 1) == 0) && d[i] > 0 && (a >= (d[i] / 2)))
        dp[state][a] = (dp[state][a] + dp[state ^ 1][a - d[i] / 2]) % mod;
    }
    state ^= 1;
  }

  state ^= 1;
  return dp[state][s1];
}

//long long go(int i, int a) {
  //if (i == n)
    //return a  == 0;

  //long long state = i * 1000001LL + a;
  //if (dp.count(state))
    //return dp[state];

  //long long ans = 0;
  //if (((d[i] & 1) == 0) && d[i] > 0 && (a >= (d[i] / 2)))
    //ans = (ans + go(i + 1, a - d[i] / 2)) % mod;

  //if (a >= d[i] && d[i] > 0)
    //ans = (ans + go(i + 1, a - d[i])) % mod;
  //ans = (ans + go(i + 1, a)) % mod;

  //return dp[state] = ans % mod;
//}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int s1, s2;
  while (cin >> s1 >> s2) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> d[i];
    }
    //memset(dp, -1, sizeof dp);
    // dp.clear();
    //
    long long ans1 =  run(0, s1);
    //dp.clear();
    // long long ans2 =  go(0, s2);
    // assert(ans1 == ans2);
    cout << ans1 << endl;

  }
  return 0;
}
