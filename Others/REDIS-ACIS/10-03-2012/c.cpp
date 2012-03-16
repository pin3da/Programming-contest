using namespace std;
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>

#define MYINF 0x3fffffff
#define rep(i,n) for(int i=0; i<(n); i++)

long double powinv[17];
char buf[128];
string cad = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";   

const long double EPS = 1e-17L;
int cmp(double x, double y = 0, double tol = EPS){
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int toint(long double x) {
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

long double todouble(int x) {
    long double ans = 0;
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

 long double get(char a, int b, char c){
    int num = chartoint(a)<<12 | b << 1 | ((c=='D')?1:0);
    return todouble(num);
}


int main() {
    map< long double, string > nums;
    for (int i = 0; i < cad.size(); ++i) {
        for (int b = 0; b < (1 << 11); ++b) {
            char buf[100]; sprintf(buf, "%d", b);         
            nums[ get(cad[i], b, 'F') ] = cad.substr(i, 1) + " " + string(buf) + " F";
            nums[ get(cad[i], b, 'D') ] = cad.substr(i, 1) + " " + string(buf) + " D";                
        }
    }
    
    int casos; cin >> casos;
    while (casos--) {
        int id; long double v;
        cin >> id >> v;
        printf("%d ", id);
        if (v < -1.0 || v >= 1.0) {
            cout<<"INVALID VALUE"<<endl;
            continue;
        }
        map< long double, string >::iterator i = nums.lower_bound( v );    
        if (v >= 0 and cmp(i->first, v) != 0) i--;
        cout << i->second << endl;
    }
    
    return 0;
    
}
