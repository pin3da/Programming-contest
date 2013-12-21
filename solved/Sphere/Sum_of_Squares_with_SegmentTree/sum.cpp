using namespace std;
#include<iostream>
#include<vector>
#include<cmath>
#include<cassert>

typedef long long int ll;

struct Segment_tree{
    vector<ll> A;
    vector<ll> M;
    vector<ll> S;
    vector<ll> pending;
    vector<int> operation;
    
    Segment_tree(int n){
        A.resize(n);
        M.resize((n<<2)+4);
        S.resize((n<<2)+4);
        pending.resize((n<<2)+4);
        operation.resize((n<<2)+4);
    }
    
    void init(int node,int a,int b){
        if(a==b){
            M[node] = A[a];
            S[node] = A[a]*A[a];
        }else{
            init(node<<1, a,(a+b)>>1);
            init((node<<1)+1,((a+b)>>1)+1,b);
            M[node] = M[node<<1] + M[(node<<1)+1];
            S[node] = S[node<<1] + S[(node<<1)+1];
        }
        pending[node] = operation[node] = 0;
    }
    
    void propagate(int node,int a,int b){
        if(pending[node] == 0) return;
        if(operation[node] ==  1){ // add
            
            if(a!=b){
                if(operation[node<<1] == 2) propagate(node<<1,a,(a+b)>>1);
                if(operation[(node<<1)+1] == 2) propagate((node<<1)+1, ((a+b)>>1)+1 ,b);
            }
            
            S[node] += ((M[node]*pending[node])<<1 ) + (((ll)(b-a+1))*pending[node]);
            M[node] += ((ll)(b-a+1))*pending[node];
        
            if(a==b){
                pending[node] = 0;
                return;
            }
            pending[node<<1] += pending[node];
            pending[(node<<1)+1] += pending[node];
            pending[node] = 0;
            operation[node<<1] = operation[(node<<1)+1] = 1;
        }else{  //set
                  
            S[node] = ((b-a+1)*pending[node]*pending[node]);
            M[node] = (b-a+1)*pending[node];

            if(a==b){
                pending[node] = 0;
                return;
            }
            pending[node<<1] = pending[(node<<1)+1] = pending[node];
            pending[node] = 0;
            operation[node<<1] = operation[(node<<1)+1] = 2;
        }
    }
    
    void set_val(int node,int a,int b,ll value,int i,int j){
        propagate(node,a,b);
        if(a>j or b<i) return;
        if(a>= i and b <= j){
            S[node] = ((ll)(b-a+1))*value*value;
            M[node] = ((ll)(b-a+1))*value;
            if(a==b) return;
            pending[node<<1] = pending[(node<<1)+1] = value;
            operation[node<<1] = operation[(node<<1)+1] = 2;
            return;
        }
        set_val(node<<1,a, (a+b)>>1,value,i,j);
        set_val((node<<1)+1,((a+b)>>1)+1,b,value,i,j);
        M[node] = M[node<<1] + M[(node<<1)+1];
        S[node] = S[node<<1] + S[(node<<1)+1];
    }
    
    void add_val(int node,int a,int b,ll value,int i,int j){
        propagate(node,a,b);
        if(a>j or b<i) return;
        if(a>= i and b <= j){
            if(a!=b){
                if(operation[node<<1] == 2) propagate(node<<1,a,(a+b)>>1);
                if(operation[(node<<1)+1] == 2) propagate((node<<1)+1, ((a+b)>>1)+1 ,b);
            }
            S[node] += ((M[node]*value)<<1) + ((ll)(b-a+1))*value;
            M[node] += ((ll)(b-a+1))*value;
            if(a==b) return;
            pending[node<<1] += value;
            pending[(node<<1)+1] += value;
            operation[node<<1] = operation[(node<<1)+1] = 1;
            return;
        }
        add_val(node<<1,a, (a+b)>>1,value,i,j);
        add_val((node<<1)+1,((a+b)>>1)+1,b,value,i,j);
        M[node] = M[node<<1] + M[(node<<1)+1];
        S[node] = S[node<<1] + S[(node<<1)+1];
    }

    ll query(int node,int a,int b,int i,int j){
        propagate(node,a,b);
        if(a>j or b<i) return 0L;
        if(a>=i and b<=j)
            return S[node];
        return query(node<<1, a,(a+b)>>1,i,j) + query((node<<1)+1, ((a+b)>>1)+1,b,i,j);
    }

};

int main(){
    int T;cin>>T;
    for(int tid = 1;tid<=T;++tid){
        cout<<"Case "<<tid<<":"<<endl;
        int n,queries;
        cin>>n>>queries;
        Segment_tree tree(n);
        for(int i = 0;i <n;++i)
            cin>>tree.A[i];
            
            
        tree.init(1,0,n-1);
        int cont = 1;
        while(queries--){
            int op,a,b;
            ll c;
            cin>>op;
            if(op == 2){
                cin>>a>>b;
                cout<<tree.query(1,0,n-1,a-1,b-1)<<endl;
                cont++;
            }else if(op == 1){
                cin>>a>>b>>c;
                tree.add_val(1,0,n-1,c,a-1,b-1);
            }else{
                cin>>a>>b>>c;
                tree.set_val(1,0,n-1,c,a-1,b-1);
            }
        }
    }
    return 0;
}

