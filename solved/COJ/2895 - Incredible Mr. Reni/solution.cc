#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

unsigned long long pow_div_fact(unsigned long long n, unsigned long long p) {
  unsigned long long sd = 0; for (unsigned long long N=n; N; N /= p) sd += N % p; return (n-sd)/(p-1);
}


int main() {
  unsigned long long a, b, p;
  while(cin >> a >> b >> p) {
    unsigned long long ans = pow_div_fact(b , p);
    ans -= pow_div_fact(a - 1, p);
    cout << oct<< ans << endl;
  }
  return 0;
}
