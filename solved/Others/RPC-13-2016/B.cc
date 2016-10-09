#include<bits/stdc++.h>

// #define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

int main() {
  // ios_base::sync_with_stdio(false); cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    string ttt; getline(cin, ttt);
    stringstream ss(ttt);
    int a, b; ss >> a >> b;
    vector<int> f(line.size());
    vector<int> len(line.size());
    f[0] = 0;
    for (int i = 1; i < (int)line.size(); ++i) {
      if (line[i] != ' ') f[i] = f[i - 1];
      else f[i] = i + 1;
    }
    int last = -1;
    
    last = line.size() + 1;
    for (int i = line.size() - 1; i >= 0; --i) {
      if (i == 0 || (line[i - 1] == ' ')) {
        len[i] = last - i;
        last = i;
      } 
    }
    
    for (int i = a; i <= b; ++i) {
      int j = 0;
      int ans = 0;
      while (j < (int)line.size()) {
        ans += len[j];
        if (j + i >= (int)line.size()) break;
        j = f[j + i];
      }
      cout << ans - 1 << endl;
    }
  }
  return 0;
}


