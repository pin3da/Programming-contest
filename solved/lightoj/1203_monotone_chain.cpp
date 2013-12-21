#include<cstdio>
#include<cassert>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#define D(x) cout<< #x " = "<<(x)<<endl
using namespace std;

#define REMOVE_REDUNDANT

typedef double T;

const T EPS = 1e-7;
const double pi = acos(-1);

struct PT {
  T x, y;
  PT() {}
  PT(T x, T y): x(x),
  y(y) {}
  bool operator < (const PT & rhs) const {
    return make_pair(y, x) < make_pair(rhs.y, rhs.x);
  }
  bool operator == (const PT & rhs) const {
    return make_pair(y, x) == make_pair(rhs.y, rhs.x);
  }
};

inline int distsqr(const PT &a, const PT &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const PT &a, const PT &b){
  return sqrt(distsqr(a, b));
}
/*
inline int dot(const PT &a, const PT &b, const PT &c){
	return (a.x - b.x)*(c.x - b.x) + (a.y - b.y)*(c.y - b.y);
}

inline double ang(const PT &a, const PT &b, const PT &c){
	return acos((dot(a,b,c)) / (dist(a,b)*dist(b,c)));
}*/

inline T cross(const PT &a, const PT &b, const PT &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

//AB dot AC
inline T dot(const PT &a, const PT &b, const PT &c){
	return (b.x - a.x)*(c.x - a.x) + (b.y - a.y)*(c.y - a.y);
}

double ang(PT &a, PT &b, PT &c){
	double da = dist (b,a);
	double db = dist (c,a);
	T cj = cross(a,b,c);
	T dj = dot(a,b,c);
    double dsin = cj/(da*db);
    double alpha=asin(dsin);  
  
    if (dj < 0) 
            alpha=pi-alpha;  
    return alpha*180.0/pi;
}


T cross(PT p, PT q) {
  return p.x * q.y - p.y * q.x;
}

T area2(PT a, PT b, PT c) {
  return cross(a, b) + cross(b, c) + cross(c, a);
}
#ifdef REMOVE_REDUNDANT

bool between(const PT & a, const PT & b, const PT & c) {
  return (fabs(area2(a, b, c)) < EPS && (a.x - b.x) * (c.x - b.x) <= 0 && (a.y - b.y) * (c.y - b.y) <= 0);
}
#endif

void ConvexHull(vector < PT > & pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector < PT > up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  #ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
  #endif
}


int main(){
	int ncase;
	scanf("%d",&ncase);
	int points;
	for(int i = 1;i<=ncase; ++i){
		scanf("%d",&points);
		vector<PT> todos(points);
		for(int j = 0;j< points ; ++j){
			scanf("%lf%lf",&todos[j].x,&todos[j].y);
		}
		double ans = 0.0;
		if(points > 2){
			ConvexHull(todos);
			ans = 180;
			if(todos.size()>2){
				ans = 180;
				size_t len = todos.size();
				for(int j = 0;j<len;++j){
					double t = ang(todos[(j+1)%len],todos[(j+2)%len],todos[j]);
					ans = min(ans,t);
				}
			}
		}
		printf("Case %d: %.8lf\n",i,ans);
	}
	return 0;
}

