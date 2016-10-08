#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define debug(x) cout << #x " = " << (x) << endl

int f[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string name [] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int gn(string a) {
  for (int i = 0; i < 7; ++i)
    if (a == name[i]) return i;
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  while (cin >> a >> b) {
    int x = gn(a), y = gn(b);
    int ok = false;
    for (int i = 0; i < 11; ++i) {
      if ((x + f[i]) % 7 == (y)) {
        ok = true;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
