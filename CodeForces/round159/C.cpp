using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 1000

const double pi=acos(-1);

struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};



int main(){
  int n;cin>>n;
  vector<double> p(n);
  int x,y;
  For(i,n){
    cin>>x>>y;
    p[i]= atan2(y,x);
    if( p[i]< 0.0)
      p[i] = 2.0*pi + p[i];
  }
  sort(all(p));
  /*double maxdiff=-1;
  double diffacum=0.0;
  for(int i=1;i<n;++i){
    double diff = p[i]-p[i-1];
    diffacum+=diff;
    if(diff>maxdiff){
      maxdiff= diff;
    }
  }*/

  double ans = p[n-1]-p[0];
  ans = ans*180.0/pi;
  printf("%.16lf\n",ans);
  
  return 0;
}
