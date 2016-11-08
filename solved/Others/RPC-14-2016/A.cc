#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
const int MX = 100005;

int main() {
  int n;
  while(cin >> n) {
    int nodes = 0;
    string a, b;
    map<string, int> parse;
    vector<int> G[MX];
    vector<int> in(MX);
    char c;
    for(int i = 0; i < n; i++) {
      cin >> a >> c >> b;
      int u, v;
      if(parse.count(a)) u = parse[a];
      else{
        u = nodes++;
        parse[a] = u;
      }
      if(parse.count(b)) v = parse[b];
      else{
        v = nodes++;
        parse[b] = v;
      }
      if(c == '<'){
        G[v].push_back(u);
        in[u]++;
      }else{
        G[u].push_back(v);
        in[v]++;
      }
    }
    queue<int> Q;
    for(int i = 0; i < nodes; i++) {
      if(in[i] == 0) Q.push(i);
    }
    while(!Q.empty()) {
      int tm = Q.front();
      Q.pop();
      for(int i = 0; i < G[tm].size(); i++) {
        int cur = G[tm][i];
        if(in[cur] > 0) {
          in[cur]--;
        }
        if(in[cur] == 0) Q.push(cur);
      }
    }
    bool ok = true;
    for(int i = 0; i < nodes; i++) {
      if(in[i]) ok = false;
    }
    cout << (ok ? "possible" : "impossible") << endl;
  }


  return 0;
}
