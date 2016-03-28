#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  cout << fixed << setprecision(2);
  while (cin >> line) {
    int acc = 0, num = 0;
    for (int i = 0; i < line.size(); ++i) {
      if (line[i] == '1' && i + 1 < line.size() && line[i + 1] == '0') {
        acc += 10;
        num++;
        i += 1;
      } else {
        acc += line[i] - '0';
        num++;
      }
    }
    cout << double(acc) / double(num) << endl;
  }
  return 0;
}
