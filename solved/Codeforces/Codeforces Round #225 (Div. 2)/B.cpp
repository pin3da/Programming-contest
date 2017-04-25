// http://codeforces.com/contest/384/problem/B

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl

int n,m, ord;
int nums[1010][111];


int main(){ ___
  cin>>n>>m>>ord;

  For(i,n) For(j,m) cin>>nums[i][j];

  vector<pair<int,int > > ans;

  if(ord == 0){
    For(i,m - 1){
      for(int j = i+1; j < m; ++j ){
        ans.push_back(make_pair(i,j));
      }
    }
  }else{
    for(int i = m-1; i > 0; --i){
      for(int j = i-1; j >= 0; --j ){
        ans.push_back(make_pair(i,j));
      }
    }
  }
  assert(ans.size() <= (m*(m+1)/2));
  cout<<ans.size()<<endl;
//  cout<<(m*(m-1)/2)<<endl;
  For(i,ans.size()){
    cout<<(ans[i].first +1)<<" "<<(ans[i].second + 1)<<endl;
  }

  return 0;
}
