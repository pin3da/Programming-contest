using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const int MN = 3002;
const int ML = 33810;

#define null NULL

struct node {
  int x, y, size;
  node *l, *r;
  node(int k) : x(k), y(rand()), size(1),
  l(null), r(null) { }
};

node *relax(node *p) {
  if (p) {
    p->size = 1;
    if (p->l) {
      p->size += p->l->size;
    }
    if (p->r) {
      p->size += p->r->size;
    }
  }
  return p;
}

// Puts all elements <= x in l and all elements > x in r.
void split(node *t, int x, node* &l, node* &r) {
  if (t == null) l = r = null; else {
    if (t->x <= x) {
      split(t->r, x, t->r, r);
      l = relax(t);
    } else {
      split(t->l, x, l, t->l);
      r = relax(t);
    }
  }
}

node *merge(node *l, node *r) {
  if (l == null) return relax(r);
  if (r == null) return relax(l);
  if (l->y > r->y) {
    l->r = merge(l->r, r);
    return relax(l);
  } else {
    r->l = merge(l, r->l);
    return relax(r);
  }
}

node *insert(node *t, node *m) {
  if (t == null || m->y > t->y) {
    split(t, m->x, m->l, m->r);
    return relax(m);
  }
  if (m->x < t->x) t->l = insert(t->l, m);
  else t->r = insert(t->r, m);
  return relax(t);
}

node *erase(node *t, int x) {
  if (t == null) return null;
  if (t->x == x) {
    node *q = merge(t->l, t->r);
    delete t;
    return relax(q);
  } else {
    if (x < t->x) t->l = erase(t->l, x);
    else t->r = erase(t->r, x);
    return relax(t);
  }
}

// Returns any node with the given x.
node *find(node *cur, int x) {
  while (cur != null and cur->x != x) {
    if (x < cur->x) cur = cur->l;
    else cur = cur->r;
  }
  return cur;
}

node *find_kth(node *cur, int k) {
  while (cur != null and k >= 0) {
    if (cur->l && cur->l->size > k) {
      cur = cur->l;
      continue;
    }
    if (cur->l)
      k -= cur->l->size;
    if (k == 0) return cur;
    k--;
    cur = cur->r;
  }
  return cur;
}


int ans[MN], pos;
void flatten(node *t) {
    if (t == null) return;
    flatten(t->l);
    if (pos >= MN) return;
    ans[pos++] = (t->x);
    flatten(t->r);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  srand(time(0));

  node *root = null;
  for (int i = 2; i < ML; i ++) {
    root = insert(root, new node(i));
  }

  int i = 0;
  while (true) {
    node *a = find_kth(root, i);
    if (a == null) break;
    int step = a->x;
    for (int j = i + step; j < root->size; j += step) {
      int t = find_kth(root, j)->x;
      root = erase(root, t);
      j--;
    }
    ++i;
  }

  pos = 0;
  flatten(root);

  int t;
  while (cin >> t && t)
    cout << ans[t - 1] << endl;
  return 0;
}

