#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  char c;
  string line;
  while (cin >> c >> line && c != '0') {
    int first = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == c) continue;
      first = (line[i] != '0') || first;
      if (first)
        cout << line[i];
    }

    if (!first)
      cout << '0';
    cout << endl;
  }
  return 0;
}
