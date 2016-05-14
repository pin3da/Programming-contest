#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool check(string &a, int m) {
  int c = 0;
  for (auto &i : a)
    c = (c * 10 + i - '0') % m;
  return c == 0;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  int first = true;
  while (cin >> line) {
    int leap = 0, hulu = 0, bulu = 0;
    if ((check(line, 4) && !check(line, 100)) || check(line, 400))
      leap = 1;
    if (check(line, 15))
      hulu = 1;
    if (check(line, 55) && leap)
      bulu = 1;

    if (!first)
      cout << endl;
    first = false;
    if (!leap && !hulu && !bulu)
      cout << "This is an ordinary year." << endl;
    else {
      if (leap)
        cout << "This is leap year." << endl;
      if (hulu)
        cout << "This is huluculu festival year." << endl;
      if (bulu)
        cout << "This is bulukulu festival year." << endl;
    }
  }
  return 0;
}
