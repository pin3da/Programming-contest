#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long int64;

#define MAXN 32
int64 comb[MAXN][MAXN];
int64 fac[MAXN];

void fillcomb() {
    for (int n=0; n<MAXN; n++) {
        for (int k=0; k<MAXN; k++) {
            if (n<k) {comb[n][k] = 0; continue;}
            if (k==0) {comb[n][k] = 1; continue;}
            comb[n][k] = comb[n-1][k] + comb[n-1][k-1];
        }
    }
    fac[0] = 1;
    for (int i=1; i<MAXN; i++) fac[i] = i*fac[i-1];
}

int main() {
    fillcomb();
    int tc,n,k;
    scanf("%d",&tc);
    for (int i=1; i<=tc; i++) {
        scanf("%d %d",&n,&k);
        printf("Case %d: ",i);
        if (k>n) cout << "0\n";
        else {
            int64 ans = comb[n][k] * comb[n][k] * fac[k];
            cout << ans << "\n";
        }
    }
}
