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

typedef long long int lint;

lint a,b,l;

template<class T>
string toStr(T r){stringstream m;m<<r;return m.str();}

map<lint,int> prime_factorize(lint n) {
    map<lint,int> f;
    int sn = sqrt(n);
    foreach(p, primes) {
        int prime = *p;
        if (prime > sn) break; if (n % prime) continue;
        int e = 0; for (; n % prime == 0; e++, n /= prime);
        f[prime] = e;
        sn = sqrt(n);
    }
    if (n > 1) f[n] = 1;
    
    return f;
}

string solve(){
    map<lint,int> ma = prime_factorize(a);
    map<lint,int> mb = prime_factorize(b);
    map<lint,int> ml = prime_factorize(l);
    map<lint,int> ans;
    foreach(p,ma)
        if(ml[p->first] < p->second) return "impossible";
    foreach(p,mb)
        if(ml[p->first] < p->second) return "impossible";
    
    foreach(p,ml){
        if(ma[p->first] != p->second and mb[p->first] != p->second)
            ans[p->first] = p->second;
    }
    lint ret = 1;
    foreach(p,ans){
        if(p->second)
            ret *= pow(p->first,p->second);
    }
    return toStr(ret);
}

int main(){
  prime_sieve();
  
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    cin>>a>>b>>l;
    cout<<"Case "<<cid<<": "<<solve()<<endl;
  }
  return 0;
}
