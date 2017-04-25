// http://codeforces.com/contest/404/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 1001


char mat[MN][MN];

int main() { ___

  int n;cin>>n;
  For(i,n) For(j,n) cin>>mat[i][j];


  set<char> diag, nd;
  For(i,n) {
    diag.insert(mat[i][i]);
    diag.insert(mat[n-1-i][i]);
  }

  For(i,n) {
    mat[i][i] = 'A' ;
    mat[n-1-i][i] = 'A';
  }

  For(i,n) For(j,n) if(mat[i][j] != 'A') nd.insert(mat[i][j]);

  if(diag.size() == 1 and nd.size() == 1 and (*diag.begin()) != (*nd.begin())){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }

  return 0;
}