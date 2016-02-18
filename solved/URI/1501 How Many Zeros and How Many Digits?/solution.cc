#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN  = (1 << 20) + 20;
double ll[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, b;
  ll[0] = 0;
  for (int i = 1; i < MN; ++i) {
    ll[i] = ll[i - 1] + log(i);
  }
  while (cin >> n >> b) {
    int last_p, last_e;
    int bb = b;
    for (int i = 2; i <= b; ++i) {
      if ((b % i) == 0) {
        int exp = 0;
        while ((b % i) == 0) {
          exp++;
          b /= i;
        }
        last_p = i;
        last_e = exp;
      }
    }

    int times = 0;
    int a = n;
    while (a > 0) {
      a /= last_p;
      times += a;
    }

    cout << (times) / last_e  << " " << (int) round(floor(ll[n] / log(bb)) + 1) << endl;
  }
  return 0;
}

