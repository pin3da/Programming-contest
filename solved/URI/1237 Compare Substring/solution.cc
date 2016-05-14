#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

vector<int> compute_z(const string &s){
  int n = s.size();
  vector<int> z(n,0);
  int l,r;
  r = l = 0;
  for(int i = 1; i < n; ++i){
    if(i > r) {
      l = r = i;
      while(r < n and s[r - l] == s[r])r++;
      z[i] = r - l;r--;
    }else{
      int k = i-l;
      if(z[k] < r - i +1) z[i] = z[k];
      else {
        l = i;
        while(r < n and s[r - l] == s[r])r++;
        z[i] = r - l;r--;
      }
    }
  }
  return z;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  while (getline(cin, a) && getline(cin, b)) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      string c = a.substr(i);
      int t = c.size();
      c = c + '$' + b;
      vector<int> z = compute_z(c);
      for (int j = t; j < c.size(); ++j)
        ans = max(ans, z[j]);
    }
    cout << ans << endl;
  }
  return 0;
}
