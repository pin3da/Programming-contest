#include <bits/stdc++.h>
using namespace std;

struct player {
  string name;
  long long a, b;
};

const long long inf = 1000000001;
int main() {
  int n; cin >> n;
  while (n--) {
    vector<player> a(5);
    for (auto &i : a)
      cin >> i.name  >> i.a >> i.b;

    for (auto &i : a) {
      if (i.b == 0) continue;
      if ((i.a * 3 < i.b))
        cout << i.name << " plz uninstall" << endl;
    }

    for (auto &i : a)
      cin >> i.name  >> i.a >> i.b;

    player worst; worst.a = inf; worst.b = 0;

    for (auto &i : a)
      if (i.a * worst.b < worst.a  * i.b)
        worst = i;

    if (worst.b == 0) {
      for (auto &i : a)
        cout << i.name << " plz uninstall" << endl;
    } else {
      for (auto &i : a) {
        if (i.b == 0) continue;
        if ((i.a * worst.b == worst.a  * i.b) || (i.a * 2 < i.b))
          cout << i.name << " plz uninstall" << endl;
      }
    }
  }
  return 0;
}
