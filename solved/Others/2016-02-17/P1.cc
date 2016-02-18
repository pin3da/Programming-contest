#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    int op = 0;
    int ok = true;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '(')
        op++;

      if (line[i] == ')') {
        if (op <= 0) {
          ok = false;
          break;
        }
        op--;
      }
    }
    if (op)
      ok = false;

    if (ok)
      cout << "correct" << endl;
    else
      cout << "incorrect" << endl;

  }
  return 0;
}
