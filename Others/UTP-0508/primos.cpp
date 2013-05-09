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
#include<cctype>

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

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

const int MP = 20000000;

int sieve[MP];
int primes[MP];
int a[MP];
int b[MP];

int fill_sieve(){
    int pcount = 0,mio = 0;
    sieve[0] = sieve[1] = 1;
    memset(sieve,0,sizeof(sieve));
    for(int i = 2 ; i < MP  and i; ++i){
        if(!sieve[i]){
            primes[pcount] =  i;
            if(pcount > 0 and (primes[pcount] - primes[pcount-1]) == 2){
                a[mio] = primes[pcount-1];
                b[mio] = primes[pcount];
                mio++;
            }
            pcount++;
            for(int j = i ; j < MP ; j += i)
                sieve[j] = 1;
        }
    }
    
    return pcount;
}

int main(){
    fill_sieve();
    int n;
    while(cin>>n){
        n--;
        cout<<"("<<a[n]<<", "<<b[n]<<")"<<endl;
        
    }
    return 0;
}
