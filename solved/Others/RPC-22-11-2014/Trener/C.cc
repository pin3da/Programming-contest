using namespace std;
#include<bits/stdc++.h>



int ans[26];

int main() {
  int n; cin >> n;
  string line;
  for (int i = 0; i < n; ++i) {
    cin >> line;
    ans[line[0] -  'a']++;
  }
  
  int seen  = 0;
  
  for (int i = 0; i < 26; ++i) {
    if (ans[i] >= 5) {
      cout << char(i + 'a');
      seen = true;
    }
  }
 
  if (!seen)
    cout << "PREDAJA";
    
  cout << endl;
 
  
  return 0;
}
