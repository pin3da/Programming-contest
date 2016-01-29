#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int t;
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < 5; ++i) {
    cin >> t;
    if (t & 1) a++;
    else       b++;
    if (t > 0) c++;
    else if (t < 0) d++;
  }
  printf("%d valor(es) par(es)\n", b);
  printf("%d valor(es) impar(es)\n", a);
  printf("%d valor(es) positivo(s)\n", c);
  printf("%d valor(es) negativo(s)\n", d);
  return 0;
}
