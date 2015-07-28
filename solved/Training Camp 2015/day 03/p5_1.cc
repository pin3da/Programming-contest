#include <bits/stdc++.h>
using namespace std;

vector<vector<double> > a(5, vector<double>(5));
vector<vector<double> > b(5, vector<double>(1));

void GaussJordan() {
  const int n = 5;
  const int m = 1;
  vector<int> irow(n), icol(n), ipiv(n);

  for (int i = 0; i < n; i++) {
    int pj = -1, pk = -1;
    for (int j = 0; j < n; j++) if (!ipiv[j])
      for (int k = 0; k < n; k++) if (!ipiv[k])
	if (pj == -1 || fabs(a[j][k]) > fabs(a[pj][pk])) { pj = j; pk = k; }
    ipiv[pk]++;
    swap(a[pj], a[pk]);
    swap(b[pj], b[pk]);
    irow[i] = pj;
    icol[i] = pk;

    double c = 1.0 / a[pk][pk];
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
}
const double pi = acos(-1.0);

void solve(double x[], double y[], double tx[], double ty[]) {
  for (int i = 0; i < 3; i++) {
    a[i][0] = x[i]*x[i]; a[i][1] = y[i]*y[i]; a[i][2] = x[i]*y[i]; a[i][3] = x[i]; a[i][4] = y[i];
  }
  int der_add = 0;
  for (int i = 0; der_add < 2; i++) {
    if (fabs(tx[i] - tx[(i+1)%3]) < 1E-9)
      continue;
    double der = (ty[i] - ty[(i+1)%3]) / (tx[i] - tx[(i+1)%3]);
    a[3 + der_add][0] = 2*x[i]; a[3 + der_add][1] = 2*y[i]*der; a[3 + der_add][2] = y[i] + x[i]*der; a[3 + der_add][3] = 1; a[3 + der_add][4] = der;
    der_add++;
  }
  
  for (int i = 0; i < 3; i++)
    b[i][0] = -1;

  GaussJordan();

  double A = b[0][0], B = b[1][0], C = b[2][0], D = b[3][0], E = b[4][0];
  double theta;
  if (fabs(C) < 1E-9)
    theta = 0.0;
  else
    theta = 0.5 * ( fabs(A - B) < 1E-9 ? (C < 0 ? -pi*0.5 : pi*0.5) : atan(C / (A - B)) );
  
  double Anew = A*cos(theta)*cos(theta) + B*sin(theta)*sin(theta) + C*cos(theta)*sin(theta);
  double Bnew = B*cos(theta)*cos(theta) + A*sin(theta)*sin(theta) - C*cos(theta)*sin(theta);
  double Dnew = D*cos(theta) + E*sin(theta);
  double Enew = E*cos(theta) - D*sin(theta);
  
  double xcp = -0.5 * Dnew / Anew, ycp = -0.5 * Enew / Bnew;
  
  double ap = sqrt((0.25*Dnew*Dnew/Anew + 0.25*Enew*Enew/Bnew - 1) / Anew);
  double bp = sqrt((0.25*Dnew*Dnew/Anew + 0.25*Enew*Enew/Bnew - 1) / Bnew);

  bool x_axis = true;
  if (ap < bp) {
    swap(ap, bp);
    x_axis = false;
  }
  theta *= -1;
    
  double fdist = sqrt(ap*ap - bp*bp);
  double xf1, yf1, xf2, yf2;
  if (x_axis) {
    xf1 = xcp - fdist;
    xf2 = xcp + fdist;
    yf1 = yf2 = ycp;
  } else {
    yf1 = ycp - fdist;
    yf2 = ycp + fdist;
    xf1 = xf2 = xcp;
  }
 
  double ans_x1 = xf1*cos(-theta) - yf1*sin(-theta), ans_y1 = yf1*cos(-theta) + xf1*sin(-theta);
  double ans_x2 = xf2*cos(-theta) - yf2*sin(-theta), ans_y2 = yf2*cos(-theta) + xf2*sin(-theta);  
  double ans_dist = sqrt((ans_x1 - x[0])*(ans_x1 - x[0]) + (ans_y1 - y[0])*(ans_y1 - y[0])) + sqrt((ans_x2 - x[0])*(ans_x2 - x[0]) + (ans_y2 - y[0])*(ans_y2 - y[0]));

  if (ans_x1 > ans_x2) {
    swap(ans_x1, ans_x2);
    swap(ans_y1, ans_y2);
  }
  else if (fabs(ans_x1 - ans_x2) <= 1E-9 and ans_y1 > ans_y2) {
    swap(ans_x1, ans_x2);
    swap(ans_y1, ans_y2);
  }
  
  printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n", ans_x1, ans_y1, ans_x2, ans_y2, ans_dist);
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    double x[3], y[3];
    for (int j = 0; j < 5; j++) {
      a[j].assign(5, 0.0);
      b[j].assign(1, 0.0);
    }
    for (int j = 0; j < 3; j++)
      cin >> x[j] >> y[j];
    double nx[3], ny[3];
    for (int j = 0; j < 3; j++) {
      double aux[] = {(x[(j+1)%3] - x[j]) * 0.5, (y[(j+1)%3] - y[j]) * 0.5};
      nx[j] = x[j] + aux[0]; ny[j] = y[j] + aux[1];
    }
    cout << i+1 << " ";
    solve(nx, ny, x, y);
  }
  return 0;
}
