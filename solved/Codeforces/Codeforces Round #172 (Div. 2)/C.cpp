// http://codeforces.com/contest/281/problem/C

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long int lli;
typedef pair<int , int> pii;

double circle_angle(double a) { return a >= 0 ? a : Pi2 + a; }

template <typename T>
struct Point {
    T x, y;
    Point() { x=y=0; }
    Point(T X, T Y) : x(X), y(Y) {}
    T distance(const Point &p) const {
        T dx = p.x - x, dy = p.y - y; return sqrt(dx*dx + dy*dy);
    }
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    bool collinear(const Point &b, const Point &c) const {
        return (b.y - y) * (c.x - x) == (c.y - y) * (b.x - x);
    }
};

struct Vector {
    double x, y;
    Vector(double X, double Y) : x(X), y(Y) {}
    Vector(const Point<double> &p) : x(p.x), y(p.y) {}
    double norm() { return sqrt(x*x + y*y); }
    double cross(const Vector &v) const { return x * v.y - y * v.x; }
    double angle(const Vector &p) const {
        return circle_angle(atan2(p.y, p.x) - atan2(y, x));
    }
    void rotate(double a) {
        double px = x, py = y;
        x = px*cos(a) - py*sin(a);
        y = px*sin(a) + py*cos(a);
    }
    double distance_line_point(Point<double> a, Point<double> p) {
        return fabs((p.x-a.x)*y - (p.y-a.y)*x) / sqrt(x*x + y*y);
    }
};



double eps = 1e-7;
 
struct point{
    double x,y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
    point sub(point a){
        return point(x - a.x,y - a.y);
    }
    point add(point a){
        return point(x + a.x,y + a.y);
    }
    double cross(point a){
        return x*a.y - y*a.x;
    }
    point multbyscalar(double ua) {
        return point(ua*x,ua*y);
    }
};
 
typedef vector<point> polygon;
 
int n,l,w;
 
vector<point> initPol(double a,double b){
    vector<point> ans(4);
    ans[0] = point(a,b);
    ans[1] = point(-a,b);
    ans[2] = point(-a,-b);
    ans[3] = point(a,-b);
    return ans;
}
 
point intersectionbtwlines(point &p1,point &p2,point &p3,point &p4){
    point p2_p1=p2.sub(p1);
    point p4_p3=p4.sub(p3);
    double den=p2_p1.cross(p4_p3);
    if (fabs(den)<eps)//the lines are parallel or coincident
        return point();
    point p1_p3=p1.sub(p3);
    double num=p4_p3.cross(p1_p3);
    double ua=num/den;
    return p2_p1.multbyscalar(ua).add(p1);
}
 
polygon sutherland_hodgman(vector<point> &line,polygon &poly, int flag){
    vector<point> output;
    point S = poly[poly.size()-1];
    for(int i=0;i<poly.size();i++){
        point E = poly[i];
        double ecross = line[1].sub(line[0]).cross(E.sub(line[0]));
        double scross = line[1].sub(line[0]).cross(S.sub(line[0]));
        if (fabs(ecross)<eps)
            output.push_back(E);
        else if (ecross*flag>eps){
            if (scross*flag<-eps){
                double den = (E.y - S.y)*(line[1].x - line[0].x) - (E.x - S.x)*(line[1].y - line[0].y);
                if(fabs(den)>eps){
                    double num = (E.x - S.x)*(line[0].y - S.y) - (E.y - S.y)*(line[0].x - S.x);
                    num/=den;
                    output.push_back(point((line[1].x-line[0].x)*num + line[0].x, (line[1].y-line[0].y)*num + line[0].y));
                }
                //output.push_back(intersectionbtwlines(line[0],line[1],S,E));
            }
            output.push_back(E);
        }
        else if(scross*flag>eps){
            double den = (E.y - S.y)*(line[1].x - line[0].x) - (E.x - S.x)*(line[1].y - line[0].y);
            if(fabs(den)>eps){
                double num = (E.x - S.x)*(line[0].y - S.y) - (E.y - S.y)*(line[0].x - S.x);
                num/=den;
                output.push_back(point((line[1].x-line[0].x)*num + line[0].x, (line[1].y-line[0].y)*num + line[0].y));
            }
            //output.push_back(intersectionbtwlines(line[0],line[1],S,E));
        }
        S = E;
    }
    return output;
}
 
vector<polygon> bisection(vector<point> &line,polygon &poly){
    polygon uno=sutherland_hodgman(line,poly,1);
    polygon dos=sutherland_hodgman(line,poly,-1);
    int amount=(uno.size()>2)?1:0;
    amount+=(dos.size()>2)?1:0;
    vector<polygon> ret(amount);
    int index=0;
    if (uno.size()>2)
        ret[index++]=uno;
    if (dos.size()>2)
        ret[index++]=dos;
    return ret;
 
}

double PolygonArea(const vector<point> &p){
  double r = 0.0;
  for (int i=0; i<p.size(); ++i){
    int j = (i+1) % p.size();
    r += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return fabs(r/2.0);
}

int main(){
	
	double h,w,n;
	while(cin>>h>>w>>n){
		n = n*pi/180.0;
		Vector a(w/2.0,h/2.0);
		Vector b(-w/2.0,h/2.0);
		Vector c(-w/2.0,-h/2.0);
		Vector d(w/2.0,-h/2.0);
		polygon poly = initPol(w/2.0,h/2.0);
		a.rotate(n);
		b.rotate(n);
		c.rotate(n);
		d.rotate(n);
		vector<polygon> ans;
    	ans.push_back(poly);
    	vector<point> line(2);
	    line[0] = point(a.x,a.y);
        line[1] = point(b.x,b.y);
        vector<polygon> tmp;
        foreach(pol,ans){
            vector<polygon> result = bisection(line,(*pol));
            for(int j=0;j<result.size();++j)
                tmp.push_back(result[j]);
        }
        ans = tmp;
       	line[0] = point(b.x,b.y);
        line[1] = point(c.x,c.y);
        tmp.clear();
        foreach(pol,ans){
            vector<polygon> result = bisection(line,(*pol));
            for(int j=0;j<result.size();++j)
                tmp.push_back(result[j]);
        }
        ans = tmp;
       line[0] = point(c.x,c.y);
        line[1] = point(d.x,d.y);
        tmp.clear();
        foreach(pol,ans){
            vector<polygon> result = bisection(line,(*pol));
            for(int j=0;j<result.size();++j)
                tmp.push_back(result[j]);
        }
        ans = tmp;
        line[0] = point(d.x,d.y);
        line[1] = point(a.x,a.y);
        tmp.clear();
        foreach(pol,ans){
            vector<polygon> result = bisection(line,(*pol));
            for(int j=0;j<result.size();++j)
                tmp.push_back(result[j]);
        }
        ans = tmp;
		
		double mio = 0;
		/*foreach(pol,ans){
			mio = max(mio,PolygonArea((*pol)));
		}*/
		mio = PolygonArea(ans[0]);
		printf("%.10lf\n",mio);
	
	}
    return 0;
}

