#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  ld a;
  while (cin >> a) {
    string line;
    cin >> line;
    int prec = line.size() - 2;
    stringstream ss(line);
    ld b;
    ss >> b;
    b = 1.0 - b;
    for (int i = 0; i < prec; ++i) {
      a *= 10;
      b *= 10;
    }
    long long x = (a + b);
    for (int i = 0; i < prec; ++i)
      x /= 10;

    cout << x << endl;
  }
  return 0;
}

