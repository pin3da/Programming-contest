#include<bits/stdc++.h>

// #define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

double EPS = 1e-6;

int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point(const point &p) : x(p.x), y(p.y)    {}
  point operator + (const point &p)  const { return point(x+p.x, y+p.y); }
  point operator - (const point &p)  const { return point(x-p.x, y-p.y); }
  point operator * (double c)     const { return point(x*c,   y*c  ); }
  point operator / (double c)     const { return point(x/c,   y/c  ); }
};

inline double dot(point p, point q)     { return p.x*q.x+p.y*q.y; }
inline double dist2(point p, point q)   { return dot(p-q,p-q); }
inline double cross(point p, point q)   { return p.x*q.y-p.y*q.x; }

inline point ProjectPointSegment(point a, point b, point c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  double t = dot(c - a, b - a);
  if (t * r < 0) return a;
  if (t > r) return b;
  r = dot(c-a, b-a) / r;
  return a + (b-a)*r;
}

inline double DistancePointSegment(point a, point b, point c) {
  return dist2(c, ProjectPointSegment(a, b, c));
}


const int MN = 505;
double cir[MN][MN];
int  seen[MN][MN];
int curcol = 1;

int dx[] = {0, 0, 1, 1, 1};
int dy[] = {-1, 1, -1, 1, 0};

point q[MN * MN + 100];

point A, B;
inline double lazyDist(int x, int y) {
  return DistancePointSegment(A, B, point(x, y));
}

int bfs(int x1, int y1, int x2, int y2) {
  point cur(x1, y1);
  int head = 0, tail = 0;
  q[head++] = cur;
  A = point(x1, y1);
  B = point(x2, y2);
  int ans = 0;
  seen[x1][y1] = curcol;
  while (head > tail) {
    point node = q[tail++];
    int x = node.x;
    int y = node.y;
    if (cir[x][y] > 0 && cmp(lazyDist(x, y), cir[x][y]) == -1)
      ans++;
    for (int i = 0; i < 5; ++i) {
      int nx = node.x + dx[i],
          ny = node.y + dy[i];
      if (nx >= x1 && nx < MN && ny >= 0 && ny <= MN &&
          seen[nx][ny] < curcol && lazyDist(nx, ny) < 0.9) {
        seen[nx][ny] = curcol;
        q[head++] = point(nx, ny);
      }
    }
  }
  return ans;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    memset(cir, 0, sizeof cir);
    for (int i = 0; i < n; ++i) {
      int x, y;
      float r;
      scanf("%d%d%f", &x, &y, &r);
      cir[x][y] = r * r;
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
      curcol++;
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      if (x2 < x1) {
        swap(x1, x2);
        swap(y1, y2);
      }
      if (x1 == x2) {
        int s = min(y1, y2);
        int e = max(y1, y2);
        int ans = 0;
        for (int i = s; i <= e; ++i)
          ans += cir[x1][i] > 0;
        printf("%d\n", ans);
      } else if (y1 == y2) {
        int ans = 0;
        for (int i = x1; i <= x2; ++i)
          ans += cir[i][y1] > 0;
        printf("%d\n", ans);
      } else {
        printf("%d\n", bfs(x1, y1, x2, y2));
      }
    }
  }
  return 0;
}


