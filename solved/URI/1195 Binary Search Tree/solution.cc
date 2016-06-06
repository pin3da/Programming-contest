#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

#define null NULL

struct t_node {
  int val;
  t_node *l, *r;
  t_node(int k) : l(null), r(null), val(k) {}
};

typedef t_node* pnode;

int find_max(pnode node) {
  if (node-> r) return find_max(node-> r);
  return node-> val;
}

pnode erase(pnode node, int val) {
  if (node == null) return null;
  if (node-> val > val) {
    node-> l = erase(node-> l, val);
  } else if (node -> val < val) {
    node-> r = erase(node-> r, val);
  } else {
    if (node-> l == null && node-> r == null) {
      delete node;
      return null;
    }
    if (node-> l != null && node-> r != null) {
      int tar = find_max(node-> l);
      node-> val = tar;
      node-> l = erase(node-> l, tar);
    } else if (node-> l) {
      pnode c = node-> l;
      delete node;
      return c;
    } else if (node-> r) {
      pnode c = node-> r;
      delete node;
      return c;
    }
  }
  return node;
}

pnode insert(pnode node, int val) {
  if (node == null) {
    return new t_node(val);
  }

  if (node-> val >= val) {
    node-> l = insert(node-> l, val);
    return node;
  } else if (node-> val < val) {
    node-> r = insert(node-> r, val);
    return node;
  }
}

pnode search(pnode node, int val) {
  if (node == null)
    return null;
  if (node-> val == val) return node;
  else if (node-> val > val) return search(node-> l, val);
  else return search(node-> r, val);
}

void pref(pnode node) {
  if (node == null) return;
  cout << ' ';
  cout << (node-> val);
  pref(node-> l); pref(node-> r);
}

void inf(pnode node) {
  if (node == null)return;
  inf(node-> l);
  cout << ' ';
  cout << (node-> val);
  inf(node-> r);
}

void posf(pnode node) {
  if (node == null) return;
  posf(node-> l); posf(node-> r);
  cout << ' ';
  cout << (node-> val);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case " << (i + 1) << ":" << endl;
    pnode root = null;
    int n, t; cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> t;
      root = insert(root, t);
    }
    cout << "Pre.:";
    pref(root);
    cout << endl;
    cout << "In..:";
    inf(root);
    cout << endl;
    cout << "Post:";
    posf(root);
    cout << endl;
    cout << endl;
  }
  return 0;
}

