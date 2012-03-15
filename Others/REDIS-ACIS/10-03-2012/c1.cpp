#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>

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

int main() {
    rep(i,17) powinv[i] = pow(2,-i);
    int TC,tcid;
    double num;
    scanf("%d",&TC);
    rep(caso,TC) {
        scanf("%d %lf",&tcid,&num);
        if (num >= -1 && num < 1) {
            tocad(buf, toint(num));
            printf("%d %s\n",tcid,buf);
        } else {
            printf("%d INVALID VALUE\n",tcid);
        }
    }
}
