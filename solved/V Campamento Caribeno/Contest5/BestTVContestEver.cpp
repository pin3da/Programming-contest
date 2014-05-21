using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x) << endl

const int MN = 111;
int n,m;
int p[MN], t[MN];

const int inf = 1<<30;
double memo[111][10001];

double dp(int i, int m) {
  if (m <= 0) return 0;
  if (i == n) return 0;
  if (memo[i][m] >= 0) return memo[i][m];
  double ans = 0;
  ans +=  (1.0 + dp(i+1, m)) * (1.0 - (p[i]/100.0));
  ans +=  (1.0 + dp(i+1, m - t[i])) * (p[i]/100.0);
  return memo[i][m] = ans;
}

int main() {
  scanf("%d%d", &n,&m);
  for (int i = 0 ; i < n; ++i)
    scanf("%d", t + i);
  for (int i = 0 ; i < n; ++i)
    scanf("%d", p + i);

  for (int i = 0 ; i < 101; ++i) for (int j = 0;  j < 10001; ++j) memo[i][j] = -1;
  printf("%d\n", (int) round(dp(0,m)));
  return 0;
}
