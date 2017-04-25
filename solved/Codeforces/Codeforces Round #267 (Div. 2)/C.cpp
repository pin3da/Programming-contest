// http://codeforces.com/contest/467/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 5050;
long long num[MN];
long long sum[MN];

long long get(int i, int j) {
  long long ret = sum[j];
  if (i) ret -= sum[i- 1];
  return ret;
}

int n, m;
long long dp[MN][MN];
long long go(int i, int k) {
  if (k == 0 or (i >=  n)) return 0;

  if (dp[i][k] != -1) return dp[i][k];
  long long best = go(i+1, k);
  if (i + m < n)
    best = max(best, get(i, i + m) + go(i + m + 1, k -1));

  return dp[i][k] = best;
}

int main() { ___

  int k;
  cin>>n>>m>>k;

  for (int i = 0; i < n; ++i)
    cin>> num[i];

  sum[0] = num[0];

  for (int i = 1; i < n; ++i) {
    sum[i] = sum[i-1] + num[i];
  }

  m--;
  memset(dp, -1 , sizeof dp);
  cout << go(0, k) << endl;


  return 0;
}