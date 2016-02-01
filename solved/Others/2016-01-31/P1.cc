#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;


int main() {
  int tc; cin >> tc;
  while (tc--) {
    string line;
    cin >> line;
    long long a = 0, b = 0;
    int i;
    for (i = 0; line[i] != '-'; ++i)
      a = (a * 26) + (line[i] - 'A');

    i++;
    for (; i < line.size(); ++i)
      b = (b * 10) + (line[i] - '0');

    if (abs(a - b) <= 100)
      cout << "nice" << endl;
    else
      cout << "not nice" << endl;
  }
  return 0;
}
