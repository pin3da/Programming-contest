using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define MS 5005

char line[MS];
char line2[MS];
int n;
short _dp[MS][MS];

int lcs(char *a, char *b){
    int m = n;
    if(n==0 || m==0) return 0;
    for(int i = 0;i <= n; ++i)
        _dp[i][0] = 0;
    for(int j=0;j<=m;++j)
        _dp[0][j] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;++j)
            _dp[i][j] = ((a[i-1]==b[j-1])?(_dp[i-1][j-1]+1):(max(_dp[i][j-1],_dp[i-1][j])));

    return _dp[n][m];
}

int main(){
  scanf("%d", &n);
  scanf("%s", line);
  memset(_dp, -1, sizeof _dp);
  memcpy(line2,line,n);
  reverse(line2,line2 + n);
  printf("%d\n", n - lcs(line,line2));
  return 0;
}
