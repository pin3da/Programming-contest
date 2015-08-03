#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


char a[6][5],b[6][5];

string solve(vector<vector<char>> &cad, vector<int> &cant, int idx, int k) {
  if (idx == 5)
    return "";

  for (int i = 0; i < cad[idx].size(); ++i) {
    if (((i + 1) * cant[idx] - 1) >= k) {
      string other = solve(cad, cant, idx + 1, k - (i * cant[idx]));
      return cad[idx][i] + other;
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

    vector<vector<char>> tot(5);
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 6; ++j) {
        for (int k = 0; k < 6; ++k) {
          if (a[j][i] == b[k][i]) {
            tot[i].push_back(a[j][i]);
          }
        }
      }
      sort(tot[i].begin(), tot[i].end());
      tot[i].erase(unique(tot[i].begin(), tot[i].end()), tot[i].end());
    }

    vector<int> cant(5);
    cant[4] = 1;
    for (int i = 3; i >= 0; --i)
      cant[i] = cant[i + 1] * tot[i + 1].size();


    if (k > cant[0] * tot[0].size()) {
      cout << "NO" << endl;
      continue;
    }
    k--;

    cout << solve(tot, cant, 0, k) << endl;
  }

  return 0;
}
