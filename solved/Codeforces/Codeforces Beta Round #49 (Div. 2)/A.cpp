// http://codeforces.com/contest/53/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100001

int main() { ___

  string q;cin>>q;
  int n;cin>>n;
  vector<string> m(n);
  For(i, n) cin>>m[i];
  sort(m.begin(), m.end());


  For(i, n) {
    if (m[i].size() < q.size()) continue;
    if (m[i].substr(0,q.size()) == q) {
      cout<<m[i]<<endl;
      return 0;
    }
  }
  cout<<q<<endl;

  return 0;
}