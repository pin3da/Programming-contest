// http://codeforces.com/contest/454/problem/C

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

int n,m;

int main() { ___
  cin>>m>>n;

  double mm = m, nn = n;
  double sum = 0;
  for (int i = 1; i <= m; ++i) {
    double cur = i;
    sum += (cur * ( pow(cur / mm, nn) -  pow((cur - 1.0) / mm, nn)));
  }
  printf("%.10lf\n",sum);
  return 0;
}