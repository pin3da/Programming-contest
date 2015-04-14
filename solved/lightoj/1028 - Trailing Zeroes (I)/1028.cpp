using namespace std;
#include<cstdio>
#include<cstring>
#include<cmath>
#define D(x) cout<< #x " = "<<x<<endl


const int LIMIT = 1000003;

int sieve[LIMIT + 1]; // Inicializar con 0’s.
int primes[LIMIT + 1];


typedef long long int lli;


int main(){

	//generate the sieve
	memset(sieve,0,sizeof(sieve));
	int primeCount = 1;
	for (int i = 2; i <= LIMIT; ++i) {
		if (!sieve[i]) {
			primes[primeCount] = i;
			sieve[i] = primeCount;
			primeCount++;
		}
		for (int j = 1; j <= sieve[i] && i * primes[j] <= LIMIT; j++){
			sieve[ i * primes[j] ] = j;
		}
	}

	
	int numcas;scanf("%d",&numcas);
	lli num;
	for(int i=1;i<=numcas;++i){
		scanf("%lli",&num);
		int ss= sqrt(num);
		int current=1,sum=1,mult=1;
		while(num>1 and primes[current]<=sqrt(num)){
			sum=1;
			if(current>=primeCount or primes[current]>sqrt(num)){
				mult*=2;
				break;
			}
			else{
				while(num%primes[current]==0){
					sum++;
					num/=primes[current];
				}
				mult*=sum;
				current++;
			}
		}
		if (num>1)mult*=2;
		printf("Case %d: %d\n",i,mult-1);
	}
}
