#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

char rot13(char a) {
  char base = 'A';
  if (a >= 'a' && a <= 'z') {
    base = 'a';
  }
  a -= base;
  a = (a - 13 + 26) % 26;
  return a + base;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (getline(cin, line)) {
    for (auto &i : line) {
      if (isalpha(i))
        i = rot13(i);
    }
    cout << line << endl;
  }
  return 0;
}
