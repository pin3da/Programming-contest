// WA
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long parsetime(string a) {
  stringstream ss(a);
  string x, y, z;
  getline(ss, x, ':');
  getline(ss, y, ':');
  getline(ss, z, ':');
  long long h = atoll(x.c_str()),
            m = atoll(y.c_str()),
            s = atoll(z.c_str());

  return (h * 60 + m) * 60 + s;
}

int main() {
  string line;
  long long ant = 0, antspeed = 0;
  double tot = 0;
  cout << fixed << setprecision(2);
  while (cin >> line) {
    char c; scanf("%c", &c);
    if (c == ' ') {
      long long cur = parsetime(line);
      if (ant != 0)
        tot += (double)((antspeed) * (cur - ant)) / 3600.0;
      ant = cur;
      cin >> antspeed;
    } else {
      long long cur = parsetime(line);
      tot += (double)((antspeed) * (cur - ant)) / 3600.0;
      ant = cur;
      cout << line << ' ' << tot + 1e-9 << " km" << endl;
    }
  }
  return 0;
}
