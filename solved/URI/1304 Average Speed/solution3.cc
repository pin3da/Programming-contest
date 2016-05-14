#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  string line;
  int tant = 0, tact = 0;
  double d = 0, v0 = 0, v1 = 0;
  while (getline(cin, line)) {
    int c, h, m, s;
    c = sscanf(line.c_str(), "%d:%d:%d %lf", &h, &m, &s, &v1);
    tact = h * 3600 + m * 60 + s;
    d += v0 * (tact - tant) / 3600.0;
    tant = tact;
    if (c == 3)
      printf("%.2d:%.2d:%.2d %.2lf km\n", h, m, s, d);
    else
      v0 = v1;
  }
  return 0;
}
