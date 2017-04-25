// http://codeforces.com/contest/378/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 100010

template<typename T> void cmin(T& a, T b) { if (b < a) a = b; }
template<typename T> void cmax(T& a, T b) { if (a < b) a = b; }



int n;
int a[MN], b[MN];
int ans[MN][2];

int main(){ ___
    while(cin>>n){
      vector<pair<int, pair<int,int> > > all;
      for(int i = 0; i < n; ++i)cin>>a[i]>>b[i];

      for(int i = 0; i < n; ++i){
        all.push_back( make_pair(a[i], make_pair(i,0)) );
        all.push_back( make_pair(b[i], make_pair(i,1)) );
      }

      memset(ans, 0, sizeof ans);

      sort(all.begin(),all.end());

      for(int k = 0; k < n/2; ++k){
        ans[k][0] = ans[k][1] = 1;
      }

      for(int i = 0; i< n; ++i){
        ans[all[i].second.first][all[i].second.second] = 1;
      }

      for(int i = 0; i< 2; ++i){
        for(int j = 0; j < n; ++j){
          cout<<ans[j][i];
        }
        cout<<endl;
      }

    }
    return 0;
}