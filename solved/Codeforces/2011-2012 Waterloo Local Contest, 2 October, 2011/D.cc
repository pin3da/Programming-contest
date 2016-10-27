#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

string a[] = {"", "" , "ABC", "DEF", "GHI", "JKL", "MNO",
              "PQRS", "TUV", "WXYZ"};


int fw(char c) {
  c = toupper(c);
  for (int i = 0; i < 10; ++i) {
    if (a[i].find(c) != string::npos) return i;
  }
  assert(false);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  while (cin >> n) {
    while (n--) {
      string line; cin >> line;
      deque<int> p;
      for (int i = 0; i < (int)line.size(); ++i)
        p.push_back(fw(line[i]));

      int ok = true;
      for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i] != p[p.size() - 1 - i]) ok = false;
      }
      puts(ok ? "YES" : "NO");
    }
  }
  return 0;
}
