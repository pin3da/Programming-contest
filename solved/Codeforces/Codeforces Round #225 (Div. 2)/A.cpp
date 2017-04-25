// http://codeforces.com/contest/384/problem/A

using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for(int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl


int main(){ ___
  int n;cin>>n;

  int ans = 0;
  char m[n][n];
  For(i,n){
    For(j,n){
      if(i % 2){
        if(j%2){ m[i][j] = 'C';
          ans++;
        }
        else m[i][j] = '.';
      }else{
        if(j % 2 == 0){
          m[i][j] = 'C';
          ans ++;
        }else
          m[i][j] = '.';
      }
    }
  }
  cout<<ans<<endl;
  For(i,n){
    For(j,n){
      cout<<m[i][j];
    }
    cout<<endl;
  }

  return 0;
}
