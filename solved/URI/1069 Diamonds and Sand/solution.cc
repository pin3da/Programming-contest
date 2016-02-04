#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, t;
  string line;
  cin >> t;
  while (t--) {
    cin >> line;
    a = 0, b = 0;
    for (auto &i : line)
      if (i == '<')
        a++;
      else if (i == '>' && a > 0) {
        a--;
        b++;
      }
    cout << b << endl;
  }
  return 0;
}

