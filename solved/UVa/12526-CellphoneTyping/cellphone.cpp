using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<cstdio>
#define D(x)  cout<< #x " = "<<(x)<<endl
 
const int MAXS = 10000005; // Max number of states
 
struct Trie {
    int g[MAXS][27];
    int stateCount;
    
    Trie() {
        clear();
    }
    
    void clear() {
        memset(g[0], -1, sizeof g[0]);
        stateCount = 1;
    }
    
    void add(const char * s) {
        int state = 0; // root
        for (; *s; s++) {
            int next = (*s == '$')? 26 : (*s - 'a');
            if (g[state][next] == -1) { // Add new state
                g[state][next] = stateCount;
                memset(g[stateCount], -1, sizeof g[stateCount]);
                stateCount++;
            }
            state = g[state][next];
        }
    }
        
    int count_keys(const char *s){
        int state = 0;
        int ans = 0;
        for(; *s; ++s){
            int cuenta = 0;
            if(*(s+1)) // is not $
                for(int k = 0 ; k < 27 ; ++k)
                    if(g[state][k] != -1) cuenta++;
            if(cuenta > 1 or (cuenta==1 and state == 0)) ans++;
            int next = (*s == '$')? 26 : (*s - 'a');
            state = g[state][next];
        }
        return ans;
    }
};


int main(){
    int n;
    static Trie tree;
    while(cin>>n){
        vector<string> words(n);
        tree.clear();
        for(int i = 0; i< n; ++i ){
            cin>>words[i];
            words[i]+="$";
            tree.add(words[i].c_str());
        }
        double ans = 0;
        for(int i = 0 ; i < n; ++i){
            ans += tree.count_keys(words[i].c_str());
        }
        //cout<<(ans/(double)n)<<endl;
        printf("%.2lf\n",(ans/(double)n));
    }
    return 0;
}
