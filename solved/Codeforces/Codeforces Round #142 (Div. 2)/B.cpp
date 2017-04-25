// http://codeforces.com/contest/230/problem/B

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
 


typedef long long   i64;
typedef vector<int> IV;


    const int MAX = 1000000;  // sqrt(10^12)
    const int LMT = 1000;     // sqrt(MAX)
    int _c[(MAX>>5)+1];
    set<int> primes;
    void primeSieve() {
        SETCOMP(0); SETCOMP(1);
        for (int i = 3; i <= LMT; i += 2)
            if (!ISCOMP(i)) for (int j = i*i; j <= MAX; j+=i+i) SETCOMP(j);
        primes.insert(2);
        for (int i=3; i <= MAX; i+=2) if (!ISCOMP(i)) primes.insert(i);
    }

int main(){

	primeSieve();
 
	int s;
	i64 n;
	scanf("%d",&s);
	For(i,s){
		scanf("%I64d",&n);
		if(n==1){
			printf("NO\n");
			continue;		
		}
		double st = sqrt(n);
		if(st- (int)st  > 0.00000001){
			printf("NO\n");
		}else if(primes.count((int)st)) {
			printf("YES\n");
		}else {
			printf("NO\n");
		}


	}
	return 0;
}
