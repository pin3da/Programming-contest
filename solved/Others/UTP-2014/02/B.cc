using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 17


int main() {

  int n,d;
  cin>>n>>d;
  vector<int> manes(n);
  For(i,n) cin>>manes[i];
  int ans = 0;
  For(i,n)For(j,n)if(i!=j)if(fabs(manes[i]-manes[j]) <= d) ans++;
  cout<<ans<<endl;

  return 0;
}
