using namespace std;
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

const double eps = 1e-6;

struct point{
  double x,y;
  int id;
  point() {}
  point(double X, double Y, int I) : x(X), y(Y), id(I) {}
};

point pivot;

inline int distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

inline double dist(const point &a, const point &b){
  return sqrt(distsqr(a, b));
}

//retorna > 0 si c esta a la izquierda del segmento AB
//retorna < 0 si c esta a la derecha del segmento AB
//retorna == 0 si c es colineal con el segmento AB
inline
double cross(const point &a, const point &b, const point &c){
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

//Self < that si esta a la derecha del segmento Pivot-That
bool angleCmp(const point &self, const point &that){
  double t = cross(pivot, that, self);
  return t > eps;
}

void solve(vector<point> &p){
  for (int i=1; i<p.size(); ++i){
    if (p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x))
      swap(p[0], p[i]);
  }

  pivot = p[0];
  // Don't re-sort the 0-point!!
  sort(p.begin()+1, p.end(), angleCmp);
}

int main(){
    int n;cin>>n;
    vector<point> points(n);
    for(int i = 0; i< n; ++i){
        cin>>points[i].x>>points[i].y;
        points[i].id = i+1;
    }
    
    solve(points);
        
    cout<<(points[0].id)<<" "<<(points[n>>1].id)<<endl;

    return 0;
}
