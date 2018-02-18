struct board {
  int n, m, r;
  board(int a, int b, int c = 1) : n(a), m(b), r(c) {}

  long long frec(int x, int y) {
    // returns how many squares of r x r contain the cell (x, y)
    long long a = min(x, n - r) - max(x - r + 1, 0) + 1;
    long long b = min(y, m - r) - max(y - r + 1, 0) + 1;
    return a * b;
  }

  bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }
};
