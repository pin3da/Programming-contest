#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

int fun(int l) {
  int bs, iv, ev;
  cin >> bs >> iv >> ev;
  double s = (((iv + bs + (sqrt(ev) / 8)) * l) / 50) + 5;
  return int(s);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    string name; cin >> name;
    int l; cin >> l;

    printf("Caso #%d: %s nivel %d\n", i, name.c_str(), l);

    int bs, iv, ev;
    cin >> bs >> iv >> ev;
    double hp = (((iv + bs + (sqrt(ev) / 8) + 50) * l) / 50) + 10;
    printf("HP: %d\n", int(hp));
    printf("AT: %d\n", fun(l));
    printf("DF: %d\n", fun(l));
    printf("SP: %d\n", fun(l));
  }

  return 0;
}
