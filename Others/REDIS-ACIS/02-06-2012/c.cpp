
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define rep(i,n) for (int i=0; i<(n); i++)

using namespace std;

struct Point
{
    double X, Y;
    
    Point(double x, double y) {
        X=x; Y=y;
    }

    Point() {
        X=Y=0;
    }
};

void restar(Point &ans, Point a, Point b){
    ans.X=a.X - b.X;
    ans.Y = a.Y - b.Y;
}

double dis(Point p1, Point p2) {
    return sqrt((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y));
}

double cross(Point p1, Point p2, Point p3) {
    return (p2.X-p1.X)*(p3.Y-p1.Y) - (p2.Y-p1.Y)*(p3.X-p1.X);
}

bool comp(const Point &p1, const Point &p2) {
    if(p1.Y < p2.Y) return true;
    if(p1.Y > p2.Y) return false;
    if(p1.X < p2.X) return true;
}

int getconvexhull(Point p1[], Point p2[], int n) {
    sort(p1, p1 + n, comp);
    int i;
    int top = 0;
    p2[top++] = p1[0];
    p2[top++] = p1[1];
    for (i = 2; i < n; i++)
    {
        while (top >= 2 && cross(p2[top - 2], p2[top - 1], p1[i]) <= 0)
            --top;
        p2[top++] = p1[i];
    }
    int r = top;
    for (i = n - 2; i >= 0; i--)
    {
        while (top > r && cross(p2[top - 2], p2[top - 1], p1[i]) <= 0)
            --top;
        if (i != 0)
            p2[top++] = p1[i];
    }
    return top;
}

void testCHull() {
    int n;
    Point p[20];
    Point q[20];
    scanf("%d",&n);
    rep(i,n) {
        scanf("%lf %lf",&p[i].X,&p[i].Y);
    }
    int m = getconvexhull(p,q,n);
    rep(i,m){ 
        printf("%lf %lf\n",q[i].X,q[i].Y);
    }
}

inline double Dot(const Point& a,const Point& b)                        { return (a.X*b.X) + (a.Y*b.Y); }
inline double PerpDot(const Point& a,const Point& b)                    { return (a.Y*b.X) - (a.X*b.Y); }

bool LineCollision( const Point& A1, const Point& A2,
                    const Point& B1, const Point& B2,
                    double* out = 0                            )
{
    Point a,b,c;
    restar(a,A2,A1);
    restar(b,B2,B1);

    double f = PerpDot(a,b);
    if(!f)      // lines are parallel
        return false;
    
    restar(c,B2,A2);
    double aa = PerpDot(a,c);
    double bb = PerpDot(b,c);

    if(f < 0)
    {
        if(aa > 0)     return false;
        if(bb > 0)     return false;
        if(aa < f)     return false;
        if(bb < f)     return false;
    }
    else
    {
        if(aa < 0)     return false;
        if(bb < 0)     return false;
        if(aa > f)     return false;
        if(bb > f)     return false;
    }

    if(out)
        *out = 1.0 - (aa / f);
    return true;
}

int d,p;
Point pd[4000];
Point pp[4000];
Point dch[4000];
Point pch[4000];
int nd,np;

char solve() {
    nd = getconvexhull(pd,dch,nd);
    np = getconvexhull(pp,pch,np);
    dch[nd] = dch[0];
    pch[np] = pch[0];
    rep(i,nd) {
        rep(j,np) {
            if (LineCollision(dch[i],dch[i+1],pch[j],pch[j+1])) return 0;
        }
    }
    return 1;
}

void ins(Point *a,int &top,int x, int y) {
    a[top].X=x;
    a[top].Y=y;
    top++;
}

int main() {
    int x1,y1,x2,y2,caso=1;
    while (true) {
        scanf("%d %d",&d,&p);
        if (p==0 && d==0) break;
        nd=np=0;
        rep(i,d) {            
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ins(pd,nd,x1,y1);
            ins(pd,nd,x1,y2);
            ins(pd,nd,x2,y2);
            ins(pd,nd,x2,y1);
        }
        rep(i,p) {            
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            ins(pp,np,x1,y1);
            ins(pp,np,x1,y2);
            ins(pp,np,x2,y2);
            ins(pp,np,x2,y1);
        }
        char x = solve();
        if (caso!=1) printf("\n");
        printf("Case %d: ",caso++);
        if (x) {
            printf("It is possible to separate the two groups of vendors.\n");
        } else {
            printf("It is not possible to separate the two groups of vendors.\n");
        }
    }
}

