using namespace std;
#include<bits/stdc++.h>

struct point {
  long long x,y;
  int id;
  point(){}
  point(long long a, long long b, int c) : x(a), y(b), id(c) {}


  long long cross(const point &o) {
    return x * o.y - o.x * y;
  }

  point sub(const point &o) {
    return point(x - o.x, y - o.y, 0);
  }
};

point pivot;

inline long long int cross(const point &a, const point &b, const point &c) {
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}


inline long long int distsqr(const point &a, const point &b){
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool angleCmp(const point &self, const point &that){
  if (self.id == pivot.id) return true;
  if (that.id == pivot.id) return false;

  long long int t = cross(pivot, that, self);
  if (t < 0) return true;
  if (t == 0){
    return (distsqr(pivot, self) < distsqr(pivot, that));
  }
  return false;
}

long long int comb4(long long int  v) {
  long long int ret = v*(v - 1)*(v - 2)*(v - 3);
  return ret / 24;
}

long long int comb3(long long int v) {
  long long int ret = v*(v - 1)*(v - 2);
  return ret / 6;
}

vector<point> arr;

int nextInt() { int a; scanf("%d", &a); return a; }
long long int nextLong() {long long a; scanf("%lld", &a); return a;}

int main() {

  int N = nextInt();
  arr.resize(N);
  vector<point> c(N);
  for(int i = 0; i < N; i++) {
    arr[i] = point(nextLong(), nextLong(), i);
    c[i]   = point(arr[i].x, arr[i].y, i);
  }

  long long int print = 0;
  for (int i = 0; i < N; i++) {
    pivot = arr[i];
    sort(c.begin(), c.end(), angleCmp);
    int k = 1;
    long long int count = 0;
    for (int j = 1; j < N; j++) {
      point f = c[j];
      while ( (count < N - 1) && c[k].sub(pivot).cross(f.sub(pivot)) <= 0) {
        count++;
        k = (k == N -1)? 1: k + 1;
      }
      if (count > 1) {
        long long int side = ((count - 1)*(count - 2)) / 2;
        print += side;
      }
      count--;
    }
  }
  print -= 2*comb4(N);
  print  += 3 * comb3(N);
  printf("%.2f\n", (print + 0.0)/comb3(N));

  return 0;
}
