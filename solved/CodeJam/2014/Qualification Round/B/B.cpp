using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {

  int tc;cin>>tc;
  for (int tid = 0; tid < tc; ++tid) {
    double c,f,x; cin>>c>>f>>x;
    double ans = 0, cur = 2, acum = 0;

    while (true) {
      double tn = c / cur;
      tn = tn + ((x) / (cur + f));
      double tt = (x / cur);
      if (cmp (tn , tt) == -1) {
          ans += c / cur;
          cur += f;
      } else {
        ans += tt;
        break;
      }
    }
    printf("Case #%d: %.10lf\n", tid + 1, ans);
  }

  return 0;
}
