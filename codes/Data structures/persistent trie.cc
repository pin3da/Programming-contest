/**
 * Persistent version of trie:
 *  could be used as a persistent BST of integers.
 *  add: O(log2(n))
 *  query: O(log2(n)), works equal than the non-persistent version.
 * */

const int MD = 31;
const int MAX_CHILD = 2;

struct node {
  node *child[MAX_CHILD];
};

typedef node* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node();
  if (cur)
    *ans = *cur;
  return ans;
}

pnode add(pnode cur, int val, int id = MD) {
  pnode ans = copy_node(cur);
  if (id == -1) return ans;
  int t = (val >> id) & 1;
  ans-> child[t] = add(ans-> child[t], val, id - 1);
  return ans;
}
