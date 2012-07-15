
#include <cstdio>
#include <cstdlib>
#include <cmath>
 
#define MAXN 1000005
 
using namespace std;
 
double logn[MAXN];
 
void precomp() {
    logn[0]=0;
    for (int i=1; i<MAXN; i++) {
        logn[i] = log(i) + logn[i-1];
    }
}
 
int main() {
    precomp();
    int numcas;scanf("%d",&numcas);
    int n,base,cas=0;
    while(numcas--){
        scanf("%d %d",&n,&base);
        double sum=0;
        sum = logn[n] / log(base);
        printf("Case %d: %d\n",++cas,(int)floor(sum)+1);
    }
    return 0;
}
