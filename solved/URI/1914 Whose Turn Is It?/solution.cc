#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int B = b == "PAR",
        D = d == "PAR";

    int A, C;
    cin >> A >> C;
    if ((A + C) & 1) {
      if (B & 1)
        cout << c << endl;
      else
        cout << a << endl;
    } else {
      if (B & 1)
        cout << a << endl;
      else
        cout << c << endl;
    }
  }
  return 0;
}

