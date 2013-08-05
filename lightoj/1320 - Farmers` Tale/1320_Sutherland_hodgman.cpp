/**
* Time Limit exceeded.
*/
using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
 
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
 
const double pi=acos(-1);
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
 
vector<point> initPol(int a,int b){
    vector<point> ans(4);
    ans[0] = point(0,0);
    ans[1] = point(a,0);
    ans[2] = point(a,b);
    ans[3] = point(0,b);
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
            if (scross*flag<-eps)
                output.push_back(intersectionbtwlines(line[0],line[1],S,E));
            output.push_back(E);
        }
        else if(scross*flag>eps)
            output.push_back(intersectionbtwlines(line[0],line[1],S,E));
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
 
 
int main(){
  int numcas;cin>>numcas;
  int t1,t2,t3,t4;
  vector<point> line(2);
  for(int cid=1;cid<=numcas;++cid){
    cin>>n>>l>>w;
    polygon poly = initPol(l,w);
    vector<polygon> ans;
    ans.push_back(poly);
    for(int i=0;i<n;++i){
        cin>>t1>>t2>>t3>>t4;
        line[0] = point(t1,t2);
        line[1] = point(t3,t4);
        vector<polygon> tmp;
        foreach(pol,ans){
            vector<polygon> result = bisection(line,(*pol));
            for(int j=0;j<result.size();++j)
                tmp.push_back(result[j]);
        }
        ans = tmp;
    }
   
    cout<<"Case "<<cid<<": "<<ans.size()<<endl;
  }
  return 0;
}
     

