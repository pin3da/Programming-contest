using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 1000010

const int mod = 100000007;

long long p[203800];
int c;
void gen_powers(){
  c = 0;
  for(long long i = 2; i <= 100001; ++i ){
    long long num = i*i;
    while(num <= 10000000001L){
      p[c++] = num;
      num*=i;
    }
  }
  sort(p,p+c);
  c = unique(p,p+c) - p;
  p[c++] = 10001000000;
}

long long cat[MP];
long long fac[2*MP];

long long mod_pow(int n, int m = (mod - 2)){
  long long ans = 1;
  for(long long base = n ; m ; m>>=1){
    if(m&1) ans = (ans * base)%mod;
    base = (base * base)%mod;
  }
  return ans;
}

void fill_cat(){

  fac[0] = fac[1] = 1;
  for(int i = 2; i < 2*MP; ++i)
    fac[i] = (i*fac[i-1])%mod;

  cat[0] = cat[1] = 1;
  for(int i = 2; i < MP; ++i){
    cat[i] = fac[2*i];
    long long tmp = (fac[i+1]*fac[i]) % mod;
    tmp = mod_pow(tmp);
    cat[i] = (cat[i]*tmp)%mod;
  }

}

int solve(){
  long long a,b;
  cin>>a>>b;

  int f = lower_bound(p, p+c, a) - p;
  int t = lower_bound(p, p+c, b) - p;
  if(p[t] > b) t--;

  int n = t - f + 1;
  if(!n) return 0;
  return cat[n];
}


int main(){ ___

  gen_powers();
  fill_cat();
/*
  for(int i = 0; i < 10; ++i){
    D(fac[i]);
    D(cat[i]);
  }
*/
  int tc;cin>>tc;
  for(int i = 0; i< tc; ++i)
    printf("Case %d: %d\n",i+1,solve());

  return 0;
}

