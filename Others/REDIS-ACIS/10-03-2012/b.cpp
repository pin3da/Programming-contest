
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MYINF 0x3fffffff
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long int dword;

using namespace std;

dword funcion(int n, int m){
    int x=n-m;
    dword ans= (((dword)x)*m)+1;
    return ans;    
}

int main() {
    int TC, tcid, n , m;
    scanf("%d",&TC);
    rep(i, TC){
        scanf("%d %d %d", &tcid, &n, &m);
        printf("%d %lld\n", tcid, funcion(n,m));
    }
}


