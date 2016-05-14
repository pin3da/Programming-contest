// WA
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

long long parsetime(string a) {
  for (auto &i : a)  i -= '0';
  long long h = a[0] * 10 + a[1],
      m = a[3] * 10 + a[4],
      s = a[6] * 10 + a[7];

  return (h * 60 + m) * 60 + s;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  long long ant = 0, antspeed = 0;
  long double tot = 0;
  cout << fixed << setprecision(2);
  while (getline(cin, line)) {
    if (line.find(' ') != string::npos) {
      stringstream ss(line);
      string a, b;
      ss >> a >> b;
      long long cur = parsetime(a);
      if (ant != 0) {
        tot += (double)((antspeed) * (cur - ant)) / 3600.0;
      }
      ant = cur;
      antspeed = atoi(b.c_str());
    } else {
      long long cur = parsetime(line);
      tot += (double)((antspeed) * (cur - ant)) / 3600.0;
      ant = cur;
      cout << line << ' ' << tot << " km" << endl;
    }
  }
  return 0;
}
