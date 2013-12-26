using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 50005

int sieve[MP];
long long primes[MP];
int prime_count;

void fill_sieve(){
  fill(sieve, sieve + MP, 1);
  prime_count = 0;
  sieve[0] = sieve[1] = 0;
  for(int i = 2; i < MP; ++i){
    if(sieve[i]){
      primes[prime_count++] = i;
      for(int j = i+i; j < MP; j += i) sieve[j] = 0;
    }
  }
}

void gen_divisors(vector<long long> &p, vector<int> &e, int i, long long acum, vector<long long> &ans){
  if(i == p.size()){
    ans.push_back(acum);
    return;
  }
  for(int j = 0; j <= e[i]; ++j){
    gen_divisors(p,e,i+1,acum,ans);
    acum *= p[i];
  }
}

vector <long long> gen_divisors(long long n){
  vector<long long> p;
  vector<int> e;
  for(int i = 0; primes[i]*primes[i] <= n; ++i){
    if(n%primes[i]) continue;
    int exp = 0;
    while(n%primes[i] == 0){exp++;n/=primes[i];}
    p.push_back(primes[i]);
    e.push_back(exp);

  }
  if(n > 1) {
    p.push_back(n);
    e.push_back(1);
  }

  vector<long long> ans;
  gen_divisors(p,e,0,1LL,ans);
  return ans;

}

void solve(){
  long long p,l;
  cin>>p>>l;
  if ( p - l <= l){
    cout<<" impossible";
    return;
  }
  vector<long long> ans = gen_divisors(p-l);
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); ++i ){
    if(ans[i] <= l) continue;
    cout<<" "<<ans[i];
  }
}

int main(){ ___
  int tc;cin>>tc;
  fill_sieve();
  for(int i = 0; i< tc; ++i){
    cout<<"Case "<<(i+1)<<":";solve();
    cout<<endl;
  }

  return 0;
}
