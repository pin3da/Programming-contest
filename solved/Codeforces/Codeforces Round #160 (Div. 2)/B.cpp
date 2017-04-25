// http://codeforces.com/contest/262/problem/B

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
  int n,k;cin>>n>>k;
  int nums[n];
  For(i,n){
    cin>>nums[i];
  }
  int i = 0;
  while (k > 0 and nums[i] < 0){
        nums[i] *= -1;
        i++; k--;
    }
    if (k % 2 == 1){
        sort(nums,nums+n);
        nums[0] *=-1;
    }
    
  lli ans = 0;
  For(i,n){
    ans+=nums[i];
  }
  cout<<ans<<endl;
  
  return 0;
}