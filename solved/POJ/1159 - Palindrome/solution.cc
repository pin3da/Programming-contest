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

int dp(){

  memset(_dp,0,sizeof _dp);
  for(int i = 0; i < n; ++i)
    _dp[i][1] = 1;

  for(int l = 2; l <= n; ++l){
    for(int i = 0; i + l <= n; ++i){
      _dp[i][l] = _dp[i+1][l-2] + ((line[i] == line[i + l -1])? 2: 0);
      _dp[i][l] = max( _dp[i][l], max(_dp[i+1][l-1], _dp[i][l-1]));
    }
  }

  return _dp[0][n];

}
int main(){
  scanf("%d", &n);
  scanf("%s", line);
  printf("%d\n", n - dp());
  return 0;
}
