#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

const int MN = 1000000 + 10;

int a[MN];
vector<int> incR[MN];
vector<int> incL[MN];
int vi[MN];

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    for (int i = 0; i < n + 5; ++i) {
      incR[i].clear();
      incL[i].clear();
    }

    for (int i = 0; i < n; ++i) {
      int r = i + a[i];
      if (r < n) {
        incR[r].push_back(i);
      }
      int l = i - a[i];
      if (l >= 0) {
        incL[l].push_back(i);
      }
    }

    memset(vi, 0, sizeof vi);
    deque<int> q;
    q.push_back(0);
    vi[0] = true;
    while (!q.empty()) {
      int cur = q.front();q.pop_front();
      int id = cur + a[cur];
      if (id < n) {
        for (auto &to : incL[id]) {
          if (!vi[to]) {
            q.push_back(to);
            vi[to] = true;
          }
        }
      }
      id = cur - a[cur];
      if (id >= 0) {
        for (auto &to : incR[id]) {
          if (!vi[to]) {
            q.push_back(to);
            vi[to] = true;
          }
        }
      }
    }

    for (int i = n - 1; i >= 0; --i) {
      if (vi[i]) {
        cout << i << endl;
        break;
      }
    }

  }
  return 0;
}
