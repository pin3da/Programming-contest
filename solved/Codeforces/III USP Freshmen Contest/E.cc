#include<bits/stdc++.h>

#define debug(x) cout << #x << " = " << (x) << endl

using namespace std;

struct task {
  int x, y;
  task(){}
  task(int a, int b): x(a), y(b){}
  bool operator <(const task & a) const {
    return y < a.y;
  }
};

int main () {
  int n, x, y;
  long long st;
  while (cin >> n >> st) {
    vector<pair<task, int>> tasks(n);
    vector<long long> len(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      tasks[i].first = task(st - y + x, x);
      tasks[i].second = i;
      len[i] = x;
    }
    sort(tasks.begin(), tasks.end());
    long long ans = 0;
    long long acc = 0;
    for (int i = 0; i < n; i++) {
      ans += tasks[i].first.x + acc;
      acc += len[tasks[i].second];
    }
    cout << ans << endl;
  }
}
