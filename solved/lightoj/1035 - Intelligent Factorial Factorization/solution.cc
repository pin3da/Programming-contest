using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int primes [] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };

int count2(int p, const int &n){
  int ans = 0;
  int t = p;
  while(t <= n){
    ans += n/t;
    t*=p;
  }
  return ans;
}

void solve(){
  int n;
  cin>>n;
  printf("%d =",n);
  int first = 1;
  for(int i = 0; primes[i] <= n ; ++i ){
    int p = primes[i];
    if(!first) printf(" *");
    first = 0;
    printf(" %d (%d)",p,count2(p,n));
  }
  puts("");
}

int main(){ ___
  int tc;cin>>tc;
  for(int i = 0; i < tc;++i){
    printf("Case %d: ",i+1);
    solve();
  }
  return 0;
}
