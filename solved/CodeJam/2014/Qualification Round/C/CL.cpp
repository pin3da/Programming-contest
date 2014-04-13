using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

int r,c,m, n;

void solve() {
  n = r*c - m;

  for (int i = 1; i <= c; ++i) {
    int h = n / i;
    int k = n % i;
    if (i == 1 or h > r) continue;
    if (h == r and k > 0 ) continue;
    if (h == 1 and i <= 2) continue;
    vector<vector<char> > mat(r, vector<char>(c,'*'));

    for (int j = 0; j < h ; ++j)
      for (int jj = 0; jj < i; ++jj)
        mat[j][jj] = '.';

    for (int j = 0; j < k; ++j) {
      mat[h][j] = '.';
    }

    mat[0][0] = 'c';

    for (int j = 0; j < r; ++j) {
      for (int jj = 0; jj < c; ++jj){
        cout<<mat[j][jj];
      }
      cout<<endl;
    }
    return;
  }
  cout<<"Impossible"<<endl;
}

int main() {

  int tc;cin>>tc;
  for (int tid = 0; tid < tc; ++tid) {
    cin>>r>>c>>m;
    cout<<"Case #"<<(tid+1)<<":"<<endl;
    solve();
  }

  return 0;
}
