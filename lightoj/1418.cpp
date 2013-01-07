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

typedef long long int lli;

struct point{
	lli x,y;
	point() {}
	point(lli X, lli Y) : x(X), y(Y) {}
};


lli gcd (lli a, lli b) {
  lli tmp;
  while (b) {
    a %= b;
    tmp = a;
    a = b;
    b = tmp;
  }
  return a;
}



//P es un polígono ordenado anticlockwise.
//Si es clockwise, retorna el area negativa.
//Si no esta ordenado retorna basura.
//P[0] != P[n-1]
double PolygonArea(const vector<point> &p){
  double r = 0.0;
  for (int i=0; i<p.size(); ++i){
    int j = (i+1) % p.size();
    r += p[i].x*p[j].y - p[j].x*p[i].y;
  }
  return r/2.0;
}


int main(){
	int numcas;cin>>numcas;
	for(int cid=1;cid<=numcas;++cid){
	  int n;
	  cin>>n;
	  vector<point> points(n);
	  for(int i=0;i<n;++i)
	    scanf("%lld%lld",&points[i].x,&points[i].y);
    
    lli np = n;
    for(int i=1;i<=n;++i){
      if(points[i%n].x == points[i-1].x) np+= fabs(points[i%n].y - points[i-1].y) - 1LL;
      else if(points[i%n].y == points[i-1].y) np+= fabs(points[i%n].x - points[i-1].x) - 1LL;
      else{      
        lli dx = fabs(points[i%n].x - points[i-1].x);
        lli dy = fabs(points[i%n].y - points[i-1].y);
        np += gcd(dx,dy) - 1LL;
      }
    }
	  
	  double area = PolygonArea(points);
	  lli ans = ((lli)fabs(area)) + 1LL - np/2LL;
		cout<<"Case "<<cid<<": "<<ans<<endl;
	}
	return 0;
}
