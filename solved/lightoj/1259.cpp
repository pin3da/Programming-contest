using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)

#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAX = 10000000; // 10^7
const int LMT = 10000; // sqrt(MAX)
int _c[(MAX>>6)+1];

vector<int> primes;

void prime_sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!IsComp(i)) for (int j = i*i; j <= MAX; j+=i+i) SetComp(j);
    primes.push_back(2);
    for (int i=3; i <= MAX; i+=2) if (!IsComp(i)) primes.push_back(i);
}
bool is_prime(int n) {
    if (n < 2 || (n > 2 && n % 2 == 0)) return false;
    return ! IsComp(n);
}

int solve(int num){
  int m = num>>1;
  int ans = 0;
  for(int i=0;i<primes.size() and primes[i]<=m;++i)
    if(is_prime(num - primes[i]))ans++;
  
  return ans;
}

int main(){
  prime_sieve();
  
  int numcas;cin>>numcas;
  int num;
  for(int cid=1;cid<=numcas;++cid){
    cin>>num;
    cout<<"Case "<<cid<<": "<<solve(num)<<endl;
  }
  return 0;
}
