using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1010


int primes[MN];
int sieve[MN];
int prime_counter;
int image[MN];

void fill_sieve() {
  fill(sieve, sieve + MN, 1);
  sieve[0]  = sieve[1] = prime_counter = 0;
  for (int i = 2; i < MN; ++i ) {
    if (sieve[i]) {
      primes[prime_counter++] = i;
      for (int j = i+i; j < MN; j += i){
        sieve[j] = 0;
      }
    }
  }
}


int main() { ___

  fill_sieve();

  memset(image, 0, sizeof image);

  for (int i = 0; i < prime_counter - 1; ++i) {
    int nuevo =  primes[i] + primes[i + 1] + 1;
    if (nuevo < MN and sieve[nuevo]){
      image[nuevo] = 1;
    }
  }


  for (int i = 1; i < MN; ++i) image[i] += image[i-1];

  int n, k;

  while(cin>>n>>k) {
    if (image[n] >= k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }


  return  0;
}
