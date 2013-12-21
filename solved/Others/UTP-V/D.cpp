using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

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
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

typedef long long int lli;

#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 10000; // sqrt(2^31)
const int SQRP = 100; // sqrt(MAX)
const int MAX_NP = 1000; // 1.26 * MAXP/log(MAXP)

int _c[(MAXP>>6)+1];
int primes[MAX_NP];
int nprimes;

void prime_sieve() {
    nprimes=0;
    for (int i = 3; i <= SQRP; i += 2)
        if (!IsComp(i)) for (int j = i*i; j <= MAXP; j+=i+i) SetComp(j);
    primes[nprimes++] = 2;
    for (int i=3; i <= MAXP; i+=2) if (!IsComp(i)) primes[nprimes++] = i;
}


int is_not_prime(lli n){
    for(int i = 0; i < nprimes and primes[i]*primes[i]<=n;++i){
        if(n%primes[i]==0) return primes[i];
    }
    return 0;
}

int main(){
    lli n;cin>>n;
    prime_sieve();
    int p = is_not_prime(n);
    if(p and n!=1){
        int pp = is_not_prime(n/p);
        if(!pp){
            cout<<2<<endl;
            return 0;
        }
        int ppp = is_not_prime((n/p)/pp);
        cout<<1<<endl;
        D(ppp);
        if(ppp)
            cout<<p*pp<<endl;
        else
            cout<<n/p<<endl;
    }else{
        cout<<1<<endl<<0<<endl;
    }
    
    return 0;
}
