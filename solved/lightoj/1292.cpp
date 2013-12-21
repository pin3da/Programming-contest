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

const double eps=1e-9;

struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};


int main(){
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    int n;cin>>n;
    point p[n+1];
    for(int i=0;i<n;++i)
      cin>>p[i].x>>p[i].y;
    
    int ans = -1;
    for(int i=0;i<n;++i){
      map<double,int> m;
      for(int j=i+1;j<n;++j){
            m[((double)(p[i].x - p[j].x)/(double)(p[i].y - p[j].y))]++;
      }
      int tmp = -1;
      foreach(x,m) tmp = max(tmp,x->second);
      ans = max(ans,tmp);
    }
    ans++;    
    cout<<"Case "<<cid<<": "<<((n==1)?1:ans)<<endl;
  }
  return 0;
}
