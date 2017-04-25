// http://codeforces.com/contest/404/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1001

double a,d, t;
int n;

void print(double d) {

  if (d <= a){
    printf("%.10lf %.10lf\n",d, 0.0);
    return;
  }
  d -= a;
  if (d <= a) {
    printf("%.10lf %.10lf\n",a, d);
    return;
  }
  d -= a;
  if (d <= a){
    printf("%.10lf %.10lf\n",a - d, a);
    return;
  }
  d -= a;
  printf("%.10lf %.10lf\n",0.0, a - d);
}

int main() {

  cin>>a>>d>>n;
  double dist = 0;
  t = 4.0*a;
  while (n--) {
    dist += d;
    dist = fmod(dist,t);
    print(dist);
  }

  return 0;
}