#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

bool voc(char c) {
  return c == 'a' || c == 'e' ||c == 'i' || c == 'o' || c == 'u';
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    string c;
    for (int i = 0; i < line.size(); ++i) {
      if (voc(line[i])) c.push_back(line[i]);
    }

    int ok = true;
    for (int i = 0; i < c.size(); ++i) {
      ok &= c[i] == c[c.size() - 1 - i];
    }
    puts(ok ? "S": "N");
  }
  return 0;
}
