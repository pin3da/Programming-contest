#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x " = " << (x) << endl

int main() {
#ifndef LOCAL
#define endl '\n'
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n, m; cin >> n >> m;
  map<string, string> ips;
  for (int i = 0; i < n; i++) {
    string a, b; cin >> a >> b;
    ips[b] = a;
  }

  for (int i = 0; i < m; i++) {
    string command, ip;
    cin >> command >> ip;
    ip = ip.substr(0, ip.size() - 1);
    cout << command << " " << ip << "; #" << ips[ip] << endl;
  }
  return 0;
}
