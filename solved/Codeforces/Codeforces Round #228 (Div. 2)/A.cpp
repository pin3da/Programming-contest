// http://codeforces.com/contest/389/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MM 1000000

int gcd(int a, int b) {
  while(a > 0 and b > 0) {
    if (a>b ) a %= b;
    else b %= a;
  }
  return a+b;
}
int main() { ___

  int n;cin>>n;
  int ans  = 0;
  For (i,n) {
    int t;cin>>t;
    ans = gcd(ans,t);
  }
  cout<<ans*n<<endl;
  return 0;
}