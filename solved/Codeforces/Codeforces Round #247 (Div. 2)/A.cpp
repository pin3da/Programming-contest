// http://codeforces.com/contest/431/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


const int MN = 10001;


int c[4];

int main() { ___

  For(i,4)   cin>>c[i];
  string line; cin>>line;
  int ans = 0;
  For (i, line.size()) ans += c[(line[i] - '0') - 1];
  cout<<ans<<endl;

  return 0;
}

