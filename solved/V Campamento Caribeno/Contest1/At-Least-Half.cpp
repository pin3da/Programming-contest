// Wrong Answer
using namespace std;
#include<bits/stdc++.h>

int grundy(int n) {int exp = 0; while (n) {exp++;n>>=1; } return exp; }

int compute(int a, int b) {
  if (a -1 == b)
    return (1 << b)>>2;
  else
    return (1 << (a-1)) - ((1<<b) - 1);
}

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    if (n & 1) cout<<1<<endl;
    else {
        int tope = grundy(n);
        int ans = 1<<30;
        int nim = 1 ^ tope;
        for (int i = 2; i <= tope; ++i) {
          for (int j = 1; j < i; ++j) {
            if ((nim ^ i ^ j) == 0)
              ans = min(ans, compute(i,j));
          }
        }
        cout<<ans<<endl;
    }
  }

  return 0;
}
