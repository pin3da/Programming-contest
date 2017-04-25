// http://codeforces.com/contest/262/problem/C

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
typedef long long int lli;

struct point{
  int x,y;
  point() {}
  point(int X, int Y) : x(X), y(Y) {}
};

int fun(lli a,int k){
  int m=0;
  while(a){
    int t= a%10;
    if(t==4 or t==7) m++;
    a/=10;
  }
  return m<=k;
}

int main(){
  int m;cin>>m;
  int bin[m];
  int mio = 1<<30;
  For(i,m){
    cin>>bin[i];
    if(bin[i]<mio)mio=bin[i];
  }
  
  int n;cin>>n;
  vector<int> val(n);
  For(i,n)
    cin>>val[i];
  
  sort(rall(val));
  int used[n];
  memset(used,0,sizeof(used));
  int act,uno,dos;
  int i=0,j;
  lli ans=0;
  while(i<n){
    int cuenta =0;
    int ant;
    while(cuenta < mio){
      if(i>=n)break;
      if(!used[i]){
        used[i]=1;
        ans+=val[i];
        ant=i;
        i++;
        cuenta++;
      }else{
        i++;
      }
    }
    /**
    For(h,n){
      cout<<used[h]<<" ";
    }
    cout<<endl;
  */
    j=i;
    act=val[ant];
    while(j<n){
      if(!used[j]){
        uno=val[j];
        if(uno>act)continue;
        used[j]=true;
        j++;
        break;
      }
      j++;
    }
    while(j<n){
      if(!used[j]){
        dos=val[j];
        if(dos>act)continue;
        used[j]=true;
        j++;
        break;
      }
      j++;
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
