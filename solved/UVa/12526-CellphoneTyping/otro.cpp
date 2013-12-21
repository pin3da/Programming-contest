using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
 
const int MAXS = 1000005; // Max number of states
 
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
    
    void add(char * s) {
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
    
    void add(const string &s) {
        add(s.c_str());
    }
    
    int count_keys(char *s){
        int state = 0;
        int ans = 0;
        for(; *s; ++s){
            for(int k = 0 ; k < 27 ; ++k)
                if(g[state][k] != -1) ans++;
            int next = (*s - 'a');
            state = g[state][next];
        }
    }
    int count_keys(const string &s){
        return count_keys(s.c_str());
    }
};


int main(){
    /*
    int n;
    while(cin>>n){
        cout<<n<<endl;
        vector<string> words(n);
        Trie tree;
        for(int i = 0; i< n; ++i ){
            cin>>words[i];
            words[i]+="$";
            cout<<words[i]<<endl;
            tree.add(words[i]);
        }
        cout<<"lee"<<endl;
        double ans = 0;
        for(int i = 0 ; i < n; ++i)
            ans += tree.count_keys(words[i]);
        cout<<(ans/(double)n)<<endl;
    }
    return 0;*/
}

