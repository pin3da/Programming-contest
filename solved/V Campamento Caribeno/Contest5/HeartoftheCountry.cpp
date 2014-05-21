using namespace std;
#include<bits/stdc++.h>

const int MN = 1001;
int n,k;
int c[MN];
int vivo[MN];

vector<int> g[MN];


int change() {

  for (int i  =0 ; i < n; ++i) {
    if (vivo[i]) {
      int tmp = c[i];
      for (int j = 0; j < g[i].size(); ++j) {
        if (vivo[g[i][j]])
          tmp += c[g[i][j]];
      }
      if (tmp < k) {
        vivo[i] = false;
        return true;
      }
    }
  }

  return false;
}

int main() {
  while(cin>>n>>k) {
    if (n == 0 and k == 0) break;
    for (int i = 0 ; i < MN ; ++i) {
      g[i].clear();
      vivo[i] = true;
    }
    for (int i = 0; i < n; ++i) {
      cin>>c[i];
      int t;cin>>t;
      int v;
      for (int j = 0 ; j < t; ++j)  {
        cin>>v;
        g[i].push_back(v);
      }
    }
    while (change());
    int ans = 0;
    int cuant = 0;
    for (int i = 0 ; i < n; ++i) {
      if (vivo[i]) {
        ans++;
        cuant += c[i];
      }
    }
    cout<<ans<<" "<<cuant<<endl;
  }
  return 0;
}
