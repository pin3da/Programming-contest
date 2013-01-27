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

typedef long long int lint;

lint x,y,xx,yy;

lint gcd(lint a,lint b){
  lint tmp;
  while(b){
    tmp = b;
    b = a%b;
    a = tmp;
  }
  return a;
}

lint solve(){
  if(x==xx) return fabs(y-yy) + 1;
  if(y==yy) return fabs(x-xx) + 1;
  lint dx = fabs(x-xx);
  lint dy = fabs(y-yy);
  return gcd(dx,dy) + 1;
}


int main(){  
  int numcas;cin>>numcas;
  for(int cid=1;cid<=numcas;++cid){
    cin>>x>>y>>xx>>yy;
    cout<<"Case "<<cid<<": "<<solve()<<endl;
  }
  return 0;
}
