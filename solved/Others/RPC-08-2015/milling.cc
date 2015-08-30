using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

int main() {
  int p, s;
  cin >> p >> s;
  int x, y;
  cin >> x >> y;
  vector<vector<int> > a(p, vector<int> (x));
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < x; ++j) 
      cin >> a[i][j];
  }  
  
  int t;
  vector<int> alive(x, y);
  for (int j = 0; j < s; ++j) {
    for (int i = 0; i < x; ++i) {
      cin >> t;
      alive[i] = max(0, min(alive[i], y - t));
    }
  }


  for (int k = 0; k < p; ++k) {
    for (int j = 0; j < x; ++j) {
      a[k][j] = max(0, min(a[k][j], alive[j]));
    }
  }
  
  for (int i = 0; i < p; ++i) {
    for (int j = 0; j < x; ++j) {
      if (j) cout << " ";
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
