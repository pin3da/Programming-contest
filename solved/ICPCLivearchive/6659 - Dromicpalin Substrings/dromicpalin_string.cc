using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MP 1010

int frec[MP][30];

int solve() {
  string line;
  cin>>line;
  memset(frec, 0, sizeof frec);

  for (int i = 0; i < line.size(); ++i) {
    frec[i][line[i] - 'a'] = 1;
    if (i > 0) {
      for (int j = 0; j < 30; ++j)
        frec[i][j] += frec[i - 1][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < line.size(); ++i) {
    for (int j = i; j < line.size(); ++j) {
      int non_even = 0;
      for (int k = 0; k < 30; ++k) {
        int actual = frec[j][k] - ((i>0) ? frec[i - 1][k] : 0);
        if(actual % 2) non_even++;
      }
      if (non_even <= 1) ans++;
    }
  }

  return ans;
}

int main() { ___

  int tc; cin>>tc;
  for (int c = 1; c <= tc; ++c)
    printf("Case %d: %d\n", c, solve());

  return 0;
}
