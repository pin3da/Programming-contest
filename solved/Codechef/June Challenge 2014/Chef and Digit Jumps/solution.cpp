using namespace std;
#include<bits/stdc++.h>


const int MN  = 100100;
const int inf = (1<<30) - 100;

string line;
int n;
int ts[MN], nxt[MN];

struct state{
  int i, c, w;
  state(int a, int b, int bb) : i(a), c(b), w(bb) {}

  bool operator < (const state & o) const {
    return w > o.w;
  }
};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  cin>>line;

  n = line.size() - 1;

  int ref[10];
  for (int i = 0 ; i < 10; ++i)
    ref[i] = n + 1;

  for (int i = n; i >= 0; --i) {
    ts[i] = inf;
    nxt[i] = ref[line[i] - '0'];
    ref[line[i] - '0'] = i;
  }

  ts[0] = 0;

  priority_queue<state> q;
  q.push(state(0,1,0));

  while (!q.empty()) {
    int i = q.top().i;
    int c = q.top().c;
    int w = q.top().w;
    q.pop();

    if (w > ts[i]) continue;
    if (i == n) {
      cout<<w<<endl;
      return 0;
    }

    if (i - 1 >= 0 and  (ts[i - 1] >= ts[i] + 1)) {
      ts[i - 1] = ts[i] + 1;
      q.push(state(i - 1, 1, ts[i] + 1));
    }
    if ( i + 1 <= n and (ts[i + 1] >= ts[i] + 1)) {
      ts[i + 1] = ts[i] + 1;
      q.push(state(i + 1, 1, ts[i] + 1));
    }
    if (nxt[i] <= n and (ts[nxt[i]] >= ts[i] + c)) {
      ts[nxt[i]] = ts[i] + c;
      q.push(state(nxt[i], 0, ts[i] + c));
    }
  }


  return 0;
}
