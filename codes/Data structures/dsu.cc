struct dsu {
  int p[MN];

  void init(int n) {
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  }

  int join(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py)
      return 0;
    p[px] = py;
    return 1;
  }
};
