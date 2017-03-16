using namespace std;
#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << (x) << endl

long long curr_pos;

struct ev {
  long long t;
  int k, id;
  ev() {}
  ev(long long a, int c, int d) : t(a), k(c), id(d) {}
  bool operator < (const ev &otro) const {
    if (t == otro.t) {
      if (k == otro.k)
        return id < otro.id;
      return k < otro.k;
    }
    return t > otro.t;
  }
};

const int MN = 212345;
long long ans[MN];

struct node {
  long long cost, ti, id;
  node() {}
  node(long long a, long long b, long long c) : cost(a), ti(b), id(c) {}
  bool operator < (const node &otro) const {
    if (cost + (ti - curr_pos) == otro.cost + (otro.ti - curr_pos))
      return id < otro.id;
    return (cost + (ti - curr_pos) < otro.cost + (otro.ti - curr_pos));
  }
};

int main() {

  long long n;
  int k;
  cin >> n >> k;
  vector<ev> all;
  for (int i = 0; i < k; ++i) {
    long long start, end;
    cin >> start >> end;
    all.push_back(ev(start, 1, i));
    all.push_back(ev(end, 0, i));
  }

  sort(all.begin(), all.end());
  set<node> dp;
  curr_pos = n + 1;
  dp.insert(node(0, curr_pos, k));
  for (auto e : all) {
    if (e.k == 0) {
      auto otro = *dp.begin();
      ans[e.id] = otro.ti - e.t + otro.cost - 1;
      curr_pos = e.t;
    } else {
      dp.insert(node(ans[e.id], e.t, e.id));
    }
  }
  curr_pos = 1;
  auto best = *dp.begin();
  cout << best.cost + best.ti - 1 << endl;


  return 0;
}
