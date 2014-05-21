using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 20001 * 2;
int ang[MN];

const int pi = 180000;


int main() {
  int n, r;
  int cas = 0 ;
  while (scanf("%d%d", &n,&r) == 2) {
    if (n + r == 0) break;
    int a,b;
    for (int i = 0; i < n; ++i) {
      scanf("%d.%d", &a, &b);
      ang[i] = a*1000 + b;
      ang[n+i] = ang[i] +  2 * pi;
    }
    sort(ang, ang + 2*n);

    int i = 0 , j = 0;

    long long ans = 0;
    while (i < n) {
      while ( j < 2*n and ang[j] - ang[i] <= pi)
        j++;
      j--;
      long long a = j - i; //if (ang[j] - ang[i] == pi) a--;
      ans += (a * (a - 1)) / 2;
      i++;
    }
    long long d = n;
    printf("Case %d: %lld\n", ++cas, ((d * (d - 1) * (d -2) ) / 6) - ans);
  }

  return 0;
}
