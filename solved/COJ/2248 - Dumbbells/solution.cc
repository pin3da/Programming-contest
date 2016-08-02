#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;
typedef map<int, vector<int> >::iterator itmap;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, y , x;

  while (cin >> n >> m) {
    map<int, vector<int> > tmp;
    for(int i = 0; i < n; i++) {
      cin >> x >> y;
      tmp[x].push_back(y);
    }
    vector<vector<int> > ans;
    for(itmap it = tmp.begin(); it != tmp.end(); it++) {
      //if(it->second.size() >= m) {
        sort(it->second.rbegin(), it->second.rend());
        ans.push_back(it->second);
      //}
    }
    for(int i = 0; i < ans.size(); i++) {
      for(int j = 1; j < ans[i].size(); j++) {
        ans[i][j] += ans[i][j - 1];
      }
    }
    vector<bool> vis(100000, false);
    pair<long long, long long> anst = make_pair(-1, -1);
    for(int i = 0; i < ans.size(); i++) {
      if(vis[ans[i].size()]) continue;
      vector<long long> tm;
      int sup = ans[i].size();
      // cout << i << ": " << sup << " ";
      for(int j = 0; j < ans.size(); j++) {
        if(ans[j].size() >= sup) {
         // cout << ans[j][sup - 1] << " ";
          tm.push_back(ans[j][sup - 1]);
        }
      }
      // cout << endl;
      vis[sup] = true;
      sort(tm.rbegin(), tm.rend());
      long long anss = 0;
      if(tm.size() < m) continue;
      for(int j = 0; j < m; j++) {
        anss += tm[j];
      }

      pair<long long, long long> sol = make_pair(sup, anss);
      if(sol > anst) anst = sol;
    }
    if (anst.first == -1)
      cout << 0 << " " << 0 << endl;
    else
      cout << anst.first << " " << anst.second << endl;
  }

  return 0;
}
