// http://codeforces.com/contest/467/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

int main() { ___

  int n;
  cin>>n;
  int p, q,ans = 0;
  while (n--) {
    cin>>p >>q;
    if (q - p >= 2) ans++;
  }
  cout << ans <<endl;
  return 0;
}