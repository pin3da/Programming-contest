/*
Manuel Pineda.

Basic Number Theory,  (A + B)%M = (A%M + B%M)%M
*/

using namespace std;
#include<iostream>
#include<cstdio>
#define MP 10001
#define M 10000007

int a[MP];

int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &n);
		for(int i = 6;i<=n;++i)
			a[i] = (a[i-1]%M + a[i-2]%M +a[i-3]%M + a[i-4]%M +a[i-5]%M + a[i-6]%M)%M;
        printf("Case %d: %d\n", ++caseno, a[n] % M);
    }
    return 0;
}
