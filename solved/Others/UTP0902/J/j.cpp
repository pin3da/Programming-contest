using namespace std;
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
#include<algorithm>
#define MAXP 10000000 
#define square(x) x * x
#define MOD  1000000007


int sieve[MAXP]; 
int primes[MAXP];
int veces[MAXP];

/*
exp_p: retunrs the expo of prime in num!
*/
int exp_p(long long num, int prime){
	int exp=0;	
	for(int i=1; pow(prime,(double)i) <= num ; i++)
		exp+=(num/pow(prime,(double)i));
	return exp;
}


/*
BigMod, returns b^p mod m

*/

long long bigmod(long long b,long long p,long long m) { 
  if (p == 0) 
    return 1; 
  else if (p%2 == 0) 
    return square(bigmod(b,p/2,m)) % m;
  else 
    return ((b % m) * bigmod(b,p-1,m)) % m; 
}



int main(){
	int num, ve;
	long long res,tmp;
	
	int primeCount = 1;
    for (int i = 2; i <= MAXP; ++i) {
        if (!sieve[i]) {
            primes[primeCount] = i;
            sieve[i] = primeCount;
            primeCount++;
        }

        for (int j = 1; j <= sieve[i] && i * primes[j] <= MAXP; j++){
            sieve[ i * primes[j] ] = j;
        }
    }
		
	while(cin>>num){
        if(num==0)break; 
        ve=1;
        for(int i=1;primes[i]<=num;i++){
                veces[i]=exp_p(num,primes[i]);
                ve++;
        }
        res=1;
        for(int i=1;i<ve;i++){
            res*=bigmod(primes[i],(veces[i]%2==0)?veces[i]:veces[i]-1,MOD);   
            res%=MOD;
        }
        cout<<res<<endl;

    }
	return 0;
}
