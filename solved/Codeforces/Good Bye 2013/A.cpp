// http://codeforces.com/contest/379/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 505

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }

int main(){ ___
  int a,b;
  while(cin>>a>>b){
    int ans = a;
    int mod = 0;
    while(a >= b){
      mod = a%b;
      a/=b;
      ans+=a;
      a+=mod;
    }
    cout<<ans<<endl;
  }
  return 0;

}