#include<bits/stdc++.h>
#define MAXPRIMES 1000010
#define target 10001

char sieve[MAXPRIMES];
int primes[MAXPRIMES];
int prime_counter;

void fill_sieve(){
    prime_counter = 0;
    
    memset(sieve,1,sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i< MAXPRIMES and prime_counter < target; ++i){
        if(sieve[i]){
            primes[prime_counter++] = i;
            if(i*i < MAXPRIMES and i*i > 0)
            for(int j = i*i; j< MAXPRIMES; j+=i)
                sieve[j] = 0;
        }
    }
}
    
int main(){
    fill_sieve();
    printf("Prime counter: %d\n",prime_counter);
    printf("%d\n",primes[target-1]);
}
