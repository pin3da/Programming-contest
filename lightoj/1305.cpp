using namespace std;
#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

struct point{
	int x,y;
	point() {}
	point(int X, int Y) : x(X), y(Y) {}
};


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
	int cid=0;
	point a,b,c,d;
	while(numcas--){
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
		d.x=c.x-(b.x-a.x);
		d.y=a.y+(c.y-b.y);
		vector<point> m;
		m.push_back(a);
		m.push_back(b);
		m.push_back(c);
		m.push_back(d);
		cout<<"Case "<<++cid<<": "<<d.x<<" "<<d.y<<" "<<(int)fabs(PolygonArea(m))<<endl;
	}
	return 0;
}
