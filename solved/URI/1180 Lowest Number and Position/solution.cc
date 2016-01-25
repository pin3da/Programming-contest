#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  cout << "Menor valor: " << *min_element(a.begin(), a.end()) << endl;
  cout << "Posicao: " << min_element(a.begin(), a.end()) - a.begin() << endl;
  return 0;
}
