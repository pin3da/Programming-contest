using namespace std;
#include<bits/stdc++.h>


#define IsComp(n) (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
const int MAXP = 1000000000; // sqrt(2^31)
const int SQRP = 1000000000; // sqrt(MAX)
const int MAX_NP = 10000000; // 1.26 * MAXP/log(MAXP)
int _c[(MAXP>>6)+1];
int primes[MAX_NP];
int nprimes;
void prime_sieve() {
    for (int i = 3; i <= SQRP; i += 2)
        if (!IsComp(i)) for (int j = i*i; j <= MAXP; j+=i+i) SetComp(j);
    primes[nprimes++] = 2;
    for (int i=3; i <= MAXP; i+=2) if (!IsComp(i)) primes[nprimes++] = i;
}


int main() {
  prime_sieve();

  cout<<primes[nprimes - 1]<<endl;

  return 0;
}
