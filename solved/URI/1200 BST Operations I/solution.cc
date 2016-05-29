#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

#define null NULL

typedef char T;
struct t_node {
  T val;
  t_node *l, *r;
  t_node(T k) : l(null), r(null), val(k) {}
};

typedef t_node* pnode;

T find_max(pnode node) {
  if (node-> r) return find_max(node-> r);
  return node-> val;
}

pnode erase(pnode node, T val) {
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
      T tar = find_max(node-> l);
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

pnode insert(pnode node, T val) {
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

pnode search(pnode node, T val) {
  if (node == null)
    return null;
  if (node-> val == val) return node;
  else if (node-> val > val) return search(node-> l, val);
  else return search(node-> r, val);
}

int first;
void pref(pnode node) {
  if (node == null) return;
  if (!first) cout << ' ';first = false;
  cout << (node-> val);
  pref(node-> l); pref(node-> r);
}

void inf(pnode node) {
  if (node == null)return;
  inf(node-> l);
  if (!first) cout << ' ';first = false;
  cout << (node-> val);
  inf(node-> r);
}

void posf(pnode node) {
  if (node == null) return;
  posf(node-> l); posf(node-> r);
  if (!first) cout << ' '; first = false;
  cout << (node-> val);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string op;
  pnode root = null;
  while (cin >> op) {
    if (op == "I") {
      T val; cin >> val;
      root = insert(root, val);
    }
    if (op == "P") {
      T val; cin >> val;
      pnode cur = search(root, val);
      if (cur == null)
        cout << val << " nao existe" << endl;
      else
        cout << val << " existe" << endl;
    }

    if (op == "R") {
      T val; cin >> val;
      root = erase(root, val);
    }

    if (op == "INFIXA") {
      first = true;
      inf(root);
      cout << endl;
    }

    if (op == "PREFIXA") {
      first = true;
      pref(root);
      cout << endl;
    }

    if (op == "POSFIXA") {
      first = true;
      posf(root);
      cout << endl;
    }
  }
  return 0;
}
