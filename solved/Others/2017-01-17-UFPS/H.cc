#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct ds {
  int size;
  int d[1000];
  void init () {
    size = 0;
    memset(d, 0, sizeof d);
  }
  void insert(int c) {
    if (d[c] == 0) size++;
    d[c]++;
  }
  void erase(int c) {
    d[c]--;
    if (d[c] == 0) size--;
  }
};

ds data;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string line;
  while (getline(cin, line) && line != "0") {
    stringstream ss(line);
    int n, m;
    ss >> m;
    getline(cin, line);
    int i = 0, j = 0;
    int best = 0;
    n = line.size();
    data.init();
    while (i < n && j < n) {
      while (j < n) {
        data.insert(line[j]);
        j++;
        if (data.size > m) break;
        best = max(best, j - i);
      }
      while (i < n && data.size > m) {
        data.erase(line[i]);
        i++;
      }
    }
    cout << best << endl;
  }
  return 0;
}
