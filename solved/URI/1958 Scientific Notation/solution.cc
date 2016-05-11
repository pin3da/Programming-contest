#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  long double t;
  cout << scientific << setprecision(4) << uppercase;
  string line;
  while (cin >> line) {
    if (line[0] != '-')
      cout << '+';
    stringstream ss(line);
    ss >> t;
    cout << t << endl;
  }
  return 0;
}

