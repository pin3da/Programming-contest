#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <cstring>

#define MYINF 0x3fffffff
#define rep(i,n) for(int i=0; i<(n); i++)

using namespace std;

double powinv[17];
char buf[128];
const char *cad = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";   

int toint(double x) {
    int ans=0;
    if (x < 0) {
        ans = 1;
        x = x + 1;
    }
    rep(i,16) {
        int e = i+1;
        ans <<= 1;
        if (x >= powinv[e]) {
            ans |= 1;
            x -= powinv[e];
        }
    }
    return ans;
}

void tocad(char *ans, int bin) {
    int x = bin;
    char primero = cad[(x >> 12)];
    x = x & ((1 << 12) - 1);
    int segundo = x >> 1;
    char tercero = (x & 1) ? 'D' : 'F';
    sprintf(ans,"%c %d %c",primero,segundo,tercero);    
}

int chartoint(char c) {
    int i=0;
    while (cad[i] != c && cad[i]!='\0') i++;
    return i;
}

double todouble(int x) {
    double ans = 0;
    rep(i,16) {
        ans /= 2;
        if (x & 1) {
            ans += 0.5;
        }     
        x >>= 1;   
    }
    if (x) return ans-1;
    return ans;
}

int mystrlen(char * cad) {
    int i=0;
    while (cad[i] != '\0') i++;
    return i;
}

void remceros(char *cad) {
    int n = mystrlen(cad);
    int i=n-1;
    while (cad[i]=='0' && cad[i-1]!='.') {
        cad[i] = '\0';
        i--;
    }    
}

int main() {
    int TC,tcid;
    char p,t; int s;
    scanf("%d",&TC);
    rep(caso,TC) {
        scanf("%d %c %d %c",&tcid,&p,&s,&t);
        int num = chartoint(p)<<12 | s << 1 | ((t=='D')?1:0);
        sprintf(buf,"%.16lf",todouble(num));
        remceros(buf);
        printf("%d %s\n",tcid, buf);
    }
}
