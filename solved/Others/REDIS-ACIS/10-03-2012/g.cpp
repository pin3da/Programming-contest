
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
#include <complex>
#include <iostream>

#define MYINF 0x3fffffff
#define rep(i,n) for(int i=0; i<(n); i++)
#define pdd complex<double>
#define X real()
#define Y imag()
#define DET(a,b,c,d) ((a)*(d)-(b)*(c))
#define CRAMER(a,b,x,c,d,y) (DET(x,b,y,d)/DET(a,b,c,d))

using namespace std;

pdd intersection(pdd a1, pdd a2, pdd b1, pdd b2){
    double k= CRAMER(a2.X-a1.X,b2.X-b1.X,b1.X-a1.X,a2.Y-a1.Y,b2.Y-b1.Y,b1.Y-a1.Y);
    pdd res=a1+k*(a2-a1);
    return res;
}

double area(pdd p1, pdd p2, pdd p3) {
    pdd x = p2-p1;
    pdd y = p3-p1;
    double cp = x.X*y.Y - x.Y*y.X;
    return (fabs(cp)/2.0);
}

double dist(pdd a, pdd b) {
    double dx = a.X - b.X;
    double dy = a.Y - b.Y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    pdd a,b,c,d,ap,bp,cp,dp,p1,p2,p3,p4;
    a = pdd(0,0);
    int TC, tcid;
    double x1,x2,x3,x4,x5;
    scanf("%d",&TC);
    rep(caso,TC) {
        scanf("%d %lf %lf %lf %lf %lf",&tcid,&x1,&x2,&x3,&x4,&x5);
        b = pdd(x1,0);
        c = pdd(x2,x3);
        d = pdd(x4,x5);
        dp = 0.5*(b+a);
        ap = 0.5*(b+c);
        bp = 0.5*(c+d);
        cp = 0.5*(d+a);
        p1 = intersection(d,dp,c,cp);
        p2 = intersection(c,cp,b,bp);
        p3 = intersection(a,ap,d,dp);
        p4 = intersection(a,ap,b,bp);
        double chas = area(p1,c,d)/160;
        double dave = area(a,d,p3)/160;
        double al = area(a,p4,b)/160;
        double bob = area(b,p2,c)/160;
        double emily = (area(p1,p2,p3) + area(p3,p4,p2))/160;
		double per1 = dist(p4, p2) + dist(p2, p1) + dist(p1, p3) + dist(p3, p4);        
        per1 *= 16.5;
        per1 = ceil(per1);
        printf("%d %.3lf %.3lf %.3lf %.3lf %.3lf %.0lf\n",tcid,al,bob,chas,dave,emily,per1);
    }
    return 0;
}
