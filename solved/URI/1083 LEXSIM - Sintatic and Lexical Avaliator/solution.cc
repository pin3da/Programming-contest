#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

enum token_t {
  VAR,
  RPAREN,
  LPAREN,
  XOR,
  MULT,
  DIV,
  PLUS,
  MINUS,
  LBRA,
  RBRA,
  EQUAL,
  SHARP,
  AND,
  OR,
  NONE
};

struct token {
  token_t type;
  char val;
  token(token_t a) : type(a), val(0) {}
  token(token_t a, char v) : type(a), val(v) {}
};

bool is_var(char p) {
  if ('A' <= p && p <= 'Z') return true;
  if ('a' <= p && p <= 'z') return true;
  if ('0' <= p && p <= '9') return true;
  return false;
}

bool lexer(const string &p, deque<token> &t) {
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == '^')      t.push_back(token(XOR, p[i]));
    else if (p[i] == '*') t.push_back(token(MULT, p[i]));
    else if (p[i] == '/') t.push_back(token(DIV, p[i]));
    else if (p[i] == '+') t.push_back(token(PLUS, p[i]));
    else if (p[i] == '-') t.push_back(token(MINUS, p[i]));
    else if (p[i] == '>') t.push_back(token(RBRA, p[i]));
    else if (p[i] == '<') t.push_back(token(LBRA, p[i]));
    else if (p[i] == '=') t.push_back(token(EQUAL, p[i]));
    else if (p[i] == '#') t.push_back(token(SHARP, p[i]));
    else if (p[i] == '(') t.push_back(token(LPAREN, p[i]));
    else if (p[i] == ')') t.push_back(token(RPAREN, p[i]));
    else if (p[i] == '.') t.push_back(token(AND, p[i]));
    else if (p[i] == '|') t.push_back(token(OR, p[i]));
    else if (is_var(p[i])) t.push_back(token(VAR, p[i]));
    else return false;
  }
  return true;
}

struct node {
  int l, r, t;
  char val;
  token_t op;
  node(char a,int b) :
    l(-1), r(-1), val(a), t(b), op(NONE) {}
  node(int la, int ra, token_t t, char v) :
    l(la), r(ra), val(v), t(-1), op(t) {}
};

struct ast {
  vector<node> nodes;

  int add(int val, int is_var) {
    nodes.push_back(node(val, is_var));
    return nodes.size() - 1;
  }

  int add(int l, int r, token_t t, char v) {
    nodes.push_back(node(l, r, t, v));
    return nodes.size() - 1;
  }
  void posfix(int node) {
    if (nodes[node].l != -1) posfix(nodes[node].l);
    if (nodes[node].r != -1) posfix(nodes[node].r);
    cout << nodes[node].val;
  }

  void infix(int node) {
    if (nodes[node].l != -1) infix(nodes[node].l);
    cout << nodes[node].val;
    if (nodes[node].r != -1) infix(nodes[node].r);
  }

  size_t size(int node) {
    size_t ans = 1;
    if (nodes[node].l != -1) ans += size(nodes[node].l);
    if (nodes[node].r != -1) ans += size(nodes[node].r);
    return ans;
  }
};

struct parser {
  deque<token> tokens;
  parser(deque<token> t) : tokens(t) {}

  token_t top() {
    if (tokens.empty()) return NONE;
    return tokens.front().type;
  }

  token pop() {
    if (tokens.empty()) return token(NONE);
    token t = tokens.front();
    tokens.pop_front();
    return t;
  }

  int A(ast &tree) {
    int left = B(tree);
    if (left == -1) return -1;
    while (top() == OR) {
      token op = pop();
      int right = B(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, op.type, op.val);
    }
    return left;
  }

  int B(ast &tree) {
    int left = C(tree);
    if (left == -1) return -1;
    while (top() == AND) {
      token op = pop();
      int right = C(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, op.type, op.val);
    }
    return left;
  }

  int C(ast &tree) {
    int left = D(tree);
    if (left == -1) return -1;
    while (top() == RBRA || top() == LBRA || top() == EQUAL
           || top() == SHARP) {

      token op = pop();
      int right = D(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, op.type, op.val);
    }
    return left;
  }

  int D(ast &tree) {
    int left = E(tree);
    if (left == -1) return -1;
    while (top() == PLUS || top() == MINUS) {
      token op = pop();
      int right = E(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, op.type, op.val);
    }
    return left;
  }

  int E(ast &tree) {
    int left = F(tree);
    if (left == -1) return -1;
    while (top() == MULT || top() == DIV) {
      token op = pop();
      int right = F(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, op.type, op.val);
    }
    return left;
  }

  int F(ast &tree) {
    int left = G(tree);
    if (left == -1) return -1;
    while (top() == XOR) {
      pop();
      int right = G(tree);
      if (right == -1) return -1;
      left = tree.add(left, right, XOR, '^');
    }
    return left;
  }

  int G(ast &tree) {
    if (top() == LPAREN) {
      pop();
      int t = A(tree);
      if (top() != RPAREN) return -1;
      pop();
      return t;
    } else if (top() == VAR) {
      return tree.add(pop().val, true);
    } else {
      return -1;
    }
  }

};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  string line;
  while (cin >> line) {
    deque<token> t;
    if (!lexer(line, t)) {
      cout << "Lexical Error!" << endl;
      continue;
    }
    ast tree;
    parser p(t);
    int root = p.A(tree);
    if (root == -1 || p.tokens.size()) {
      cout << "Syntax Error!" << endl;
      continue;
    }
    tree.posfix(root);
    cout << endl;
  }
  return 0;
}
