using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl;

/**
 * Name    : Ivan Operations.
 * Topics  : Lazy propagation on splay trees.
 * Problem : http://coj.uci.cu/24h/problem.xhtml?abb=2418
 * **/

struct node{
  node *left, *right, *parent;
  int cur, vset, size, c[27];   // current character, value to set, size, ans for i-th character at c[i].
  int rev, set;                 // Values for propagation, reverse and set operations.
  node (int k) : cur(k), left(0), right(0), parent(0) , rev(0), set(0) {
    c[k] = 1;
    size = 1;
  }

  void set_val(int a) {
    cur = vset = a;
    set = 1;
    memset(c, 0, sizeof c);
    c[a] = size;
  }

  void reverse() {
    rev ^= 1;
    swap(left, right);
  }

  void update() {
    size = 1;
    memset(c, 0, sizeof c);
    c[cur] = 1;
    if (left) {
      size += left->size;
      for (int i = 0;  i  < 26; ++i) c[i] += left->c[i];
    }
    if (right) {
      size += right->size;
      for (int i = 0;  i  < 26; ++i) c[i] += right->c[i];
    }
  }

  void propagate() {
    if (rev) {
      rev = 0;
      if (left) left->reverse();
      if (right) right->reverse();
    }
    if (set) {
      set = 0;
      if (left) left->set_val(vset);
      if (right) right->set_val(vset);
    }
  }
};

string line;

struct splay_tree{

  node *root;

  void right_rot(node *x) {
    node *p = x->parent;
    if (x->parent = p->parent) {
      if (x->parent->left  == p) x->parent->left  = x;
      if (x->parent->right == p) x->parent->right = x;
    }
    if (p->left = x->right) p->left->parent = p;
    x->right  = p;
    p->parent = x;

    p->update();
  }

  void left_rot(node *x) {
    node *p = x->parent;
    if (x->parent = p->parent) {
      if (x->parent->left  == p) x->parent->left  = x;
      if (x->parent->right == p) x->parent->right = x;
    }
    if (p->right = x->left) p->right->parent = p;
    x->left  = p;
    p->parent = x;

    p->update();
  }

  void splay(node *x, node *fa = 0) {

    while( x->parent != fa and x->parent != 0) {
      node *p = x->parent;
      if (p->parent == fa)
        if (p->right == x)
          left_rot(x);
        else
          right_rot(x);
      else {
        node *gp = p->parent;
        if (gp->left == p)
          if (p->left == x)
            right_rot(x),right_rot(x);
          else
            left_rot(x),right_rot(x);
        else
          if (p->left == x)
            right_rot(x), left_rot(x);
          else
            left_rot(x), left_rot(x);
      }
    }

    x->update();
    if (fa == 0) root = x;
    else fa->update();
  }

  splay_tree(){ root = 0;};

  node *build(int a, int b) {
    if (b < a) return 0;
    int mid = (a + b)>>1;
    node *x = new node(line[mid] - 'a');
    x->left = build(a, mid - 1);
    if (x->left) x->left->parent = x;
    x->right = build(mid + 1, b);
    if (x->right) x->right->parent  = x;
    x->update();
    return x;
  }

  node *find(int k) {
    node *cur = root;
    while (true) {
      cur->propagate();
      if (cur->left) {
        if (cur->left->size >= k) {
          cur = cur->left;
          continue;
        }
        k -= cur->left->size;
      }
      if ( k == 1) break;
      k--;
      cur = cur->right;
    }
    return cur;
  }

  void set_val(int a, int b, int c) {
    node *end = find(b + 1);
    node *begin = find(a - 1);
    splay(end); splay(begin, end);
    begin->right->set_val(c);
    begin->update();
    end->update();
  }

  void reverse(int a, int b) {
    node *end = find(b + 1);
    node *begin = find(a - 1);
    splay(end); splay(begin, end);
    begin->right->reverse();
  }

  int query(int a, int b, int pos) {
    node *end = find(b + 1);
    node *begin = find(a - 1);
    splay(end); splay(begin, end);
    return begin->right->c[pos];
  }

  void good_bye(node *x) {
    if (x == 0) return;
    good_bye(x->left);
    good_bye(x->right);
    delete (x);
    x = 0;
  }


  void print(node *a) {
    if (!a) return;

    print(a->left);
    cout<<(char)(a->cur + 'a')<<" - ";
    print(a->right);
  }

};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);

  splay_tree tree;
  cin>>line;
  line = '{' + line + '{';
  tree.root = tree.build(0, line.size()-1);

  int q; cin>>q;
  char op, c;
  int a,b;

  while (q--) {
    cin>>op>>a>>b;
    if (op == 'C') {
      cin>>c;
      cout<<tree.query(a + 1, b + 1, c - 'a')<<endl;
    } else if (op == 'S') {
      cin>>c;
      tree.set_val(a + 1, b + 1, c - 'a');
    } else {
      tree.reverse(a + 1, b + 1);
    }
  }
  return 0;
}
