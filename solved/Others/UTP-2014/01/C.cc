using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for (typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define For(i,n) for (int i = 0; i < (n); ++i)
#define D(x) cout<<#x " = "<<(x)<<endl
#define MN 111


int main() { ___

  string cad;
  while (cin>>cad) {
    vector<char> ans;
    reverse(cad.begin(), cad.end());
    char ant = 'a';
    ant--;
    for ( int i = 0; i < cad.size(); ++i ) {
      if (cad[i] >= ant) {
        ans.push_back(cad[i]);
        ant = cad[i];
      }
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
      cout<<ans[i];
    }
    cout<<endl;

  }
  return  0;
}
