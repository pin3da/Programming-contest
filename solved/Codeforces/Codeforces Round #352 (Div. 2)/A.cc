#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  for (int i = 1; i < 1000; ++i) {
    line += to_string(i);
  }
  int n;
  while (cin >> n)
    cout << line[n - 1] << endl;
  return 0;
}
