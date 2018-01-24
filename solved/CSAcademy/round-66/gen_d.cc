#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  srand(time(0));

  int n = 5;
  vector<vector<int>> b(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        b[i][i] = 1;
      else
        b[i][j] = random() % 2;
    }
  }

  random_shuffle(b.begin(), b.end());

  cout << n << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << b[i][j] << " " ;
    }
    cout << endl;
  }
  return 0;
}
