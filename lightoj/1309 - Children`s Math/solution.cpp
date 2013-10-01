using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl

template<class T> int to_int(T t){stringstream ss;ss<<t;int r;ss>>r;return r;}

/*
* Alphabet : x , +, - , * , ( , ), = , DIGIT(0,9)
*/

enum token_type {
    NUM,
    VAR,
    RPAREN,
    LPAREN,
    EQUALS,
    PLUS,
    MINUS,
    TIMES,
    NONE
};

struct token{
   token_type t;
   int val;
   token(token_type _t): t(_t), val(0){}
   token(token_type _t,int _v): t(_t) , val(_v){}
};

queue<token> lexer(const string &line){
    queue<token> tokens;
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == 'x') tokens.push(token(VAR));
        else if(line[i] == '+') tokens.push(token(PLUS));
        else if(line[i] == '-') tokens.push(token(MINUS));
        else if(line[i] == '(') tokens.push(token(LPAREN));
        else if(line[i] == ')') tokens.push(token(RPAREN));
        else if(line[i] == '*') tokens.push(token(TIMES));
        else if(line[i] == '=') tokens.push(token(EQUALS));
        else{
            string tmp;
            while(i < line.size() and isdigit(line[i]))
                tmp+=line[i++];
            tokens.push(token(NUM,to_int(tmp)));
            --i;
        }
    }
    return tokens;
}

struct node{
    int left,right;
    int val,is_var;
    token_type op;
    node(int a,int b): left(-1),right(-1),val(a), is_var(b), op(NONE) {}
    node(int l,int r, token_type t): left(l), right(r), val(-1),is_var(-1), op(t) {}
};

struct ast{
    vector<node> nodes;
    
    int add(int val,int is_var){
        nodes.push_back(node(val,is_var));
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

            if(n.is_var)
                cout<<"x"<<endl;
            else
                cout<<n.val<<endl;
        }else{
            char op;
            if(n.op == TIMES)   op = '*';
            if(n.op == MINUS)   op = '-';
            if(n.op == PLUS)    op = '+';
            if(n.op == EQUALS)  op = '=';
            cout<<"   "<<op<<endl;
            for(int i = 0; i< depth.size(); ++i) if(depth[i] == '+' or depth[i]=='-') depth[i] = ' ';
            print(n.left, depth +  "    |-- ");
            print(n.right, depth + "    +-- ");
        }
    }
    
    /**
    * The goal is transform the ecuation to : ax = b;
    */
    void simplify(int node_id, int &a ,int &b){
        node &n = nodes[node_id];
        if(n.left == -1){ //leaf
            if(n.is_var){
                a = 1;
                b = 0;
            }else{
                a = 0;
                b = n.val;
            }
        }else{
            int al,bl,ar,br;
            simplify(n.left,al,bl);
            simplify(n.right,ar,br);
            if(n.op == TIMES){
                a = al*br + ar*bl; // someone of these values must be 0;
                b = bl*br;
            }else if(n.op == PLUS){
                a = al + ar;
                b = bl + br;
            }else if(n.op == MINUS){
                a = al - ar;
                b = bl - br;
            }else if(n.op == EQUALS){
                a = al - ar; // move to left side
                b = br - bl; // move to right side
            }
        }
    }

};

/* Grammar
* Equation => Expression '=' Expression
* Expression => Term | Expression '+' Term  | Expression '-' Term
* Term => Factor | Factor '*' Factor
* Factor => Number | 'x' | '(' Expression ')'
*/

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
    
    int equation(ast &tree){
        int left = expression(tree);
        pop();
        int right = expression(tree);
        return tree.add(left,right,EQUALS);
    }
    
    int expression(ast &tree){
        int left = term(tree);
        while(top() == PLUS or top() == MINUS){
            token_type op = pop().t;
            int right = term(tree);
            left = tree.add(left,right,op);
        }
        return left;
    }
    
    int term(ast &tree){
        int left = factor(tree);
        while(top() == TIMES){
            pop();
            int right = factor(tree);
            left = tree.add(left,right,TIMES);
        }
        return left;
    }
    
    int factor(ast &tree){
        if(top() == LPAREN){
            pop();
            int t = expression(tree); 
            pop();
            return t;
        }else if(top() == NUM)
            return tree.add(pop().val,0);
        pop();
        return tree.add(0,1);
    }
    
};

void solve(const string &line){

    queue<token> tokens = lexer(line);
    parser p(tokens);
    ast tree;
    int root = p.equation(tree);
    //tree.print(root);
    //cout<<"======================="<<endl;
    int a,b;
    tree.simplify(root,a,b);
    if(a==0){
        if(b==0)
            cout<<"infinitely many solutions"<<endl;
        else
            cout<<"no solution"<<endl;
    }else{
        int g = __gcd(abs(a),abs(b));
        a/=g;
        b/=g;
        if(a < 0) a*= -1, b*=-1;
        if(a==1)cout<<b<<endl;
        else cout<<b<<"/"<<a<<endl;
    }
}


int main(){ ___
    int tc;cin>>tc;
    string line;
    for(int t = 0; t < tc; ++t){
        cin>>line;
        cout<<"Case "<<(t+1)<<": ";
        solve(line);
    }
    return 0;
}
