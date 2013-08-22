using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 2000001

char sieve[MP];
int primes[MP];
int prime_counter;
long long ans;

void solve(){
    prime_counter = 0;
    ans = 0;
    memset(sieve, 1, sizeof sieve);
    sieve[0] = sieve[1] = 0;
    for(int i = 2; i< MP; ++i){
        if(sieve[i]){
            primes[prime_counter++] = i;
            ans += i;
            for(int j = i+i; j < MP; j+= i)
                sieve[j] = 0;
        }
    }
}



int main(){
    solve();
    cout<<ans<<endl;
    return 0;
}
