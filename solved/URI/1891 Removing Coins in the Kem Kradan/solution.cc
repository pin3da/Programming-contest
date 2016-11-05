#include<bits/stdc++.h>
using namespace std;

int main() {
  int t, n; cin >> t;
  string s;
  while(t--) {
    cin >> n >> s;
    vector<int> ans;
    vector<bool> checked(n);
    int i = 0;
    while(i < n) {
      if(s[i] == 'D') {
        ans.push_back(i);
        checked[i] = true;
        int j = i - 1;
        while(j >= 0 && !checked[j]) {
          ans.push_back(j);
          j--;
        }
        if(i + 1 < n)
          s[i + 1] = (s[i + 1] == 'D') ? 'B' : 'D';
      }
      i++;
    }
    if(ans.size() == n) {
      cout << "Y" << endl;
      for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << ans[i] + 1;
      }
      cout << endl;
    }else{
      cout << "N" << endl;
    }
  }
  return 0;
}
