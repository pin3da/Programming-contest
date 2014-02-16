using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 17

int minx, maxx, miny, maxy;

int main() { ___

  int n,m;
  cin>>n>>m;

  if(n == 0 or m == 0) {
    cout<<0<<endl;
    return 0;
  }
  vector<pair<int,int> > X[2],Y[2];
  for (int i = 0; i< n; ++i) {
    int a,b,c;cin>>a>>b>>c;
    X[0].push_back(make_pair(a,a));
    Y[0].push_back(make_pair(b, b + c));
  }

  for (int i = 0; i < m; ++i) {
    int a,b,c;cin>>a>>b>>c;
    X[1].push_back(make_pair(a, a + c));
    Y[1].push_back(make_pair(b, b));
  }


  int ans = 0;
  for(int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      minx = X[1][j].first;
      maxx = X[1][j].second;
      miny = Y[0][i].first;
      maxy = Y[0][i].second;

      int x = X[0][i].first, y = Y[1][j].first;
      if(minx <= x and x <= maxx and miny <= y and y <= maxy) {
        ans = max(ans , min(x-minx, min(maxx - x, min (y - miny, maxy - y))));
      }

    }
  }

  cout<<ans<<endl;
  return 0;
}
