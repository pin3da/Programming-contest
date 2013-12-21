/*
Manuel Pineda,
- Combiatoria, inverso modular, teorema de euler.
*/

using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>
#define For(i,n) for(long long i =0; i<n;++i)
#define MP 1000001
#define M 1000003

long long fac[MP];

long long modpod(long long b, long long p, long long m){
	long long r=1;
	long long pow = b%m;
	while (p > 0) {
        if (p % 2 == 1)
            r = (r*pow)%m;
        pow = (pow*pow)%m;
        p >>= 1;
    }
    return r;
}


inline void fun(){
	fac[0]=1;
	for(int i =1;i<MP;++i){
		fac[i]= ((fac[i-1]%M)*(i%M))%M;
	}
}

int main(){
	fun();	
	int numcas;scanf("%d",&numcas);
	int n,k, cas=0;
	while(numcas--){
		scanf("%d %d",&n,&k);
		printf("Case %d: %d\n",++cas,(fac[n]%M*modpod((fac[k]*fac[n-k]),M-2,M))%M);
	}
		
	return 0;
}

