using namespace std;
#include<bits/stdc++.h>

long long gcd(long long a, long long b) {
  while (a != 0 and b != 0) {
    if (a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

int main() {

  int tc;scanf("%d", &tc);
  while (tc--) {
    long long n,m;
    scanf("%lld%lld", &n,&m);

    long long a = (n + 1) >> 1;
    long long b = (m + 1) >> 1;
    long long c = n >> 1;
    long long d = m >> 1;

    long long num = a*d + b*c;
    long long den = n*m;

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    printf("%lld/%lld\n", num, den);
  }
  return 0;
}
