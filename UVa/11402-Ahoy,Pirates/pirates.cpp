using namespace std;
#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>
#include<cstdio>
#define D(x) cout<< #x " = "<<(x)<<endl

typedef unsigned int u32;

struct Reader {
    char b; Reader() { read(); }
    void read() { int r = fgetc_unlocked(stdin); b = r == EOF ? 0 : r; }
    void skip() { while (b > 0 && b <= 32) read(); }
    u32 next_u32() {
        u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
    void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }
    char next_char() { skip(); char c = b; read(); return c; }
};


struct Segmet_tree{
    vector<int> M;
    vector<int> pending;
    
    Segmet_tree(int m){
        M.resize((m<<2)+4);
        pending.resize((m<<2)+4);
    }
    
    void init(vector<int> &data,int node, int a,int b){
        pending[node] = 0;
        if(a==b){
            M[node] = data[a];
        }else{
            init(data,node<<1,a,(a+b)>>1);
            init(data,(node<<1)+1, ((a+b)>>1)+1 ,b);
            M[node] = M[node<<1] + M[(node<<1)+1];
        }
    }
    
    void propagate(int node,int a,int b){
        if(pending[node] == 0) return;
        if(pending[node] == 1){
            M[node] = (b-a+1);
            if(a!=b)
                pending[node<<1] = pending[(node<<1)+1] = 1;
         
        }else if (pending[node] == 2){
            M[node] = 0;
            if(a!=b)
                pending[node<<1] = pending[(node<<1)+1] = 2;
            
        }else{
            M[node] =  (b-a+1) - M[node];
            assert((b-a+1) >= M[node]);
            if(a!=b){
                if(pending[node<<1] != 0) pending[node<<1] = (pending[node<<1] != 3)? (pending[node<<1] == 2)? 1:2: 0 ;
                else pending[node<<1] = 3;
                if(pending[(node<<1)+1]!=0) pending[(node<<1)+1] = (pending[(node<<1)+1] != 3)? (pending[(node<<1)+1] == 2)? 1:2: 0;
                else pending[(node<<1)+1] = 3;    
            }
        }
        pending[node] = 0;
    }
    
    void set_bits(int node, int a,int b, int i,int j){
        propagate(node,a,b);
        if(a> j or b <i ) return;
        if(a >= i and b <= j){
            M[node] = (b-a+1);
            assert((b-a+1) > 0);
            if(a!=b)
                pending[node<<1] = pending[(node<<1)+1] = 1;
        }else{
            set_bits(node<<1, a, (a+b)>>1 ,i,j);
            set_bits((node<<1)+1 , ((a+b)>>1)+1, b, i,j);
            M[node] = M[node<<1] + M[(node<<1)+1];
        }
    }
    
   void clear_bits(int node, int a,int b, int i,int j){
        propagate(node,a,b);
        if(a> j or b <i ) return;
        if(a >= i and b <= j){
            M[node] = 0;
            if(a!=b)
                pending[node<<1] = pending[(node<<1)+1] = 2;
        }else{
            clear_bits(node<<1, a, (a+b)>>1 ,i,j);
            clear_bits((node<<1)+1 , ((a+b)>>1)+1, b, i,j);
            M[node] = M[node<<1] + M[(node<<1)+1];
        }
    }
    
    void flip(int node, int a,int b, int i,int j){
        propagate(node,a,b);
        if(a> j or b <i ) return;
        if(a >= i and b <= j){
            M[node] =  (b-a+1) - M[node];
            assert((b-a+1) >= M[node]);
            if(a!=b){
                if(pending[node<<1]!=0) pending[node<<1] = ( (pending[node<<1] != 3)? (pending[node<<1] == 2)? 1:2: 0 );
                else pending[node<<1] = 3;
                if(pending[(node<<1)+1]!=0) pending[(node<<1)+1] = ( (pending[(node<<1)+1] != 3)? (pending[(node<<1)+1] == 2)? 1:2: 0 );
                else pending[(node<<1)+1] = 3;
            }
        }else{
            flip(node<<1, a, (a+b)>>1 ,i,j);
            flip((node<<1)+1 , ((a+b)>>1)+1, b, i,j);
            M[node] = M[node<<1] + M[(node<<1)+1];
        }
    }
    
    int query(int node,int a,int b,int i,int j){
        propagate(node,a,b);
        if(a>j or b < i) return 0;
        if(a>=i and b<= j)
            return M[node];
        else
            return query(node<<1, a, (a+b)>>1 ,i,j) + query((node<<1)+1 , ((a+b)>>1)+1, b, i,j);
    }
    
};

char str[100];
Segmet_tree tree(1024000);

int main(){

    Reader sc;
    int TC = sc.next_u32();
    for(int tid = 1; tid <= TC ;++tid){
        int M = sc.next_u32();
        vector<int> data;
        while(M--){
            int T = sc.next_u32();
            sc.next(str);
            while(T--)
                for(int i =0;str[i];++i)
                    data.push_back(str[i]=='1');
        }
        
        int m = data.size();
        tree.init(data, 1,0,m-1);

        int queries = sc.next_u32();
        int qid=1;
        printf("Case %d:\n",tid);
//        cout<<"Case "<<tid<<":"<<endl;
        while(queries--){
            char op = sc.next_char();
            int a = sc.next_u32();
            int b = sc.next_u32();
            if(op=='F')
                tree.set_bits(1,0,m-1,a,b);
            else if( op == 'E')
                tree.clear_bits(1,0,m-1,a,b);
            else if(op == 'I')
                tree.flip(1,0,m-1,a,b);
            else
                printf("Q%d: %d\n",qid++,tree.query(1,0,m-1,a,b));
//                cout<<"Q"<<qid++<<": "<<tree.query(1,0,m-1,a,b)<<endl;
            
            
        }
    
    }
    return 0;
}

