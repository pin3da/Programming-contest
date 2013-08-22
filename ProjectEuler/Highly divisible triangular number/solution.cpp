using namespace std;
#include<bits/stdc++.h>
#define MP 2000001

char sieve[MP];
int primes[MP];
int prime_counter;

void fill_sieve(){
    prime_counter = 0;
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i< MP; ++i){
        if(sieve[i]){
            primes[prime_counter++] = i;
            for(int j = i+i; j < MP; j+= i)
                sieve[j] = 0;
        }
    }
}

long long triang(long long i){
    return (i*(i+1))/2;
}

int num_fact(long long n){
    int ans = 1;
    long long tope = sqrt(n);
    for(int i = 0; primes[i] < tope; ++i){
        if(n%primes[i])continue;
        int expo = 0;
        while(n%primes[i]==0){
            expo++;
            n/=primes[i];
        }
        tope = sqrt(n);
        if(expo!=0)ans*=(expo+1);
    }
    if(n>1)ans*=2;
    return ans;
}

int main(){
    long long i;
    fill_sieve();
    for(i = 5; num_fact(triang(i)) < 500  ; ++i);
    cout<<triang(i)<<endl;
    
    return 0;
}
