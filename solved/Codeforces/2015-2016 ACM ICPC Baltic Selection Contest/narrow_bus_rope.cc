#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

struct node {
  int y, size, val;
  node *l, *r, *p;
};

typedef node* pnode;

int get_size(pnode t) {
  return t ? t-> size : 0;
}

pnode relax(pnode t) {
  if (t) {
    t-> size = 1 + get_size(t-> l) + get_size(t-> r);
    if (t-> r)
      t-> r-> p = t;
    if (t-> l)
      t-> l-> p = t;
  }
  return t;
}

void split(pnode tree, pnode &l, pnode &r, int pos) {
  if (!tree)
    l = r = NULL;
  else {
    if (pos < get_size(tree-> l) ) {
      split(tree-> l, l, tree-> l, pos);
      r = relax(tree);
    } else {
      split(tree-> r, tree-> r, r, pos - 1 - get_size(tree-> l));
      l = relax(tree);
    }
  }
}

pnode merge(pnode l, pnode r) {
  if (!l) return relax(r);
  if (!r) return relax(l);
  if (l-> y > r-> y) {
    l->r = merge(l->r, r);
    return relax(l);
  } else {
    r->l = merge(l, r->l);
    return relax(r);
  }
}

pnode init(int val){
  pnode ret = (pnode)malloc(sizeof(node));
  ret-> y = rand();
  ret-> size = 1;
  ret-> val = val;
  ret-> l = ret-> r = ret-> p = NULL;
  return ret;
}

const int MN = 1000000 + 100;
pnode root = NULL;
pnode rev[MN];
int nodes;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));
  int n;
  cin >> n;

  int pop = 0;


  int i = 0;
  nodes = 0;

  while (n--) {
    char op;
    cin >> op;
    if (op == 'F') {
      if (root == NULL) {
        root = rev[nodes] = init(nodes);
      } else {
        rev[nodes] = init(i);
        root = merge(rev[nodes], root);
      }
      nodes++;
      i++;
    } else if (op == 'B') {
      if (root == NULL) {
        root = rev[nodes] = init(nodes);
      } else {
        rev[nodes] = init(i);
        root = merge(root, rev[nodes]);
      }
      nodes++;
      i++;
    } else {
      int id;
      cin >> id;
      id--;

      pnode x = rev[id];
      int left = get_size(x-> l);
      while (x != root) {
        pnode t = x-> p;
        if (t-> r == x)
          left += get_size(t-> l) + 1;
        x = t;
      }

      // D(left);
      if (left <= (i - left - 1))
        cout << left << endl;
      else
        cout << (i - left - 1) << endl;

      pnode l, r, r1;
      split(root, l, r, left - 1);
      split(r, r1, r, 0);
      root = merge(r, l);

      i--;
    }

  }

  return 0;
}
