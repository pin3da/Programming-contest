using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

// determine if line segment from a to b intersects with 
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}
typedef vector<PT> polygon;

double polarAngle( PT p ) {
    double x = p.x, y = p.y;
    if(fabs(x) <= EPS && fabs(y) <= EPS) return -1.0;
    if(fabs(x) <= EPS) return (y > EPS ? 1.0 : 3.0) * acos(0);
    double theta = atan(1.0 * y / x);
    if(x > EPS) return(y >= -EPS ? theta : (4*acos(0) + theta));
    return(2 * acos( 0 ) + theta);
}

bool pointInPoly( PT p,polygon &poly ) {
  int n = poly.size();
  double ang = 0.0;
  for(int i = n - 1, j = 0; j < n; i = j++){
    PT v( poly[i].x - p.x, poly[i].y - p.y );
    PT w( poly[j].x - p.x, poly[j].y - p.y );
    double va = polarAngle(v);
    double wa = polarAngle(w);
    double xx = wa - va;
    if(va < -0.5 || wa < -0.5 || fabs(fabs(xx)-2*acos(0)) < EPS){
        // POINT IS ON THE EDGE
        return true;
        assert( false );
        ang += 2 * acos( 0 );
        continue;
      }
    if( xx < -2 * acos( 0 ) ) ang += xx + 4 * acos( 0 );
    else if( xx > 2 * acos( 0 ) ) ang += xx - 4 * acos( 0 );
    else ang += xx;
  }
  return( ang * ang > 1.0 );
}


int p[50];

int find_set(int x){
    return (p[x]==x)? x : p[x] = find_set(p[x]);
}
void link(int i,int j){
    p[find_set(i)] = find_set(j);
}



ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

int main(){
    int n;
    string line;
    while(getline(cin,line)){
        int n = atoi(line.c_str());
        if(n==0) break;
        vector<polygon> pols;

        while(n--){
            getline(cin,line);
            polygon act;
            stringstream ss(line);
            int x,y;
            while(ss>>x>>y)act.push_back(PT(x,y));
            pols.push_back(act);
        }

        for(int i = 0; i < pols.size(); ++i) p[i] = i;
        
        for(int i = 0; i < pols.size(); ++i){
            for(int j = i+1; j < pols.size(); ++j){
                
                int na = pols[i].size(), nb = pols[j].size();
                for (int a = 0; a < na; ++a) {
                    if (pointInPoly(pols[i][a], pols[j])) link(i,j);
                }
                for (int a = 0; a < nb; ++a) {
                    if (pointInPoly(pols[j][a], pols[i])) link(i,j);
                }
            
                int f = 1;
                for(int a = 0; a < pols[i].size() and f; ++a){
                    for(int b = 0; b < pols[j].size() and f; ++b){
                        if(SegmentsIntersect(pols[i][a], pols[i][(a+1)%pols[i].size()],pols[j][b], pols[j][(b+1)%pols[j].size()] )){
                            link(i,j);
                            f = 0;
                        }
                    }
                }
            }
        }
        set<int> ans;
        for(int i = 0; i < pols.size(); ++i)ans.insert(find_set(i));
        cout<<ans.size()<<endl;
    }
    return 0;
}
