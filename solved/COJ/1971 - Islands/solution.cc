#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while(cin >> n) {
    vector<int> islands(n + 1),newi;
    islands[0] = 0;
    vector<pair<int,int> > ord;
    for(int i = 1; i <= n; i++){
      cin >> islands[i];
      // ord[i - 1] = {islands[i], i};
    }
    newi.push_back(0);
    for(int i = 1; i <= n; i++) {
      newi.push_back(islands[i]);
      ord.push_back({islands[i], newi.size() - 1});
      while(i + 1 <= n && islands[i] == islands[i + 1]) i++;
    }
    newi.push_back(0);

    sort(ord.begin(), ord.end());
    int sol = 1, ans = 1;
    for(int i = 0; i < n; i++){
      int ma = 0, mi = 0;
      int id = ord[i].second;
      ma += newi[id] < newi[id - 1];
      ma += newi[id] < newi[id + 1];
      mi += newi[id] > newi[id - 1];
      mi += newi[id] > newi[id + 1];
      if(mi == 2) sol--;
      if(ma == 2) sol++;
      //cout << ord[i].first << " " << ord[i].second << " " << ans << endl;
      ans = max(ans, sol);
    }
    cout << ans << endl;
  }

}
