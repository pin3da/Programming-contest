#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m;
  cin >> n >> m;
  string line;
  cin >> line;
  while (m--) {
    int a, b;
    char c, d;
    cin >> a >> b >> c >> d;
    a--;b--;
    for (int i = a; i <= b; i++) {
      if (line[i] == c)
        line[i] = d;
    }
  }
  cout << line << endl;
  return 0;
}
