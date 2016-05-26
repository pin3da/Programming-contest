#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 205;
ll coef[MAXN][MAXN];

void calc() {
  coef[0][0] = 1;
  coef[1][0] = coef[1][1] = 1;

  for(int i = 2; i < MAXN; i++) {
    coef[i][0] = coef[i][i] = 1;
    for(int j = 1; j < i; j++) {
      coef[i][j] = coef[i - 1][j - 1] + coef[i - 1][j];
    }
  }
}

int main() {
  calc();
  int t; cin >> t;
  while(t--) {
    ll sol = 0;

    int n; cin >> n;
    for(int i = 0; i < min(5, n); i++) sol += coef[n - 1][i];
    cout << sol << endl;
  }
}
