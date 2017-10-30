#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

const int MX = 100005;

int tree[MX * 3][9];
int lazy[MX * 3], ansq[9], anst[9];

void init(int node, int b, int e) {
  if (b == e) {tree[node][1] = 1; return;}
  int mid = (b + e) >> 1;
  int next = node << 1;
  init(next, b, mid);
  init(next | 1, mid + 1, e);
  tree[node][1] = tree[next][1] + tree[next | 1][1];
  return;
}

void push_down(int node, int b, int e) {
  if (lazy[node]) {
    int v = lazy[node];
    lazy[node] = 0;
    for (int i = 0; i < 9; i++) anst[(i + v) % 9] = tree[node][i];
    for (int i = 0; i < 9; i++) tree[node][i] = anst[i];
    if (b != e) {
      int next = node << 1;
      lazy[next] += v;
      lazy[next | 1] += v;
    }
  }
}

void query(int node, int b, int e, int l, int r) {
  push_down(node, b, e);
  if (b > r || e < l) return;
  if (b >= l && e <= r) {
    for (int i = 0; i < 9; i++) { ansq[i] += tree[node][i]; }
    return;
  }
  int mid = (b + e) >> 1;
  int next = node << 1;
  query(next, b, mid, l, r);
  query(next | 1, mid + 1, e, l, r);

}

void update(int node, int b, int e, int l, int r, int v) {
  push_down(node, b, e);
  if (b > r || e < l) return;
  if (b >= l && e <= r) {
    lazy[node] += v;
    push_down(node, b, e);
    return;
  }
  int mid = (b + e) >> 1;
  int next = node << 1;
  update(next, b, mid, l, r, v);
  update(next | 1, mid + 1, e, l, r, v);
  for (int i = 0; i < 9; i++) {
    tree[node][i] = tree[next][i] + tree[next | 1][i];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, l, r;
  cin >> n >> m;
  init(1, 0, n - 1);
  for (int i = 0; i < m; i++) {
    cin >> l >> r;
    // cout << l << " + " << r << endl;
    memset(ansq, 0, sizeof ansq);
    query(1, 0, n - 1, l, r);
    int mx = -1, mtx = -1;
    for (int j = 8; j >= 0; j--) {
      // cout << ansq[j] << " ";
      if (ansq[j] > mtx) {
        mtx = ansq[j]; mx = j;
      }
    }
    // cout << " min: " << mx << endl;
    update(1, 0, n - 1, l, r, mx);

  }
  for (int i = 0; i < n; i++) {
    memset(ansq, 0, sizeof ansq);
    query(1, 0, n - 1, i, i);
    for (int j = 0; j < 9; j++) {
      if (ansq[j]) {cout << j << endl; break;}
    }
  }
  return 0;
}

