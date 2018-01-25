#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

const int MD = 31;

struct node_bin {
  node_bin *child[2];
  int val;

  node_bin() : val(0) {
    child[0] = child[1] = NULL;
  }
};

typedef node_bin* pnode_bin;

pnode_bin copy_node(pnode_bin cur) {
  pnode_bin ans = new node_bin();
  if (cur) *ans = *cur;
  return ans;
}

pnode_bin modify(pnode_bin cur, int key, int inc, int id = MD) {
  pnode_bin ans = copy_node(cur);
  ans->val += inc;
  if (id >= 0) {
    int to = (key >> id) & 1;
    ans->child[to] = modify(ans->child[to], key, inc, id - 1);
  }
  return ans;
}

int sum_smaller(pnode_bin cur, int key, int id = MD) {
  if (cur == NULL) return 0;
  if (id < 0) return 0;  // strictly smaller
  // if (id == - 1) return cur->val;  // smaller or equal

  int ans = 0;
  int to = (key >> id) & 1;
  if (to) {
    if (cur->child[0]) ans += cur->child[0]->val;
    ans += sum_smaller(cur->child[1], key, id - 1);
  } else {
    ans = sum_smaller(cur->child[0], key, id - 1);
  }
  return ans;
}


const int MAX_CHILD = 26;
struct node {
  node *child[MAX_CHILD];
  int val;
  node() : val(-1) {
    for (int i = 0; i < MAX_CHILD; i++) {
      child[i] = NULL;
    }
  }
};

typedef node* pnode;

pnode copy_node(pnode cur) {
  pnode ans = new node();
  if (cur) *ans = *cur;
  return ans;
}

pnode set_val(pnode cur, string &key, int val, int id = 0) {
  pnode ans = copy_node(cur);
  if (id >= int(key.size())) {
    ans->val = val;
  } else {
    int t = key[id] - 'a';
    ans->child[t] = set_val(ans->child[t], key, val, id + 1);
  }
  return ans;
}

pnode get(pnode cur, string &key, int id = 0) {
  if (id >= int(key.size()) || !cur)
    return cur;
  int t = key[id] - 'a';
  return get(cur->child[t], key, id + 1);
}

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n;
  cin >> n;

  vector<pnode> keys;
  vector<pnode_bin> values;

  keys.push_back(new node());
  values.push_back(new node_bin());

  while (n--) {
    string op;
    cin >> op;

    pnode cur_keys = keys.back();
    pnode_bin cur_values = values.back();

    assert(keys.size() == values.size());

    if (op == "set") {
      string id; cin >> id;
      int val; cin >> val;
      pnode last = get(cur_keys, id);
      if (last != NULL && last->val >= 0) {
        int old_value = last->val;
        keys.push_back(set_val(cur_keys, id, val));

        pnode_bin tmp = modify(cur_values, old_value, -1);
        values.push_back(modify(tmp, val, +1));
      } else {
        keys.push_back(set_val(cur_keys, id, val));
        values.push_back(modify(cur_values, val, +1));
      }
    }
    if (op == "remove") {
      string id; cin >> id;
      pnode last = get(cur_keys, id);
      if (last != NULL && last->val >= 0) {
        int old_value = last->val;
        keys.push_back(set_val(cur_keys, id, -1));
        values.push_back(modify(cur_values, old_value, -1));
      } else {
        keys.push_back(keys.back());
        values.push_back(values.back());
      }
    }

    if (op == "query") {
      string id; cin >> id;
      pnode last = get(cur_keys, id);
      if (last != NULL && last->val >= 0) {
        int total = sum_smaller(cur_values, last->val);
        cout << total << endl << flush;
      } else {
        cout << -1 << endl << flush;
      }
      keys.push_back(cur_keys);
      values.push_back(cur_values);
    }

    if (op == "undo") {
      int times; cin >> times;
      keys.push_back(*(keys.end() - times - 1));
      values.push_back(*(values.end() - times - 1));
    }
  }
  return 0;
}
