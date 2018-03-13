// this can be tested in the problem: http://www.spoj.com/problems/ILKQUERY/

struct wavelet {
  vector<int> values, ori;
  vector<int> map_left, map_right;
  int l, r, m;
  wavelet *left, *right;
  wavelet() : left(NULL), right(NULL) {}
  wavelet(int a, int b, int c) : l(a), r(b), m(c), left(NULL), right(NULL) {}
};

wavelet *init(vector<int> &data, vector<int> &ind, int lo, int hi) {
  if (lo > hi || (data.size() == 0)) return NULL;
  int mid = ((long long)(lo) + hi) / 2;
  if (lo + 1 == hi) mid = lo; // handle negative values

  wavelet *node = new wavelet(lo, hi, mid);

  vector<int> data_l, data_r, ind_l, ind_r;
  int ls = 0, rs = 0;
  for (int i = 0; i < int(data.size()); i++) {
    int value = data[i];
    if (value <= mid) {
      data_l.emplace_back(value);
      ind_l.emplace_back(ind[i]);
      ls++;
    } else {
      data_r.emplace_back(value);
      ind_r.emplace_back(ind[i]);
      rs++;
    }
    node->map_left.emplace_back(ls);
    node->map_right.emplace_back(rs);
    node->values.emplace_back(value);
    node->ori.emplace_back(ind[i]);
  }

  if (lo < hi) {
    node->left = init(data_l, ind_l, lo, mid);
    node->right = init(data_r, ind_r, mid + 1, hi);
  }
  return node;
}

int kth(wavelet *node, int to, int k) {
  // returns the kth element in the sorted version of (a[0], ..., a[to])
  if (node->l == node->r) return node->m;
  int c = node->map_left[to];
  if (k < c)
    return kth(node->left, c - 1, k);
  return kth(node->right, node->map_right[to] - 1, k - c);
}

int pos_kth_ocurrence(wavelet *node, int val, int k) {
  // returns the position on the original array of the kth ocurrence of the value "val"
  if (!node) return -1;

  if (node->l == node->r) {
    if (int(node->ori.size()) <= k)
      return -1;
    return node->ori[k];
  }

  if (val <= node->m)
    return pos_kth_ocurrence(node->left, val, k);
  return pos_kth_ocurrence(node->right, val, k);
}
