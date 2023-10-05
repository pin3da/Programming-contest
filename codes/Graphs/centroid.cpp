const int N = 2e5 + 1;
vector<pair<int, int>> vertices[N];
int sub_size[N];
int k;
bool dead[N];
int res = -1;

void AddEdge(int u, int v, int w) {
	vertices[u].push_back(make_pair(v, w));
	vertices[v].push_back(make_pair(u, w));
}

int DFS(int u, int daddy) {
	sub_size[u] = 1;
	foreach (pair<int, int> adj in vertices[u]) {
		int v = adj.first;
		if (v == daddy || dead[v]) {
			continue;
		}
		sub_size[u] += DFS(v, u);
	}
	return sub_size[u];
}

int centroid(int u, int daddy, int lim) {
	foreach (pair<int, int> adj in vertices[u]) {
		int v = adj.first;
		if (v == daddy || dead[v]) {
			continue;
		}
		if (sub_size[v] > lim) {
			return centroid(v, u, lim);
		}
	}
	return u;
}

void dfs2(int u, int daddy, int distance, map<int, int>& cur, int s) {
	if (cur.count(s)) {
		Minimize(cur[s], distance);

	} else {
		//cout << distance <<'\n';
		cur[s] = distance;
	}
	foreach (pair<int, int> adj in vertices[u]) {
		int v = adj.first;
		if (v == daddy || dead[v]) {
			continue;
		}
		if (s + adj.second > k) {
			continue;
		}
		dfs2(v, u, distance + 1, cur, s + adj.second);
	}
}

void Build(int u, int daddy) {
	int lim = DFS(u, daddy);
	int _c = centroid(u, daddy, lim >> 1);

	dead[_c] = true;

	map<int, int> dict;
	foreach (pair<int, int> adj in vertices[_c]) {

		int v = adj.first;
		if (dead[v]) {
			continue;
		}

		map<int, int> cur;
		dfs2(v, _c, 1, cur, adj.second);
		foreach (auto val in cur) {
			if (dict.count(k - val.first)) {

				Minimize(res, dict[k - val.first] + val.second);
			}
		}

		foreach (auto val in cur) {
			if (dict.count(val.first)) {
				Minimize(dict[val.first], val.second);
			} else {
				dict[val.first] = val.second;
			}
		}
	}
	if (dict.count(k)) {
		foreach (auto val in dict) {
			if (val.first == k)
				Minimize(res, val.second);
		}
	}
	dict.clear();

	foreach (pair<int, int> adj in vertices[_c]) {
		int v = adj.first;
		if (dead[v]) {
			continue;
		}
		Build(v, _c);
	}
}

int best_path(int n, int m, int H[N][2], int L[N]) {
	k = m;
	for (int i = 0; i < n - 1; i++) {
		AddEdge(H[i][0] + 1, H[i][1] + 1, L[i]);
	}
	Build(1, -1);
	return res;
}