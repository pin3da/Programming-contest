#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x " = " << (x) << endl

const double PI = acos(-1.0);

struct cpx {
  double real, image;
  cpx(double _real, double _image) {
    real = _real;
    image = _image;
  }
  cpx() : real(0), image(0) {}
};

cpx operator + (const cpx &c1, const cpx &c2) {
  return cpx(c1.real + c2.real, c1.image + c2.image);
}

cpx operator - (const cpx &c1, const cpx &c2) {
  return cpx(c1.real - c2.real, c1.image - c2.image);
}

cpx operator * (const cpx &c1, const cpx &c2) {
  return cpx(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}

int rev(int id, int len) {
  int ret = 0;
  for (int i = 0; (1 << i) < len; i++) {
    ret <<= 1;
    if (id & (1 << i)) ret |= 1;
  }
  return ret;
}

const int MN = 1 << 25;
cpx *A;

void FFT(cpx *a, int len, int DFT) {
  for (int i = 0; i < len; i++)
    A[rev(i, len)] = a[i];
  for (int s = 1; (1 << s) <= len; s++) {
    int m = (1 << s);
    cpx wm = cpx(cos( DFT * 2 * PI / m), sin(DFT * 2 * PI / m));
    for(int k = 0; k < len; k += m) {
      cpx w = cpx(1, 0);
      for(int j = 0; j < (m >> 1); j++) {
        cpx t = w * A[k + j + (m >> 1)];
        cpx u = A[k + j];
        A[k + j] = u + t;
        A[k + j + (m >> 1)] = u - t;
        w = w * wm;
      }
    }
  }
  if (DFT == -1) for (int i = 0; i < len; i++) A[i].real /= len, A[i].image /= len;
  for (int i = 0; i < len; i++) a[i] = A[i];
  return;
}

cpx *first;
cpx *second;

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int S = MN * sizeof(cpx);
  A = (cpx *) malloc(MN * sizeof (cpx));
  first = (cpx *) malloc(MN * sizeof (cpx));
  second = (cpx *) malloc(MN * sizeof (cpx));

  memset(A, 0, sizeof S);
  memset(first, 0, sizeof S);
  memset(second, 0, sizeof S);

  string line;
  cin >> line;

  deque<int> sum(line.size());
  for (int i = 0; i < (int)line.size(); i++) {
    sum[i] = line[i] - 'a' + 1;
    if (i) sum[i] += sum[i - 1];
  }

  sum.push_front(0);
  int n = sum.size();

  for (int i = 0; i < n; i++) {
    first[sum[i]] = cpx(1, 0);
    second[sum.back() - sum[i]] = cpx(1, 0);
  }

  FFT(first, MN, 1);
  FFT(second, MN, 1);
  for (int i = 0; i < MN; i++)
    first[i] = first[i] * second[i];

  FFT(first, MN, -1);

  long long ans = 0;
  for (int i = sum.back() + 1; i < MN; i++) {
    if (first[i].real > 0.5) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
