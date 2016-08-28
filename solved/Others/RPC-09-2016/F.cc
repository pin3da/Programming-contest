#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl
using namespace std;

typedef long double T;

const int MN = 2555;
T fact[MN];

const T EPS = 1e-3;
int cmp(T x, T y = 0, T tol = EPS){
  return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  fact[0] = fact[1] = 0;

  for (int i = 2; i < MN; ++i) {
    fact[i] = fact[i - 1] + log((T)i);
  }

  int tc; cin >> tc;
  int tid = 1;
  while (tc--) {
    int a, b, c; cin >> a >> b >> c;

    T A = 0, B = 0, C = 0;

    int tmp;
    for (int i = 0; i < a; ++i) {
      cin >> tmp;
      A += fact[tmp];
    }
    for (int i = 0; i < b; ++i) {
      cin >> tmp;
      B += fact[tmp];
    }
    for (int i = 0; i < c; ++i) {
      cin >> tmp;
      C += fact[tmp];
    }

    cout << "Case #" << (tid++) << ": ";
    /* debug(A);
       debug(B);
       debug(C);*/
    if (cmp(A, B) == 1 && cmp(A, C) == 1) {
      cout << "A" << endl;
    } else if (cmp(B, A) == 1 && cmp(B, C) == 1) {
      cout << "B" << endl;
    } else if (cmp(C, A) == 1 && cmp(C, B) == 1) {
      cout << "C" << endl;
    } else {
      cout << "TIE" << endl;
    }
  }
  return 0;
}
