#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const string kang = "KANGAROO";
const string kiwi = "KIWIBIRD";

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  string line; cin >> line;
  int a = 0, b = 0;
  for (auto i : line) {
    for (auto j : kang)
      if (toupper(i) == j) a++;

    for (auto j : kiwi)
      if (toupper(i) == j) b++;
  }
  if (a > b)
    puts("Kangaroos");
  else if (b > a)
    puts("Kiwis");
  else
    puts("Feud continues");
  return 0;
}
