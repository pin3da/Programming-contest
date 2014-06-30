using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x  " = "<<(x)<<endl

int main() { ___

  int n;cin>>n;
  int acum = 0;
  int ans  = 0;
  int t;
  for (int i = 0; i < n; ++i) {
    cin>>t;
    if (t == 0) {
      ans = max(ans, acum);
      acum = 0;
    } else {
      acum++;
    }
  }

  ans = max(ans, acum);
  cout<<ans<<endl;

  return 0;
}
