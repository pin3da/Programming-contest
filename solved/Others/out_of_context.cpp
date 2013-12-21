/** Out of context **
* Manuel Pineda     *
* c++               *
* 01 / 2013         *
* Accepted          *
*********************/

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<iterator>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>

#include<cctype>
#include<cstring>

#define foreach(it,x) for(typeof (x.begin()) it = (x).begin(); it!= (x).end(); ++it)
#define for_range(it,x,v ) for(typeof ((v).equal_range(x).first) it = (v).equal_range(x).first; it != (v).equal_range(x).second; ++it)
#define D(x) cout<< #x " = "<<(x)<<endl

template <class T> int toInt(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
template <class T> string toStr(const T &x){stringstream s; s<<x;return s.str();}


struct symbol{
    string name;
    int terminal; // true if is terminal
    
    symbol(){}
    symbol(string Name,int ter): name(Name), terminal(ter){}
    
    bool operator < (const symbol &other) const {
        return name < other.name;
    }
    
    bool operator != (const symbol &other) const {
        return name != other.name;
    }
    bool operator == (const symbol &other) const {
        return name == other.name;
    }
};

typedef pair<symbol,vector<symbol> > production;

bool isUnitary(production p){
    return p.second.size() == 1 and !p.second[0].terminal;
}

bool is_not_Unitary_valid(production p){
    if(p.second.size()==1 and p.second[0].name=="0") return 0;
    return !isUnitary(p);
}

/**
*   parser, divide the terminal and no-terminal symbols
*   input: 'S -> "aaaSba" '
*   outpout: 'S -> "aaa","S","ba" '
*/

production parse_prod(string input){
    stringstream buffer(input);
    string lhs,arrow, right;
    buffer>>lhs>>arrow>>right;
    
    vector<symbol> rhs;
    
    if(right.size()==0) rhs.push_back(symbol("0",true)); // represents lambda/epsilon

    string sym = "";
    string tt = "";
    for(int i=0;i<right.size();++i){
        if(isupper(right[i])){
            if(sym.size()>0) rhs.push_back(symbol(sym,true));
            rhs.push_back(symbol(tt+right[i],false));
            sym="";
        }else{
            sym+=right[i];
        }
    }
    
    if(sym.size()>0)rhs.push_back(symbol(sym,true));
    
    return make_pair(symbol(lhs,false),rhs);
}

/**
*   Represents Context Free Grammar
*    * reverse_prod[symbol] contains productions in wich symbol are used.
*/

struct cfg {
    multimap<symbol, vector<symbol> > productions;
    map<symbol, set<symbol> > reverse_prod;
    set<symbol> no_terminals;
    set<symbol> terminals;
    
    symbol start_symb;
    
    cfg(){}
    
    cfg(symbol S): start_symb(S) {}

    void insert(symbol lhs, vector<symbol> rhs) { //left hand side, right hand side
        productions.insert(make_pair(lhs,rhs));
    }
    
    void gen_symbols(){
        no_terminals.clear();
        terminals.clear();
        foreach(sym,productions){
            no_terminals.insert(sym->first);
            foreach(right,sym->second){
                if(right->terminal){
                    terminals.insert(*right);
                }
            }
        }
    }
    
    void gen_inverse(){
        foreach(pro,productions){
            foreach(sym,pro->second){
                reverse_prod[(*sym)].insert(pro->first);
            }
        }
    }
    
    /*remove the nonterminals symbols which not generate strings of terminals*/
    void remove_no_gen_terminals(){
        set<production> N_p;
        set<symbol> N_t;
        foreach(pro,productions){
            if(pro->second.size()==1 and pro->second[0].name!="0" and pro->second[0].terminal){
                N_p.insert(*pro);
                N_t.insert(pro->first);
            }
        }
        
        size_t ant=0;
        while(ant != N_t.size()){
            ant = N_t.size();
            foreach(A,productions){
                bool check = true;
                foreach(w,A->second){
                    if(!w->terminal){
                        if(N_t.find(*w)==N_t.end()){
                            check = false;
                            break;
                        }
                    }
                }
                if(check){
                    N_t.insert(A->first);
                    N_p.insert(*A);
                }
            }
        }
        
        multimap<symbol, vector<symbol> > delta_p(N_p.begin(),N_p.end());        
        productions = delta_p;
        gen_symbols();
    }
    
    
    /**
    *   Manuel Pineda's versions,
    */
    void remove_useless_productions(){ // named unreachable rules too
        //remove_no_gen_terminals();
        
        //remove unreachable symbols bellow
        multimap<symbol, vector<symbol> > delta_p;
        
        queue<symbol> Q;
        Q.push(start_symb);
        map<symbol,int> visited;
        
        while(!Q.empty()){
            symbol actual = Q.front();Q.pop();
            if(visited[actual])continue;
            visited[actual]=true;
            
            for_range(pro, actual, productions){
                delta_p.insert((*pro));
                foreach(sym,pro->second){
                    if(!visited[(*sym)] and !sym->terminal){
                        Q.push((*sym));
                        
                    }
                }
            }
        }
        
        productions = delta_p;
    }
    
    /**
    *   Pinocho's version
    */
    
    void remove_useless_productions1(){
        remove_no_gen_terminals();
        
        //remove unreachable symbols bellow
    
        size_t ant = 0;
        set<symbol> No_terminals;
        set<production> p_prim;
        No_terminals.insert(start_symb);
        while(ant != No_terminals.size()){
            ant = No_terminals.size();
            foreach(sym,No_terminals){
                for_range(pro,(*sym),productions){
                    p_prim.insert((*pro));
                    foreach(S, pro->second){
                        if(!S->terminal)
                        No_terminals.insert((*S));
                    }
                }
            }
        }
        multimap<symbol, vector<symbol> > delta_p(p_prim.begin(),p_prim.end());        
        productions = delta_p;
    }
    
    vector<production> combinations(production &P,symbol &rhs){
        int total=0;
        foreach(right,P.second)
            if(rhs.name == right->name)
                total++;
        
        int top = 1<<total;
        vector<production> n_productions;
        
        for(int i=0;i<top;++i){     //represents a set
            production n_pro;
            n_pro.first=P.first;
            int act = 0;            //actual position
            foreach(symb,P.second){
                if(symb->name == rhs.name){
                    if(i & (1<<act)){
                        n_pro.second.push_back(*symb);
                    }
                    act++;
                }else{
                    n_pro.second.push_back(*symb);
                }
            }
            n_productions.push_back(n_pro);
        }
        
        return n_productions;
    }
    
    
    void remove_lambda_productions(){
        //1. Pick a lambda production
        bool check = false;
        production lambda;
        foreach(pro,productions){
            if(pro->second.size()==1 and pro->second[0].name=="0"){
                lambda = (*pro);
                //2. Remove that lambda production
                productions.erase(pro);
                check = true;
                break;
            }
        }
        if(!check) return;
        
        symbol rhs = lambda.first;
        
        vector<production> to_extend;
        foreach(prod,productions)
            foreach(R,prod->second)
                if((*R)==rhs)
                    to_extend.push_back(*prod);
             
        
        set<production> new_productions(productions.begin(),productions.end());
        foreach(prod, to_extend){
            vector<production> to_add = combinations(*prod,rhs);
            foreach(P,to_add)
                new_productions.insert(*P);
        }
        
        multimap<symbol, vector<symbol> > delta_p(new_productions.begin(),new_productions.end());
        productions = delta_p;

        remove_lambda_productions(); // the algorithm run until not changes
    
    }
    
    set<symbol> unitary_set(symbol A){
        set<symbol>  unitary;
        unitary.insert(A);
        
        queue<symbol> Q;
        Q.push(A);
        map<symbol,int> visited;
        size_t ant = 0;
        while(ant != unitary.size()){
            ant = unitary.size();
            foreach(actual,unitary){
                for_range(pro,(*actual), productions){
                    if(isUnitary(*pro)){
                        unitary.insert(pro->second[0]);
                    }
                }
            }
        }
        return unitary;       
       
    }
    
    void remove_unitary_productions(){
        set<production > p_prim(productions.begin(),productions.end());
        gen_symbols();
        
        foreach(A ,no_terminals){
            set<symbol> unitary = unitary_set((*A));
            if(unitary.size()==1)continue;
            foreach(B,unitary){
                for_range(prod,(*B),productions){
                    if(is_not_Unitary_valid(*prod)){
                        p_prim.insert(make_pair((*A),prod->second));
                    }
                }
            }
        }
        
        foreach(pro,p_prim){
            if(isUnitary(*pro)){
                p_prim.erase(pro);
                pro--;
            }
        }
        
        multimap<symbol, vector<symbol> > tmp(p_prim.begin(),p_prim.end());
        productions = tmp;
        
    }
    
    void simplify(){
        remove_lambda_productions();
        remove_unitary_productions();
        remove_useless_productions();
    }
    
    
    void cnf_terminals(){
        map<symbol,symbol> encode;
        set<production> tmp;
        foreach(T,terminals){
            encode[(*T)]=symbol("CNF"+T->name,false);
			vector<symbol> rhs;
			rhs.push_back((*T));
			tmp.insert(make_pair(encode[(*T)],rhs));
        }
        
        foreach(pro,productions){
            if(pro->second.size() == 1) continue;
            for(int i=0;i<pro->second.size();++i){
                if(pro->second[i].terminal){
                    pro->second[i] = encode[pro->second[i]];
                }
            }
        }
        
        foreach(P,tmp)
            insert(P->first,P->second);
        
    }
    
    void cnf_nonterminals(int index=0){
        foreach(pro,productions){
            if(pro->second.size()>2){
                index++;
                vector<symbol> tmp2 = pro->second;
                pro->second.clear();
                pro->second.push_back(tmp2[0]);
                pro->second.push_back(symbol("CNF"+toStr(index),false));
                tmp2.erase(tmp2.begin());
                insert(symbol("CNF"+toStr(index),false),tmp2);
                cnf_nonterminals(index);
            }
        }
    }
    
    void to_CNF(){
        simplify();
        gen_symbols();
        cnf_terminals();
        cnf_nonterminals();
        gen_symbols();
        gen_inverse();
    }
};

void debug_grammar(cfg &grammar){
    foreach(sym,grammar.productions){
        cout<< sym->first.name<<" -> ";
        foreach (m, sym->second )
            cout<<m->name<<" , ";
        cout<<endl;
    }
}

void debug_unitary_set(cfg &grammar){
    grammar.gen_symbols();
    set<symbol> U;
    foreach(S,grammar.no_terminals){
        U = grammar.unitary_set((*S));
        cout<<"**** Unitary set of ("<<S->name<<") ****"<<endl;
        foreach(sym,U)
            cout<<sym->name<<" "<<endl;
    }
}

/****
* CYK algorithm, return the longest substring that could have been generated by a given grammar in CNF
*                if no string matches, return "NONE"
*/

string CYK(cfg &grammar,string &query){
    int n = query.size();
	int r = grammar.no_terminals.size();
	int P[n][n+1][r];
	memset(P,0,sizeof(P));
	
	foreach(pro,grammar.productions){
		int pos = 0;
		while (pro->second.size() == 1 && pos < query.size() && (pos = query.find(pro->second[0].name, pos)) != -1){
		    int diff = distance(grammar.no_terminals.begin(), grammar.no_terminals.find(pro->first));
			P[pos++][1][diff] = true;
		}
	}

	for (int i = 2; i < n + 1; i++)
		for (int j = 0; j < n - i + 1; j++)
			for (int k = 0; k < i; k++)
			    foreach(pro,grammar.productions)
					if (pro->second.size() > 1) {
					    int A = distance(grammar.no_terminals.begin(), grammar.no_terminals.find(pro->first));
						int B = distance(grammar.no_terminals.begin(), grammar.no_terminals.find(pro->second[0]));
						int C = distance(grammar.no_terminals.begin(), grammar.no_terminals.find(pro->second[1]));
						P[j][i][A] = (P[j][k][B] && P[j + k][i - k][C]) ? true : P[j][i][A];
					}
					
	string ans = "";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n + 1; j++)
			if (P[i][j][distance(grammar.no_terminals.begin(), grammar.no_terminals.find(grammar.start_symb))] && i + j <= n && j > ans.size())
				ans = query.substr(i,j);
				
    return ((ans.size() == 0 ? "NONE" : ans));
}

int main(){
    /**
    * The input is in the follow format:
    *   a single line with a integer num_rules, indicates the number of productions
    *   the following num_rules lines contains a string in the format
    *   [A-Z] -> [A-Za-z]*
    */

    int n_rules;
    string tmp;
    getline(cin,tmp);
    n_rules = toInt(tmp);
    production actual;
    
    cfg grammar;  
    for(int i=0;i<n_rules;++i){
        getline(cin,tmp);
        actual = parse_prod(tmp);
        if(i==0)grammar.start_symb = actual.first;
        grammar.insert(actual.first,actual.second);
    }

    grammar.remove_lambda_productions();
    grammar.to_CNF();
   
    string query;
    while(getline(cin,query)){
    	cout<<CYK(grammar,query)<<endl;
    }
    
    /*********************************************
    * Test Code and algorithms                   *
    * Start Test                                 *
    * Tested with examples of pinocho's book     *
    **********************************************/
        /**
        debug_grammar(grammar);
        grammar.remove_lambda_productions();
        cout<<"******** Grammar without lambda productions ******** "<<endl;       
        debug_grammar(grammar);
        
        grammar.remove_unitary_productions();
        cout<<"******** Grammar without unitary productions ******** "<<endl;
        debug_grammar(grammar);
        
        //grammar.remove_useless_productions();
        grammar.remove_useless_productions1();
        cout<<"******** Grammar without useless productions ******** "<<endl;
        debug_grammar(grammar);
        debug_unitary_set(grammar);
        cout<<"Gramar"<<endl;
        debug_grammar(grammar);
        grammar.remove_lambda_productions();
        cout<<"lambda"<<endl;
        debug_grammar(grammar);
        grammar.remove_unitary_productions();
        cout<<"unitary"<<endl;
        debug_grammar(grammar);
        grammar.remove_useless_productions();
        cout<<"useless"<<endl;
        debug_grammar(grammar);*/
        //grammar.to_CNF();
        //cout<<"******** Grammar in CNF ******** "<<endl;       
        //debug_grammar(grammar);
        //string S;cin>>S;
        //cout<<CYK(grammar,S)<<endl;      

    /********* End Test *******/    

    return 0;
}

