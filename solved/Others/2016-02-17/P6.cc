// To be continued...
// ):
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

struct node {
  int v;
  int l, r;
  node () {
    v = - 1;
    l = -1;
    r = -1;
  }
};

node tree[1000000 + 10];
int pi[1000000 + 10];
int nodes;

void insert(int val, int node = 0) {
  if (val < tree[node].v) {
    if (tree[node].l == -1) {
      pi[nodes] = node;
      tree[node].l = nodes;
      tree[nodes++].v = val;
    } else
      insert(val, tree[node].l);
  } else {
    if (tree[node].r == -1) {
      pi[nodes] = node;
      tree[node].r = nodes;
      tree[nodes++].v = val;
    } else
      insert(val, tree[node].r);
  }
}

bool search(int val, int node = 0) {
  if (val == tree[node].v)
    return true;
  if (val < tree[node].v) {
    if (tree[node].l == -1)
      return false;
    else
      return search(val, tree[node].l);
  } else {
    if (tree[node].r == -1)
      return false;
    else
      return search(val, tree[node].r);
  }
}

void erase(int val, int node = 0) {
  if (val == tree[node].v) {
    if (tree[node].l != -1 && tree[node].r != -1) {
      if (pi[node] != -1) {
        if (tree[pi[node]].l == node)  {

        } else {

        }
      }
    }
    return;
  }
  if (val < tree[node].v) {
    if (tree[node].l == -1)
      return;
    else
     erase(val, tree[node].l);
  } else {
    if (tree[node].r == -1)
      return;
    else
      erase(val, tree[node].r);
  }
}

int first;
void prefix(int node) {
  if (!first) cout << " ";

  cout << tree[node].v;
  first = 0;
  if (tree[node].l != -1)
    prefix(tree[node].l);
  if (tree[node].r != -1)
    prefix(tree[node].r);
}

void infix(int node) {
  if (!first) cout << " ";

  if (tree[node].l != -1)
    infix(tree[node].l);
  cout << tree[node].v;
  first = 0;
  if (tree[node].r != -1)
    infix(tree[node].r);
}

void posfix(int node) {
  if (!first) cout << " ";
  if (tree[node].l != -1)
    posfix(tree[node].l);
  if (tree[node].r != -1)
    posfix(tree[node].r);
  cout << tree[node].v;
  first = 0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);

  string op;
  int val;

  pi[0] = -1;
  cin >> op >> val;
  tree[0].v = val;
  nodes = 1;
  while (cin >> op) {
    first = true;
    if (op == "I") {
      cin >> val;
      insert(val);
    }

    if (op == "P") {
      cin >> val;
      if (search(val))
        cout << val << " existe" << endl;
      else
        cout << val << " nao existe" << endl;

    }

    if (op == "R") {
      cin >> val;
      erase(val);
    }

    if (op == "PREFIXA") {
      prefix(0);
      cout << endl;
    }

    if (op == "INFIXA") {
      infix(0);
      cout << endl;
    }

    if (op == "POSFIXA") {
      posfix(0);
      cout << endl;
    }
  }

  return 0;
}
