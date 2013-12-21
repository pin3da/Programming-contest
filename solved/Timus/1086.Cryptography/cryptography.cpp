#include <cstdio>
#include <cstring>
#define MP 200000

char sieve[MP];
int primes[20000];

void fill_sieve(){
    int primecounter = 1;
    sieve[0] = sieve[1] = 0;
//    for(int i = 4; i< MP; i+=2) sieve[i] = 0;
    primes[1] = 2;
    for(int i = 3; i< MP; i+=2){
        if(sieve[i]){
            primes[++primecounter] = i;
            if(i*i < MP and i*i > 0)
                for(int j = i*i; j < MP; j+=i) sieve[j] = 0;
        }
    }
//    printf("%d\n", primecounter);
}

int main(){
    memset(sieve,1,sizeof(sieve));
    fill_sieve();
    int n;scanf("%d",&n);
    while(n--){
        int k;scanf("%d",&k);
        printf("%d\n",primes[k]);
    }
    return 0;
}

