const int N = 2207;
int subtask, n, m;
int s, t;
struct Edges {
  int u, v;
  long long capa, flow = 0;
  Edges(int _u, int _v, long long _capa) {
	u = _u;
	v = _v;
	capa = _capa;
  }

  long long residual() { return capa - flow; }
  Edges() {}
};
vector<Edges> edge;
int dist[N * 2 + 100], cnt[N * 2 + 100];
vector<int> vertices[N * 2 + 100];

void Input() {
  cin >> subtask;
  cin >> n >> m;
  s = n + m + 1;
  t = n + m + 2;
  for (int i = 1; i <= n; i++) {
	int x;
	cin >> x;
	edge.push_back(Edges(s, i, x));
	vertices[s].push_back((int)edge.size() - 1);
	edge.push_back(Edges(i, s, 0));
	vertices[i].push_back((int)edge.size() - 1);
  }
  for (int i = 1; i <= m; i++) {
	int x;
	cin >> x;
	edge.push_back(Edges(n + i, t, x));
	vertices[n + i].push_back((int)edge.size() - 1);
	vertices[t].push_back((int)edge.size());
	edge.push_back(Edges(t, n + i, 0));
  }

  for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++) {
	  char c;
	  cin >> c;
	  if (c == '1') {
		edge.push_back(Edges(i, j + n, INF));
		vertices[i].push_back((int)edge.size() - 1);
		edge.push_back(Edges(j + n, i, 0));
		vertices[j + n].push_back((int)edge.size() - 1);
	  }
	}
  }
}

bool BFS() {
  for (int i = 1; i <= t; i++) {
	dist[i] = -1;
	cnt[i] = 0;
  }
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
	int u = q.front();
	q.pop();
	foreach (int id in vertices[u]) {
	  if (edge[id].residual() > 0) {
		int v = edge[id].v;
		if (dist[v] < 0) {
		  dist[v] = dist[u] + 1;
		  q.push(v);
		}
	  }
	}
  }
  return dist[t] >= 0;
}

long long DFS(int u, long long flow) {
  if (flow == 0) {
	return 0;
  }
  if (u == t) {
	return flow;
  }
  for (; cnt[u] <= (int)vertices[u].size() - 1; cnt[u]++) {
	int id = vertices[u][cnt[u]];
	int v = edge[id].v;
	if (dist[v] != dist[u] + 1 || edge[id].residual() <= 0) {
	  continue;
	}
	long long new_flow = DFS(v, min(flow, edge[id].residual()));
	if (new_flow == 0) {
	  continue;
	}
	edge[id].flow += new_flow;
	edge[id ^ 1].flow -= new_flow;
	return new_flow;
  }

  return 0;
}

long long Max_Flow() {
  long long tot = 0;
  while (BFS()) {
	while (true) {
	  long long new_flow = DFS(s, INF);
	  tot += new_flow;
	  if (new_flow == 0) {
		break;
	  }
	}
  }
  return tot;
}

void Track() {
  set<int> List_1;
  set<int> List_2;
  for (int i = 1; i <= t; i++) {
	if (dist[i] < 0) {
	  continue;
	}
	foreach (int id in vertices[i]) {
	  int v = edge[id].v;
	  if (dist[v] < 0) {
		if (i == s) {
		  List_1.insert(v);
		}
		if (v == t) {
		  List_2.insert(i - n);
		}
	  }
	}
  }
  cout << (int)List_1.size() << ' ';
  foreach (int value in List_1) {
	cout << value << ' ';
  }
  cout << '\n';
  cout << (int)List_2.size() << ' ';
  foreach (int value in List_2) {
	cout << value << ' ';
  }
}

void Process() {
  cout << Max_Flow() << '\n';
  Track();
}