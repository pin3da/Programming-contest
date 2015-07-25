#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


char a[6][5],b[6][5];

void gen(vector<string> &ans, int k, string &cur) {
  if (k == 5) {
    ans.push_back(cur);
    return;
  }
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (a[i][k] == b[j][k]) {
        cur.push_back(a[i][k]);
        gen(ans, k + 1, cur);
        cur.pop_back();
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;cin>>t;
  while(t--){
    int k; cin>>k;

    for(int i = 0 ; i < 6; i++){
      for(int j = 0; j < 5; j++){
        cin>>a[i][j];
      }
    }
    for(int i = 0 ; i < 6; i++){
      for(int j = 0; j < 5; j++){
        cin>>b[i][j];
      }
    }

    vector<string> ans;
    string cur;
    gen(ans, 0, cur);

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << endl;
    }
    //if (k > ans.size())
      //cout << "NO" << endl;
    //else
      //cout << ans[k - 1] << endl;

  }

  return 0;
}


