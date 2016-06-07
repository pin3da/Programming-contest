#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    int j = 0;
    for (auto &i: line) {
      if (isalpha(i)) {
        if (j & 1) i = tolower(i);
        else       i = toupper(i);
        j ^= 1;
      }
    }
    cout << line << endl;
  }
  return 0;
}
