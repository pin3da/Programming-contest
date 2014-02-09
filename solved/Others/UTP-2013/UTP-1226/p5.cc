using namespace std;
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define D(x) cout<< #x " = "<<(x)<<endl

int ans[12];
int frec[32];
const int inf = 999999;
int _dp[40][15];
int ni[40][15];
int nc[40][15];

int dp(int i, int cuts){
  if(i == 30) return ((cuts == 0) ? 0 : inf);
  if(cuts < 0) return inf;
  if(_dp[i][cuts] != -1) return _dp[i][cuts];
  int c = 0;
  int cur = inf;
  for(int j = i+1; j <= 30; ++j){
    c += frec[j-1] * (j - i);
    int o = dp(j , cuts-1) + c;
    if(o < cur){
      cur = o;
      ni[i][cuts] = j;
      nc[i][cuts] = cuts - 1;
    }
  }
  return _dp[i][cuts] = cur;
}

char dig[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','+','*','/','?'};

int get_id(char c){
  if(isalpha(c)) return c - 'a';
  if(c == '+') return 26;
  if(c == '*') return 27;
  if(c == '/') return 28;
  if(c == '?') return 29;
}

void solve(){
  int n;cin>>n;
  string line;
  memset(frec, 0, sizeof frec);
  for(int i = 0; i < n; ++i){
    cin>>line;
    for(int j = 0; j < line.size(); ++j)
      frec[get_id(line[j])]++;
  }

  memset(_dp, -1, sizeof _dp);
  memset(ni, -1, sizeof ni);
  memset(nc, -1, sizeof nc);
  int mm = dp(0,12);
  int i = 0;
  int c = 12;
  for(int j = 0; j< 11; ++j){
    cout<<dig[ni[i][c]];
    int ii = ni[i][c];
    int cc = nc[i][c];
    i = ii;
    c = cc;
  }
  printf("\n");
}

int main(){

  int tc;cin>>tc;
  for(int i = 0; i < tc; ++i)
    solve();
  return 0;
}
