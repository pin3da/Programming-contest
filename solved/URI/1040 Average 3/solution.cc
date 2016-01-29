#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  vector<double> a(4);
  double av = 0, t;
  vector<double> w({2, 3, 4, 1});
  for (size_t i = 0; i < 4; ++i) {
    cin >> t;
    av += t * w[i];
  }
  av /= 10;
  cout << "Media: " << fixed << setprecision(1) << av << endl;
  if (av < 4.999999) {
    cout << "Aluno reprovado." << endl;
    return 0;
  }
  if (av > 6.99999) {
    cout << "Aluno aprovado."  << endl;
    return 0;
  }

  cout << "Aluno em exame." << endl;
  cin >> t;
  cout << "Nota do exame: " << t << endl;
  av += t;
  av *= 0.5;
  if (av < 4.9999999)
    cout << "Aluno reprovado." << endl;
  else
    cout << "Aluno aprovado." << endl;
  cout << "Media final: " << av << endl;
  return 0;
}
