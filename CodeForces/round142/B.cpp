using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#include<cmath>
#include<cstdio>

#define For(i,n) for(int i=0;i<(n); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)

// Number Theory
#define ISCOMP(n)  (_c[(n)>>5]&(1<<((n)&31)))
#define SETCOMP(n) _c[(n)>>5]|=(1<<((n)&31))
#define Sc(t,v) static_cast<t>(v)
#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); v++)
 


typedef long long int  i64;
typedef vector<int> IV;

namespace Num
{
    const int MAX = 1000000;  // sqrt(10^12)
    const int LMT = 1000;     // sqrt(MAX)
    int _c[(MAX>>5)+1];
    IV primes;
    void primeSieve() {
        SETCOMP(0); SETCOMP(1);
        for (int i = 3; i <= LMT; i += 2)
            if (!ISCOMP(i)) for (int j = i*i; j <= MAX; j+=i+i) SETCOMP(j);
        primes.push_back(2);
        for (int i=3; i <= MAX; i+=2) if (!ISCOMP(i)) primes.push_back(i);
    }
}
 
int ndivs(i64 n)
{
    using Num::primes;
 
    int ndiv = 1;
    int sn = Sc(int, sqrt(n));
    cFor (IV, p, primes) {
        int prime = *p;
        if (prime > sn) break; if (n % prime != 0) continue;
        int e = 0; for (; n % prime == 0; e++, n /= prime);
        ndiv *= e + 1;
        sn = Sc(int, sqrt(n));
    }
    if (n > 1) ndiv *= 2;
    return ndiv;
}

int main(){
	Num::primeSieve();
	int s;
	i64 n;
	scanf("%d",&s);
	For(i,s){
		//cin>>n;
		scanf("%I64d",&n);
		printf("%d ",ndivs(n));
		printf("%s\n",((ndivs(n)==3)?"YES":"NO"));
//		cout<<((ndivs(n)+1==3)?"YES":"NO")<<endl;
	}
	return 0;
}

