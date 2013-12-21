# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <vector>
# include <iomanip>
# include <limits>
# include <map>
using namespace std;

typedef long double DOUBLE;
typedef vector<DOUBLE> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

const DOUBLE EPS = 1e-9;

struct point{
     double x;
     double y;
     point() {}
     point(double xx,double yy) : x(xx), y(yy){}
     double dist2point(const point &p){return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));}
};


double AA[1500][51];

struct LPSolver {
  int m, n;
  VI B, N;
  VVD D;

  LPSolver(const VD &b, const VD &c) : 
    m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, VD(n+2)) {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = AA[i][j];
    for (int i = 0; i < m; i++) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i]; }
    for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
    N[n] = -1; D[m+1][n] = 1;
    /*for (int i = 0; i < m+2; i++) {
     for (int j = 0; j < n+2; j++){ cout<<D[i][j]<<" ";}
     cout<<endl;
    }*/
  }
	   
  void Pivot(int r, int s) {
    for (int i = 0; i < m+2; i++) if (i != r)
      for (int j = 0; j < n+2; j++) if (j != s)
	D[i][j] -= D[r][j] * D[i][s] / D[r][s];
    for (int j = 0; j < n+2; j++) if (j != s) D[r][j] /= D[r][s];
    for (int i = 0; i < m+2; i++) if (i != r) D[i][s] /= -D[r][s];
    D[r][s] = 1.0 / D[r][s];
    swap(B[r], N[s]);
  }

  bool Simplex(int phase) {
    int x = phase == 1 ? m+1 : m;
    while (true) {
      int s = -1;
      for (int j = 0; j <= n; j++) {
	if (phase == 2 && N[j] == -1) continue;
	if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
      }
      if (D[x][s] >= -EPS) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
	if (D[i][s] <= 0) continue;
	if (r == -1 || D[i][n+1] / D[i][s] < D[r][n+1] / D[r][s] ||
	    D[i][n+1] / D[i][s] == D[r][n+1] / D[r][s] && B[i] < B[r]) r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }

  DOUBLE Solve(VD &x) {
    int r = 0;
    for (int i = 1; i < m; i++) if (D[i][n+1] < D[r][n+1]) r = i;
    if (D[r][n+1] <= -EPS) {
      Pivot(r, n);
      if (!Simplex(1) || D[m+1][n+1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
      for (int i = 0; i < m; i++) if (B[i] == -1) {
	int s = -1;
	for (int j = 0; j <= n; j++) 
	  if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
	Pivot(i, s);
      }
    }
    if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
    x = VD(n);
    for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n+1];
    return D[m][n+1];
  }
};


int main(){
     int n;
     while(cin >> n and n){
          vector<point> myGoats(n);
          for(int i = 0; i < n; ++i){
               double x,y;
               cin >> x >> y;
               myGoats[i] = (point(x,y));
          }          
          map< int, pair<int,int> > At;
          VD b;
          VD c (n,1);
          int cont = 0;
          for(int i = 0; i < n; ++i){
               for(int j = i + 1; j < n; ++j){
                    b.push_back(myGoats[i].dist2point(myGoats[j]));
                    At[cont].first = i;
                    At[cont].second = j;
                    cont += 1;
               }
          }
          
          for(int i = 0; i < b.size(); ++i) for(int j = 0; j < n; ++j) AA[i][j] = 0;
          for(int i = 0; i < b.size(); ++i){
               AA[i][At[i].first] = 1;
               AA[i][At[i].second] = 1;
          } 
          
          VD x;
          LPSolver mySolver = LPSolver( b, c);
          double d = mySolver.Solve(x);
          //double acum = 0.0;
          //for(int i = 0; i < n; ++i) acum += x[i];
          printf("%.2f\n", d);
     }
     return 0;
}

