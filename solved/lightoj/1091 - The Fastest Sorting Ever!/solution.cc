using namespace std;
#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

void gen_print(int n) {
  cout << "void print(";
  for (int i = 0; i <  n; ++i) {
    if (i) cout << ", ";
    cout << "int " << (char)(i + 'a');
  }
  cout << ") {" << endl;
  cout << "  printf(\"";
  for (int i = 0; i <  n; ++i) {
    if (i) cout << " ";
    cout << "%d";
  }
  cout << "\\n\"";
  for (int i = 0; i <  n; ++i) {
    cout << ", " << (char)(i + 'a');
  }
  cout << ");" << endl;
  cout << "}" << endl;
};

// int mark[7][7];
enum rel {normal = 1, inv = 2};

void gen(vector<char> d, vector<vector<int> > mark, int idx, int jdx) {
  if (idx == d.size() - 1) {
    cout << "print(";
    for (int i = 0; i < d.size(); ++i) {
      if (i) cout << ", ";
      cout << d[i];
    }
    cout << ");" << endl;
    return;
  }

  if (mark[d[idx] - 'a'][d[jdx] - 'a']) {
    swap(d[idx], d[jdx]);

    if (jdx == d.size() - 1)
      gen(d, mark, idx + 1, idx + 2);
    else
      gen(d, mark, idx, jdx + 1);
    return;
  }

  cout << "if (" << d[idx] << " < " << d[jdx] << ")" << endl;

  mark[d[idx] - 'a'][d[jdx] - 'a'] = normal;
  mark[d[jdx] - 'a'][d[idx] - 'a'] = inv;

  if (jdx == d.size() - 1)
    gen(d, mark, idx + 1, idx + 2);
  else
    gen(d, mark, idx, jdx + 1);

  cout << "else" << endl;
  swap(d[idx], d[jdx]);
  mark[d[idx] - 'a'][d[jdx] - 'a'] = inv;
  mark[d[jdx] - 'a'][d[idx] - 'a'] = normal;

  if (jdx == d.size() - 1)
    gen(d, mark, idx + 1, idx + 2);
  else
    gen(d, mark, idx, jdx + 1);

}

void solve() {
  int n;
  cin >> n;
  vector<char> data(n);
  for (int i = 0; i < n; ++i)
    data[i] = 'a' + i;

  gen_print(n);
  vector<vector<int> > mark(n, vector<int> (n));
  cout << "void sort(";
  for (int i = 0; i < n; ++i) {
    if (i) cout << ", ";
    cout << "int " << (char)(i + 'a');
  }
  cout << ") {" << endl;
  gen(data, mark, 0, 1);
  cout << "}" << endl;
}

int main() {
  // ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    printf("Case %d:\n", i + 1);
    solve();
  }
}

