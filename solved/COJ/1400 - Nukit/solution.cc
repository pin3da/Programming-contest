#include<bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

int mov[][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 1, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};

int go(int a, int b, int c, int d) {
  int cur[] = {a, b, c, d};

  int can = false;

  for (int i = 0; i < 5; ++i) {
    int all = true;
    for (int j = 0; j < 4; ++j) {
      all &= mov[i][j] <= cur[j];
    }
    if (all) {
      can |= !go(a - mov[i][0], b - mov[i][1], c - mov[i][2], d - mov[i][3]);
    }
  }
  return can;

}


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (go(a, b, c, d))
      cout << "Patrick" << endl;
    else
      cout << "Roland" << endl;
  }

  return 0;
}

