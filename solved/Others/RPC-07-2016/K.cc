#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  int tc = 1;
  int acc = 0;
  while (cin >> n && n) {
      acc += n;
      if (acc >= 100) {
        cout << "Input #" << tc << ": Totally Sweet!" << endl;
        acc %= 50;
      } else if (acc >= 50) {
        acc -= 50;
        cout << "Input #" << tc << ": Sweet!" << endl;
      }
    tc++;
  }

  return 0;
}
