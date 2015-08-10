using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<x<<endl;

typedef int T;

struct node{
  node *left, *right, *parent;
  T key;
  node (T k) : key(k), left(0), right(0), parent(0) {}
};

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
        node *gp = p->parent; //grand parent
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
    if (fa == 0) root = x;
  }

  void insert(T key) {
    node *cur = root;
    node *pcur = 0;
    while (cur) {
      pcur = cur;
      if (key > cur->key) cur = cur->right;
      else cur = cur->left;
    }
    cur = new node(key);
    cur->parent = pcur;
    if (!pcur) root = cur;
    else if (key > pcur->key ) pcur->right = cur;
    else pcur->left = cur;
    splay(cur);
  }

  node *find(T key) {
    node *cur = root;
    while (cur) {
      if (key > cur->key) cur = cur->right;
      else if(key < cur->key) cur = cur->left;
      else return cur;
    }
    return 0;
  }

  splay_tree(){ root = 0;};
};

