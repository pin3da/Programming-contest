#include<bits/stdc++.h>
using namespace std;

vector<long long> fac;
const int MN = 100001;


int dp[MN];

int go(int n) {
  if (n == 0) return 0;
  int ans = MN;
  if (dp[n] != -1)
    return dp[n];
  for (int i = 0; i < fac.size(); ++i) {
    if (n - fac[i] >= 0)
      ans = min(ans, go(n - fac[i]) + 1);
  }
  return dp[n] = ans;
}

int main(){
  fac.push_back(1);
  for (int i = 1; fac.back() < MN; ++i) {
    fac.push_back(fac.back() * i);
  }

  int n;
  memset(dp, -1, sizeof dp);
  while (cin >> n) {
    cout << go(n) << endl;
  }
  return 0;
}
