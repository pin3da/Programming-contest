using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl

const double EPS = 1e-10;

typedef vector<int> VI;
typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;
typedef VVT Matrix;

T GaussJordan(VVT &a, VVT &b) {
  const int n = a.size();
  const int m = b[0].size();
  VI irow(n), icol(n), ipiv(n);
  T det = 1;

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
        if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    if (fabs(a[pj][pk]) < EPS) { cerr << "Matrix is singular." << endl; exit(0); }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    if (pj != pk) det *= -1;
    irow[i] = pj;
    icol[i] = pk;

    T c = 1.0 / a[pk][pk];
    det *= a[pk][pk];
    a[pk][pk] = 1.0;
    for (int p = 0; p < n; p++) a[pk][p] *= c;
    for (int p = 0; p < m; p++) b[pk][p] *= c;
    for (int p = 0; p < n; p++) if (p != pk) {
      c = a[p][pk];
      a[p][pk] = 0;
      for (int q = 0; q < n; q++) a[p][q] -= a[pk][q] * c;
      for (int q = 0; q < m; q++) b[p][q] -= b[pk][q] * c;
    }
  }

  for (int p = n-1; p >= 0; p--) if (irow[p] != icol[p]) {
    for (int k = 0; k < n; k++) swap(a[k][irow[p]], a[k][icol[p]]);
  }

  return det;
}


vector<map<string, string>> build_machine(string &a, string &b) {
  vector<map<string, string>> ans(2);
  for (int i = 0; i < 2; ++i)
    ans[i][a] = ans[i][b] = "-1";

  for (int tt = 0; tt < 2; ++tt) {
    if (tt & 1) swap(a, b);
    string cur = "";
    for (int i = -1; i < (int) (a.size() - 1); ++i) {
      if (i > -1)
        cur.push_back(a[i]);

      for (int k = 0; k < 2; ++k) {
        string o1 = cur + char('0' + k);
        for (int i = 0; i <= o1.size(); ++i) {
          string ba = o1.substr(i);
          if (a.substr(0, ba.size()) == ba) {
            if (ba.size() > ans[k][cur].size())
              ans[k][cur] = ba;
            break;
          }
        }
        for (int i = 0; i <= o1.size(); ++i) {
          string ba = o1.substr(i);
          if (b.substr(0, ba.size()) == ba) {
            if (ba.size() > ans[k][cur].size())
              ans[k][cur] = ba;
            break;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  while (cin >> a >> b && (a != "0" || b != "0")) {
    vector<map<string, string>> next = build_machine(a, b);
    map<string, int> state;
    for (int i = 0; i < 2;++i) for (const auto &it : next[i]) {
      int id = state.size();
      if (state.count(it.first) == 0)
        state[it.first] = id;
    }

    Matrix A(state.size(), VT(state.size(), 0));
    Matrix B(state.size(), VT(1, 0));
    for (const auto &it : state) {
      if (it.first != a && it.first != b) {
        A[it.second][it.second] += 1.0;
        A[it.second][state[next[0][it.first]]] -= 0.5;
        A[it.second][state[next[1][it.first]]] -= 0.5;
      }
    }

    A[state[a]][state[a]] += 1;
    A[state[b]][state[b]] += 1;

    B[state[a]][0] = 1;

    GaussJordan(A, B);
    printf("%.3lf\n", 1.0 - B[state[""]][0] + EPS);

  }
  return 0;
}

