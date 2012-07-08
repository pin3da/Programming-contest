
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define rep(i,n) for (int i=0; i<(n); i++)
#define Vect complex<double>
#define X real()
#define Y imag()
#define MAXANG 3600
#define EPSILON 1e-9
#define LESS(X,Y) ((X)<(Y) && fabs(X-Y)>EPSILON)
//#define GRAD (MAXANG/360)
//#define DBG if(0)

using namespace std;

double v;
//int ang[MAXANG];
double t[MAXANG];
const double PI = 2*acos(0);
int maxcount;double maxa;
int n,nn;

double deg10(Vect p) {
    double t = atan2(p.Y,p.X);
    double x = (t*180/PI) ;
    x = (90-x);
    if (x<0) return x+360;
    return x;
}

void inc(int &x) {
    x = (x+1)%MAXANG;
}

void solve() {
    double a=v/2.0;    
    int i=0,j=0;
    int count=0; nn=n;
    while(j<n && LESS(t[j],v)) {
        t[nn++] = t[j++]+360;
    }
    while(i<n && fabs(t[i])<EPSILON) i++;
    count = j-i;
    
    maxcount = count;
    maxa = a;
    rep(k,MAXANG) {
        a+=0.1;
        while( i<n && LESS(t[i],a-(v/2.0)) ) i++;
        while( j<nn && LESS(t[j],a+(v/2.0)) ) j++;
        count = j-i;
        double mya = (a<360) ? a : a-360;
        if ((count > maxcount) || ((count==maxcount) && (mya<maxa))) {
            maxcount = count;
            maxa = mya;
        }
    }
    
}

int main(){    
    double tx,ty;
    while (true) {
        scanf("%d",&n);
        if (n==0) break;
        //clean();
        scanf("%lf %lf %lf",&tx,&ty,&v);
        Vect cam(tx,ty);
        Vect p;
        rep(i,n){
            scanf("%lf %lf",&tx,&ty);
            Vect tmp(tx,ty);
            p = tmp - cam;
            t[i] = deg10(p);
            //ang[ti]++;
        }
        sort(t,t+n);
        solve();
        printf("Point the camera at angle %.1lf to view %d infested trees.\n",maxa,maxcount);
    } 
    return 0;
}

