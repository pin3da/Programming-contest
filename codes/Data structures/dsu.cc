struct Dsu {
  vector<int> p;

  Dsu(int n) {
    p.resize(n);
    for (int i = 0; i < n; i++) {
      p[i] = i;
    }
  }

  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }

  int Join(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return 0;
    p[px] = py;
    return 1;
  }
};
