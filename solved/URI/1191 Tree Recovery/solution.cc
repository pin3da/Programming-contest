#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

#define null NULL

struct node {
  char val;
  node *l, *r;
  node (char t) : val(t), l(null), r(null) {}
};

typedef node* pnode;

pnode parse(string a, string b) {
  if (a.size() == 1)
    return new node(a[0]);

  pnode cur = new node(a[0]);
  int left = 0;
  if (b.find(a[1]) < b.find(a[0])) { // left child
    cur-> l = parse(a.substr(1), b.substr(0, b.find(a[0])));
    left = 1;
  }
  int id = b.find(a[0]) + 1;
  if (b.substr(id).size())
    cur-> r = parse(a.substr(id), b.substr(id));
  return cur;
}

void po(pnode cur) {
  if (cur == null) return;
  po(cur-> l);
  po(cur-> r);
  cout << cur-> val;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string a, b;
  while (cin >> a >> b) {
    pnode root = parse(a, b);
    po(root);
    cout << endl;
  }
  return 0;
}
