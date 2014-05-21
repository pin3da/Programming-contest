using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

const int MN = 1001;
int nums[MN];
int n;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS){
    return( x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MP = 20001;
int ind[MP];

struct Reader {
    int b; Reader() { read(); }
    void read() { b = getchar_unlocked(); }
    void skip() { while (0 <= b && b <= 32) read(); }

    unsigned int next_u32() {
        unsigned int v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
    int next_int() {
        int v = 0; bool s = false;
        skip(); if (b == '-') { s = true; read(); }
        for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
    char next_char() { skip(); char c = b; read(); return c; }
    void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }

    bool has_next() { skip(); return b > 0; }
    bool has_next_u32() { skip(); return 48 <= b && b <= 57; }
    bool has_next_int() { skip(); return b == 45 || (48 <= b && b <= 57); }

    void skip_line() {
        for (; b != 10 && b != 13 && b >= 0; read());
        char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
    void next_line(char *s) {
        for (; b != 10 && b != 13 && b >= 0; read()) *s++ = b; *s = 0;
        while (b == 10 || b == 13) read(); }
    void next_real_line(char *s, int &l) {
        for (l = 0; b != 10 && b != 13 && b >= 0; read()) *s++ = b, ++l;
        *s = 0; char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
};

void mio() {
  int off = 10000;
  memset(ind, 0, sizeof ind);
  for (int i = 0; i < n; ++i) {
    ind[nums[i] + off]++;
  }
  int k = 0;
  for (int i = 0; i < MP; ++i) {
    for (int j = 0; j < ind[i]; ++j)
      nums[k++] = i - off;
  }
}

double f(double pos) {
  double ans = 0;
  for (int i  = 0; i < n; ++i) {
    if (cmp(nums[i], pos) == -1)
      ans += (1.0 / (pos - nums[i]));
    else
      ans -= (1.0 / (nums[i] - pos));
  }
  return ans;
}

const double eps = 1e-6;

int main() {
  int tmp;
  Reader rd;
  while (true) {
    n = rd.next_int();
    if (n== 0) break;
    for (int i = 0; i < n; ++i) {
      nums[i] = rd.next_int();
    }
    if (n == 1) {
      printf("The planet is doomed.\n");
      continue;
    }
    //sort(nums, nums + n);
    mio();
    /*for (int i = 0; i < n; ++i)
      cout<<nums[i]<<" ";
    cout<<endl;*/

    printf("%d", n -1);

    for (int i = 0; i < n -1; ++i) {
      double lo = nums[i];
      double hi = nums[i+1];
      while (cmp(hi, lo) == 1) {
        double mid = (hi + lo) / 2.0;
        double tt = f(mid);
        if (tt > 0)
          lo = mid;
        else
          hi = mid;
      }
      printf(" %.3lf",lo);
    }
    printf("\n");

  }
  return 0;
}
