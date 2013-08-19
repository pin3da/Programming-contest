using namespace std;
#include <bits/stdc++.h>

const int m_prime = 775150;

char sieve[m_prime];
int primes[m_prime];
int prime_counter;


void fill_sieve(){
    prime_counter = 0;
    memset(sieve,1,sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i< m_prime; ++i){
        if(sieve[i]){
            primes[prime_counter++] = i;
            for(int j = i*i; j > 0 and j< m_prime; j+=i)
                sieve[j] = 0;
        }
    }
}

long long max_factor(long long num){
    for(int i = prime_counter -1 ; i>=0; --i)
        if(num%primes[i] == 0)
            return primes[i];
            
    return num;
}

int main(){
    fill_sieve();
    
    int ans = max_factor(600851475143);
    
    cout<<ans<<endl;
    return 0;
}
