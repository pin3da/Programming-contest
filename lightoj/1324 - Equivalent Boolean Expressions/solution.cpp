using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl

enum token_type{
    VAR,
    LPAREN,
    RPAREN,
    AND,
    OR,
    NOT,
    NONE
};

struct token{
    token_type t;
    int v;
    token(){}
    token(token_type _t, int _v=0): t(_t), v(_v){}
};

int num_vars;
queue<token> lexer(const string &s){
    queue<token> tk;
    for(int i = 0; i < s.size(); ++i){
        if     (s[i] == '!')      tk.push(token(NOT));
        else if(s[i] == '(') tk.push(token(LPAREN));
        else if(s[i] == ')') tk.push(token(RPAREN));
        else if(s[i] == '&') tk.push(token(AND));
        else if(s[i] == '|') tk.push(token(OR));
        else {
            tk.push(token(VAR, s[i] - 'a'));
            num_vars = max(num_vars, s[i] -'a');
        }
    }
    return tk;
}

struct node{
    int left,right;
    int id;
    token_type op;
    node(int a): left(-1),right(-1), id(a), op(NONE) {}
    node(int l,int r, token_type t): left(l), right(r), id(-1), op(t) {}
};

struct ast{
    vector<node> nodes;
    
    int add(int val){
        nodes.push_back(node(val));
        return nodes.size() - 1;
    }
    
    int add(int l, int r, token_type t){
        nodes.push_back(node(l,r,t));
        return nodes.size() - 1;
    }
    
    void print(int node_id, string depth = ""){
        node &n = nodes[node_id];
        cout<<depth<<" ";
        if(n.left == -1){ //leaf
            cout<<((char)(n.id+'a'))<<endl;
        }else if(n.right == -1){
            cout<<'!'<<endl;
            for(int i = 0; i< depth.size(); ++i) if(depth[i] == '+' or depth[i]=='-') depth[i] = ' ';
            print(n.left,  depth + " +-- ");
        }else{
            char op;
            
            if(n.op == OR)  op = 'X';
            if(n.op == AND) op = '&';
            cout<<op<<endl;
            for(int i = 0; i< depth.size(); ++i) if(depth[i] == '+' or depth[i]=='-') depth[i] = ' ';
            print(n.left,  depth + " |-- ");
            print(n.right, depth + " +-- ");
        }
    }
    
    bool eval(int node_id, int &mask){
        node &n = nodes[node_id];
        
        if(n.left == -1)
            return ((1<<n.id)&mask) != 0;
        if(n.op == NOT)
            return ! eval(n.left,mask);
        if(n.op == OR)
            return eval(n.left,mask) or eval(n.right,mask);
        else
            return eval(n.left,mask) and eval(n.right,mask);
    }
    
};

struct parser{

    queue<token> tokens;
    parser(queue<token> t):tokens(t){}
    
    token_type top() {
        if (tokens.empty()) return NONE;
        return tokens.front().t;
    }
    
    token pop() {
        if (tokens.empty()) return token(NONE);
        token t = tokens.front();
        tokens.pop();
        return t;
    }
    
    int expression(ast &tree){
        int left = term(tree);
        while(top() == OR){
            pop();
            int right = term(tree);
            left = tree.add(left,right,OR);
        }
        return left;
    }
    
    int term(ast &tree){
        int left = factor(tree);
        while(top() == AND){
            pop();
            int right = factor(tree);
            left = tree.add(left, right, AND);
        }
        return left;
    }
    
    
    int factor(ast &tree){
        int times = 0;
        while(top() == NOT){
            pop();
            times++;
        }
        if(times%2) return tree.add(sub(tree),-1,NOT);
        else return sub(tree);
    }
    
    
    int sub(ast &tree){
        if(top() == LPAREN){
            pop();
            int t = expression(tree);
            pop();
            return t;
        }
        return tree.add(pop().v);
        
    }
};

string e1, e2;

void read(){
    cin>>e1>>e2;
}


string solve(){
    
    num_vars = 0;
    queue<token> tk1 = lexer(e1);
    queue<token> tk2 = lexer(e2);
    
    parser p1(tk1);
    parser p2(tk2);
    ast tree1,tree2;
    
    int root1 = p1.expression(tree1);
    int root2 = p2.expression(tree2);
    
    /*tree1.print(root1);
    tree2.print(root2);*/
    num_vars++;
    int tope = 1<<num_vars;
    
    for(int mask = 0; mask < tope; ++mask){ 
        if(tree1.eval(root1,mask) != tree2.eval(root2,mask))return "Not Equivalent";
    }
    return "Equivalent";
}

int main(){ ___
    int t;cin>>t;
    for(int i = 0 ; i < t; ++i, read(), printf("Case %d: %s\n",i,solve().c_str()));
    return 0;
}
