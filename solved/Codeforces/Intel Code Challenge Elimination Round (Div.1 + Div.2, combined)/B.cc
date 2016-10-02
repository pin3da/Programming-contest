#include <bits/stdc++.h>

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int isv(char c) {
  return c == 'a' || c == 'e' ||  c == 'i' ||
    c == 'o' || c == 'u' || c == 'y';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string line;
  while (getline(cin, line)) {
    int n = atoi(line.c_str());
    getline(cin, line);
    vector<int> p;
    stringstream ss(line);
    int t;
    while (ss >> t) p.push_back(t);
    int ok = true;
    for (int i = 0; i < n; ++i) {
      getline(cin, line);
      int cur = 0;
      for (int j = 0; j < line.size(); ++j)
        cur += isv(line[j]);
      ok &= cur == p[i];
    }
    puts(ok ? "YES" : "NO");

  }
  return 0;
}
