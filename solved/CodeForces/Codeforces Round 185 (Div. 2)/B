using namespace std;
#include<bits/stdc++.h>

double pa,pb;

double solve(int t) {
  if(t == 10000) return pa;
  return pa + (1.0 - pa) * (1.0 - pb) * solve(t + 1);
}

int main() {

  double a,b,c,d;
  cin>>a>>b>>c>>d;
  pa = a/b;
  pb = c/d;

  printf("%.10lf\n",solve(0));

  return 0;
}