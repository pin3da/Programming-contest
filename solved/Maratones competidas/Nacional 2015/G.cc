using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

typedef complex<long> cpx;

int main() {
  #ifdef TCBAHIA
  freopen("g.in", "r", stdin);
  #endif // TCBAHIA

  long long n;
  while (cin >> n) {
      cpx ans = cpx(0);
      int left = 0;
      for (int i = 0; i < 40; ++i) {
        ans += pow(cpx(-1 , 1), i) * cpx(((n >> i) & 1));
      }
      cout << ans.real() << " " << ans.imag() << endl;
  }
  return 0;
}
