#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  unordered_map<string, vector<string>> ans;
  ans["tesoura"].emplace_back("papel");
  ans["tesoura"].emplace_back("lagarto");
  ans["papel"].emplace_back("pedra");
  ans["papel"].emplace_back("spock");
  ans["pedra"].emplace_back("lagarto");
  ans["pedra"].emplace_back("tesoura");
  ans["lagarto"].emplace_back("spock");
  ans["lagarto"].emplace_back("papel");
  ans["spock"].emplace_back("tesoura");
  ans["spock"].emplace_back("pedra");
  int c;
  cin >> c;
  while (c--) {
    string a, b;
    cin >> a >> b;
    if (ans[a][0] == b || ans[a][1] == b)
      cout << "rajesh" << endl;
    else if (ans[b][0] == a || ans[b][1] == a)
      cout << "sheldon" << endl;
    else
      cout << "empate" << endl;
  }
  return 0;
}
