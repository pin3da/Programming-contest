using namespace std;
#include<cstdio>
#include<cmath>
#include<vector>
#include<cassert>
#include<iostream>
#include<algorithm>
#define D(x) cout<< #x " = "<<(x)<<endl

const double pi = acos(-1);
const double pi2 = acos(0);
const double eps = 1e-12;

typedef long long int T;
//Graham scan: Complexity: O(n log n)
struct point{
  T x,y;
  point() {}
  point(T X, T Y) : x(X), y(Y) {}
};

point pivot;

inline T distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b){
  return sqrt(distsqr(a, b));
}

inline T cross(const point &a, const point &b, const point &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

//AB dot AC
inline T dot(const point &a, const point &b, const point &c){
	return (b.x - a.x)*(c.x - a.x) + (b.y - a.y)*(c.y - a.y);
}

double ang(point &a, point &b, point &c){
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


//Self < that si esta a la derecha del segmento Pivot-That
bool angleCmp(const point &self, const point &that){
  T t = cross(pivot, that, self);
  if (t < 0) return true;
  if (t == 0){
    //Self < that si está más cerquita
    return (distsqr(pivot, self) < distsqr(pivot, that));
  }
  return false;
}

vector<point> graham(vector<point> p){
  for (int i=1; i<p.size(); ++i){
    if (p[i].y < p[0].y ||
        (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }

  pivot = p[0];
  sort(p.begin(), p.end(), angleCmp);

  vector<point> chull(p.begin(), p.begin()+3);

  for (int i=3; i<p.size(); ++i){
    while (chull.size() >= 2 &&
           cross(chull[chull.size()-2],
                 chull[chull.size()-1],
                 p[i]) <=0){
      chull.erase(chull.end() - 1);
    }
    chull.push_back(p[i]);
  }
  return chull;
}


int main(){
	int ncase;
	scanf("%d",&ncase);
	int points;
	
	for(int i = 1;i<=ncase; ++i){
		scanf("%d",&points);
		vector<point> todos(points);
		for(int j = 0;j< points ; ++j){
			scanf("%lld%lld",&todos[j].x,&todos[j].y);
		}
		double ans = 0;
		if(points > 2){
			vector<point> chull = graham(todos);		
			if(chull.size()>2){
				ans = 180;
				size_t len = chull.size();
				for(int j = 0;j<len;++j){
					double t = ang(chull[(j+1)%len],chull[(j+2)%len],chull[j]);
					ans = min(ans,t);
				}
			}
		}
		printf("Case %d: %.8lf\n",i,ans);
	}
	return 0;
}


