using namespace std;
#include<bits/stdc++.h>

struct particle {
  int x;
  int v;
  particle() {}
  particle(int xx, int vv): x(xx) , v(vv) {}
};

int N;
const int MN = 105000;
particle arr[MN];
double eps = 1e-9;

double f(double t){
  double mmin = 2e100;
  double mmax = -2e100;
  for(int i = 0; i < N; i++){
    mmin = min(mmin, arr[i].x + arr[i].v * t);
    mmax = max(mmax, arr[i].x + arr[i].v * t);
  }
  return mmax - mmin;
}




int main () {

  while(scanf("%d", &N) and N) {

    for(int i = 0; i < N; i++)
      scanf("%d%d", &(arr[i].x), &(arr[i].v));

    double low = 0.0;
    double high = 2000000000.0;
    while(fabs(f(high) - f(low)) > eps){
      double delta = (high - low)/3.0;
      double x1 = low + delta;
      double x2 = high - delta;
      if (f(x1) < f(x2))
        high = x2;
      else
        low = x1;
    }

    printf("%.2lf\n", f((high + low)/2.0));
  }
}

