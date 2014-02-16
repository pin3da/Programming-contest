using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 3003

long long p[MN];
int n;

long long mb[MN][MN];
long long memo[MN][MN];

long long best(int i, int j) {
  if (i >= j) return 0;
  if (mb[i][j] != -1) return mb[i][j];
  long long ans = 0;
  if (p[i] < p[j]) ans = p[j] - p[i];
  ans = max(ans, best(i + 1, j));
  ans = max(ans, best(i, j - 1));
  return mb[i][j] = ans;
}


void compute(int k, int l, int r, int opl, int opr) {

  if (r < l) return;
  int m = (l + r) >>1;
  long long ans = 0;
  int bestidx = -1;
  for(int i = max(m, opl); i <= opr; i++){
    int value = memo[i + 1][k - 1] + best(m, i);
    if (value > ans){
      ans = value;
      bestidx = i;
    }
  }
  memo[m][k] = ans;

  compute(k, l, m - 1, opl, bestidx);
  compute(k, m + 1, r, bestidx, opr);
}
/*

long long dp(int index, int k) {

  if (memo[index][k] != -1) return memo[index][k];
  if( index >= n) return 0;
  if( k <= 0) return 0;

  long long ans = 0;
  for (int i = index; i < n; ++i) {
    ans = max(ans, best(index, i) + dp(i + 1, k - 1));
  }
  return memo[index][k] = ans;
}
*/

int main() { ___

  int k;
  cin>>n>>k;

  memset(memo, 0, sizeof memo);
  memset(mb, -1, sizeof mb);

  for (int i = 0; i < n; ++i) {
    cin>>p[i];
  }

  for (int i  = 1; i <= k;  ++i) {
    compute(i, 0, n - 1, 0, n - 1);
  }

  cout<<memo[0][k]<<endl;

  return 0;
}
