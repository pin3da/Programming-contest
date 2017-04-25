// http://codeforces.com/contest/631/problem/C

#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'
using namespace std;

#define null NULL
struct Node {
  int y, size, payload;
  long long sum;
  Node *l, *r;
  bool pending_reversal;
  Node(int k) : payload(k), y(rand()), size(1),
  l(null), r(null), sum(0),
  pending_reversal(false) { }
};

Node* relax(Node* p) {
  if (p) {
    p->size = 1;
    p->sum = p->payload;
    if (p->l) {
      p->size += p->l->size;
      p->sum += p->l->sum;
    }
    if (p->r) {
      p->size += p->r->size;
      p->sum += p->r->sum;
    }
  }
  return p;
}

Node* propagate(Node * t) {
  assert(t);
  if (t->pending_reversal) {
    swap(t->l, t->r);
    t->pending_reversal = false;
    if (t->l) t->l->pending_reversal ^= 1;
    if (t->r) t->r->pending_reversal ^= 1;
    relax(t);
  }
  return t;
}


int leftCount(Node * t) {
  assert(t);
  return t->l ? t->l->size : 0;
}

// moves elements at positions [0..x] to l,
// and those at positions [x+1, n-1] to r.

void split(Node* t, int x, Node* &l, Node* &r) {
  if (t == null) l = r = null; else {
    // apply lazy propagation here to t
    propagate(t);
    if ( x < leftCount(t) ) {
      split(t->l, x, l, t->l);
      r = relax(t);
    } else {
      split(t->r, x - 1 - leftCount(t), t->r, r);
      l = relax(t);
    }
  }
}

Node* merge(Node* l, Node *r) {
  if (l == null) return relax(r);
  if (r == null) return relax(l);

  if (l->y > r->y) {
    // apply lazy propagation here to l
    propagate(l);
    l->r = merge(l->r, r);
    return relax(l);
  } else {
    // apply lazy propagation here to r
    propagate(r);
    r->l = merge(l, r->l);
    return relax(r);
  }
}

// Inserts node m at position x (0-based)
Node* insert(Node* t, Node* m, int x) {
  if (t == null || m->y > t->y) {
    split(t, x - 1, m->l, m->r);
    return relax(m);
  }
  // apply lazy propagation here to t
  propagate(t);
  if (x <= leftCount(t)) t->l = insert(t->l, m, x);
  else t->r = insert(t->r, m, x - 1 - leftCount(t));
  return relax(t);
}

Node* erase(Node* t, int x) {
  if (t == null) return null;
  // apply lazy propagation here to t
  propagate(t);
  if (leftCount(t) == x) {
    Node *q = merge(t->l, t->r);
    delete t;
    return relax(q);
  } else {
    if (x < leftCount(t)) t->l = erase(t->l, x);
    else t->r = erase(t->r, x - 1 - leftCount(t));
    return relax(t);
  }
}

Node* find(Node* cur, int x) {
  while (cur != null) {
    propagate(cur);
    if (leftCount(cur) == x) break;
    else if (x < leftCount(cur)) cur = cur->l;
    else {
      x = x - 1 - leftCount(cur);
      cur = cur->r;
    }
  }
  return cur;
}


void traverse(Node * p) {
  if (p == null) return;
  propagate(p);
  traverse(p->l);
  // printf("%d ", p->payload);
  cout << p-> payload << " ";
  traverse(p->r);
}

struct op {
  int i, t;
  op () {}
  op (int a, int b) : i(a), t(b) {}
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n, m;
  while (cin >> n >> m) {
    vector<long long> a(n);
    for (auto &i : a) cin >> i;
    deque<op> q;
    int r, t;
    for (int i = 0 ; i < m; ++i) {
      cin >> t >> r;
      while (!q.empty() && r > q.back().i)
        q.pop_back();
      q.push_back(op(r, t));
    }

    if (q.size()) {
      sort(a.begin(), a.begin() + q.front().i);
      if (q.front().t == 2)
        reverse(a.begin(), a.begin() + q.front().i);

      Node * root = new Node(a[0]);
      for (int i = 1; i < a.size(); ++i) {
        root = merge(root, new Node(a[i]));
      }

      int initial = q.front().t;
      q.pop_front();
      for (int i = 0; i <  q.size(); ++i) {
        int l = 0, r = q[i].i - 1;
        if (q[i].t != initial) {
          Node * a, * b;
          split(root, r, a, b);
          a-> pending_reversal = true;
          root = merge(a, b);
          initial = q[i].t;
        }
      }
      traverse(root);
      cout << endl;
    }
  }
  return 0;
}
