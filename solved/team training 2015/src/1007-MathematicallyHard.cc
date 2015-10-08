#include <bits/stdc++.h>
using namespace std;

const int MN = 6000010;
bool prime[MN];
unsigned long long phi[MN];

void prime_sieve() {
  for (int i = 2; i < MN; i++)
    prime[i] = true;
   
  prime[1] = false;
  for (int i = 2; i * i < MN; i++) {
    if (prime[i])
      for (int j = i * i; j < MN; j += i)
        prime[j] = false;
  }
}

void euler_sieve() {
	for (int i = 1; i < MN; i++)
		phi[i] = i;
		
	for (int i = 1; i < MN; i++) {
		if (prime[i])
			for (int j = i; j < MN; j += i)
				phi[j] -= phi[j] / i;
	}
}


int main() {
  prime_sieve();
  euler_sieve();
  
  phi[1] = 0;
  phi[2] *= phi[2];
  for (int i = 3; i < MN; i++)
  	phi[i] = phi[i] * phi[i] + phi[i - 1];
  
  int t; // cin >> t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int a, b;
    // cin >> a >> b;
    // cout << "Case " << i + 1 << ": " << phi[b] - phi[a - 1] << endl; 
    scanf("%d %d", &a, &b);
    printf("Case %d: %llu\n", i + 1, phi[b] - phi[a - 1]);
  }
  
  return 0;
}
