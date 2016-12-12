#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

struct team {
  string name;
  int a, b, c;
  team(string n, int x, int y, int z) :
    name(n), a(x), b(y), c(z) {}
  team() {}
  bool operator < (const team &o) const {
    if (a == o.a) {
      if (b == o.b) {
        if (c == o.c)
          return name < o.name;
        return c > o.c;
      }
      return b > o.b;
    }
    return a > o.a;
  }
  void read() {
    cin >> name >> a >> b >> c;
  }
  void print() {
    cout << name << ' ' << a << ' ' << b << ' ' << c << endl;
  }
};

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false);cin.tie(NULL);
#endif

  int n;
  cin >> n;
  vector<team> a(n);
  for (int i = 0; i < n; ++i) a[i].read();
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) a[i].print();
  return 0;
}
