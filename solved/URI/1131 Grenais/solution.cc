#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int a, b, c = 0, d = 0, e = 0, f = 0;
  int next = 1;
  while (next == 1 && cin >> a >> b) {
    if (a > b)
      c++;
    else if (b > a)
      d++;
    else
      e++;
    cin >> next;
    cout << "Novo grenal (1-sim 2-nao)" << endl;
    ++f;
  }

  cout << f << " grenais" << endl;
  cout << "Inter:" << c << endl;
  cout << "Gremio:" << d << endl;
  cout << "Empates:" << e << endl;
  if (c > d)
    cout << "Inter venceu mais" << endl;
  else if (d > c)
    cout << "Gremio venceu mais" << endl;
  else
    cout << "Nao houve vencedor" << endl;

  return 0;
}
