struct binary_index_tree {
  int n;
  int t[2 * N];

  void add(int where, long long what){
    for (where++; where <= n; where += where & -where){
      t[where] += what;
    }
  }

  void add(int from, int to, long long what) {
    add(from, what);
    add(to + 1, -what);
  }

  long long query(int where){
    long long sum = t[0];
    for (where++; where > 0; where -= where & -where){
      sum += t[where];
    }
    return sum;
  }
};
