#include <bits/stdc++.h>
using namespace std;

int p[1000];
map<string,int> id;


int find(int x) {
  return (p[x] == x ? x : p[x] = find(p[x]));
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  p[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    id.clear();
    for (int i = 0; i < n; i++)
      p[i] = i;
    
    string u, v;
    vector<pair<int,int>> E(m);
    for (int i = 0, c = 0; i < m; i++) {
      cin >> u >> v;
      if (!id.count(u))
	id[u] = c++;
      if (!id.count(v))
	id[v] = c++;
      if (find(id[u]) != find(id[v]))
	merge(id[u], id[v]);

      E[i] = make_pair(id[u], id[v]);
    }

    map<int,pair<int,int>> comp; // (#V, #E)

    for (int i = 0; i < n; i++)
      comp[find(i)].first++;
    
    for (auto& e: E)
      if (find(e.first) == find(e.second))
	comp[find(e.first)].second++;

    int ans = 1;

    for (auto& c : comp) 
      ans += 1 - c.second.first + c.second.second;

    cout << ans << endl;
  }
  
  return 0;
}
