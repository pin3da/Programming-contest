#include<bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
  if(a.size() != b.size()) return false;
  for(int i = 0; i < a.size(); i++) {
    if(b[i] == '-') continue;
    if(b[i] != a[i]) return false;
  }
  return true;
}


int main() {
  int n, m;
  cin >> n;
  vector<string> words(n);
  for(int i = 0; i < n; i++) cin >> words[i];
  cin >> m;
  string s;
  for(int i = 0; i < m; i++) {
    cin >> s;
    int ans = 0;
    cout << "Word #" << i + 1 << ": " << s << endl;
    for(int j = 0; j < n; j++) {
      if(cmp(words[j], s)){
        cout << words[j] << endl;
        ans++;
      }
    }
    cout << "Total number of candidate words = " << ans << endl;
  }
}
