using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

struct entry {
  int time;
  char type;
  entry () {}
  entry (int a, char b) : time(a), type(b) { }
  bool operator < (const entry &o) const {
    return time < o.time;
  }
};

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    int h, m, s;
    char c;
    vector<entry> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d:%d:%d %c", &h, &m, &s, &c);
      a[i] = (entry((h * 60 + m) * 60 + s, c));
    }

    sort(a.begin(), a.end());
    int open = 0, close = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i].type != 'E')
        close++;
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
      best = max(best, min(open, close));
      if (a[i].type == '?') {
        open++;
        close--;
      } else if (a[i].type ==  'E')
        open++;
      else
        close--;
    }

    printf("%d\n", best);

  }

  return 0;
}
