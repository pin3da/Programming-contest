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
const int MAXP = 10000000;

int primes[MAXP];
int sieve[MAXP];
int nprimes;

void prime_sieve() {
    nprimes=0;
    memset(sieve,1,sizeof(sieve));
    sieve[0]=sieve[1]=0;
    for(int i =2 ; i<MAXP;++i){
        if(sieve[i]){
            primes[nprimes] = i;
			sieve[i] = primes[nprimes];
			nprimes++;
			
			for(int j = i+i; j< MAXP; j+=i)sieve[j]=0;
        }
    }
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
        if(!ppp)
            cout<<p*pp<<endl;
        else
            cout<<n/p<<endl;
    }else{
        cout<<1<<endl<<0<<endl;
    }
    return 0;
}
