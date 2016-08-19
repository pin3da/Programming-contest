#include <bits/stdc++.h>

#include "persistent_array.cc"

using namespace std;

void free_memory(pnode node) {
  if (node == NULL) return;
  free_memory(node->l);
  free_memory(node->r);
  delete node;
}

void random_values() {
  int max_len = 100;
  vector<int> data(max_len);
  pnode root = NULL;
  for (int i = 0; i < data.size(); ++i) {
    data[i] = random();
    root = update(root, 0, max_len, i, data[i]);
  }

  vector<int> data2 = data;
  int pos = random() % data.size();
  data2[pos] = random();
  pnode ant = root;
  root = update(root, 0, max_len, pos, data2[pos]);
  for (int i = 0; i < max_len; ++i) {
    assert(get(root, 0, max_len, i) == data2[i]);
    assert(get(ant, 0, max_len, i) == data[i]);
  }
}

int main() {
  int seed = time(NULL);
  printf("Random seed = %d\n", seed);
  srand(seed);
  random_values();
  printf("Everything OK (random seed = %d).\n", seed);
  return 0;
}
