#include<bits/stdc++.h>

using namespace std;
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

const double PI = acos(-1.0);

struct cpx {
  double real, image;
  cpx(double _real, double _image) {
    real = _real;
    image = _image;
  }
  cpx(){}
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

const int MN = 1 << 21;
cpx A[MN];

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

int d[MN];
cpx first[MN];
cpx second[MN];

const double eps = 1e-9;

void solve(string &line) {
  memset(d, 0, sizeof d);
  int t;
  for (int i = 0; i < line.size(); ++i) {
    d[i] = line[i] == 'B';
  }

  for (int i = 0; i < MN; ++i) {
    if (d[i]) {
      first[i]  = cpx(1, 0);
      second[i] = cpx(0, 0);
    } else {
      first[i]  = cpx(0, 0);
      if (i < line.size())
        second[i] = cpx(1, 0);
      else
        second[i] = cpx(0, 0);
    }
  }

  reverse(second, second + MN);
  FFT(first, MN, 1);
  FFT(second, MN, 1);
  for (int i = 0; i < MN; ++i) {
    first[i] = first[i] * second[i];
  }
  FFT(first, MN, -1);

  for (int i = 0; i < line.size() - 1; ++i) {
    double cur = round(first[MN - 2 - i].real);
    if (cur < eps) cur = 0;
    cout << (int)cur << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    solve(line);
  }
  return 0;
}
