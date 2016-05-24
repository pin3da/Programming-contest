#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

#define null NULL

struct node_t {
  string op;
  node_t *l, *r;
  node_t (string a) : op(a), l(null), r(null) {}
  node_t () : op(""), l(null), r(null) {}
};

typedef node_t* pnode;

deque<string> lexer(string a) {
  deque<string> q;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '(')      q.push_back("(");
    else if (a[i] == ')') q.push_back(")");
    else if (a[i] == '*') q.push_back("*");
    else if (a[i] == '+') q.push_back("+");
    else if (a[i] == '-') q.push_back("-");
    else {
      string cur;
      while (a[i] != '}') {
        cur.push_back(a[i]);
        i++;
      }
      cur.push_back(a[i]);
      q.push_back(cur);
    }
  }
  return q;
}

struct parser {
  deque<string> tokens;
  parser(deque<string> t) : tokens(t) {}

  pnode A() {
    pnode node = B();
    while (tokens.size() &&
        (tokens.front() == "+" || tokens.front() == "-")) {

      pnode tmp = new node_t();
      tmp-> op = tokens.front(); tokens.pop_front();
      tmp-> l = node;
      tmp-> r = B();
      node = tmp;
    }
    return node;
  }

  pnode B() {
    pnode node = C();
    while (tokens.size() && tokens.front() == "*") {
      pnode tmp = new node_t();
      tmp-> op = tokens.front(); tokens.pop_front();
      tmp-> l = node;
      tmp-> r = C();
      node = tmp;
    }
    return node;
  }

  pnode C() {
    pnode node;
    if (tokens.front() == "(") {
      tokens.pop_front();
      node = A();
      tokens.pop_front();
    } else {
      node = new node_t(tokens.front());
      tokens.pop_front();
    }
    return node;
  }
};

void mfree(pnode node) {
  if (node == null) return;
  mfree(node-> l);
  mfree(node-> r);
  delete node;
}

set<char> eval(pnode node) {
  if (node-> op[0] == '{') {
    set<char> ans;
    for (int i = 1; i + 1 < node-> op.size(); ++i)
      ans.insert(node-> op[i]);
    return ans;
  }

  if (node-> op == "*") {
    set<char> ans;
    set<char> l = eval(node-> l);
    set<char> r = eval(node-> r);
    for (auto &i : r)
      if (l.count(i))
        ans.insert(i);
    return ans;
  }
  if (node-> op == "+") {
    set<char> l = eval(node-> l);
    set<char> r = eval(node-> r);
    for (auto &i : r) l.insert(i);
    return l;
  }
  if (node-> op == "-") {
    set<char> l = eval(node-> l);
    set<char> r = eval(node-> r);
    for (auto &i : r) l.erase(i);
    return l;
  }
  D(node-> op);
  assert(false);
}

void print(pnode node, string depth = ""){
  cout<<depth<<" ";
  if (!(node-> l)) {
    cout << node-> op << endl;
  } else {
    cout << "   " << node-> op << endl;
    for (int i = 0; i < depth.size(); ++i)
      if(depth[i] == '+' or depth[i]=='-') depth[i] = ' ';
    print(node-> l, depth + "    |-- ");
    print(node-> r, depth + "    +-- ");
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    deque<string> tokens = lexer(line);
    // for (auto &i : tokens)
    //  cout << i << endl;
    parser p(tokens);
    pnode root = p.A();
    // print(root);
    set<char> ans = eval(root);
    cout << "{";
    for (auto &i : ans) cout << i;
    cout << "}" << endl;
    mfree(root);
  }
  return 0;
}
