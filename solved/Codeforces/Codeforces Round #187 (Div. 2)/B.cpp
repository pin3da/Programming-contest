// http://codeforces.com/contest/315/problem/B

using namespace std;
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>

#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cctype>

#define For(i,a) for(int i=0;i<a;++i)
#define foreach(x,v) for(typeof (v).begin() x = (v).begin(); x!= (v).end(); x++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define Dbg if(1)
#define MAXNODES 100

template <class T> string to_str(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> int to_int(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

const double pi=acos(-1);
const double Pi2=acos(0);
typedef long long ll;
typedef pair<int , int> pii;
typedef vector<int> vi;

typedef long long int ll;

struct Segment_tree{
    vector<ll> A;
    vector<ll> M;
    vector<ll> pending;
    vector<int> operation;
    
    Segment_tree(int n){
        A.resize(n);
        M.resize((n<<2)+4);
        pending.resize((n<<2)+4);
        operation.resize((n<<2)+4);
    }
    
    void init(int node,int a,int b){
        if(a==b){
            M[node] = A[a];
        }else{
            init(node<<1, a,(a+b)>>1);
            init((node<<1)+1,((a+b)>>1)+1,b);
            M[node] = M[node<<1] + M[(node<<1)+1];
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
            M[node] = ((ll)(b-a+1))*value;
            if(a==b) return;
            pending[node<<1] = pending[(node<<1)+1] = value;
            operation[node<<1] = operation[(node<<1)+1] = 2;
            return;
        }
        set_val(node<<1,a, (a+b)>>1,value,i,j);
        set_val((node<<1)+1,((a+b)>>1)+1,b,value,i,j);
        M[node] = M[node<<1] + M[(node<<1)+1];
    }
    
    void add_val(int node,int a,int b,ll value,int i,int j){
        propagate(node,a,b);
        if(a>j or b<i) return;
        if(a>= i and b <= j){
            if(a!=b){
                if(operation[node<<1] == 2) propagate(node<<1,a,(a+b)>>1);
                if(operation[(node<<1)+1] == 2) propagate((node<<1)+1, ((a+b)>>1)+1 ,b);
            }
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
    }

    ll query(int node,int a,int b,int i,int j){
        propagate(node,a,b);
        if(a>j or b<i) return 0L;
        if(a>=i and b<=j)
            return M[node];
        return query(node<<1, a,(a+b)>>1,i,j) + query((node<<1)+1, ((a+b)>>1)+1,b,i,j);
    }

};

int main(){
    int n;cin>>n;
    int m;cin>>m;
    Segment_tree tree(n);

    For(i,n)
        cin>>tree.A[i];
    
    tree.init(1,0,n-1);
    int a,b,c;
    For(i,m){
        cin>>a;
        if(a==1){
            cin>>b>>c;
            tree.set_val(1,0,n-1,c,b-1,b-1);
        }else if(a==2){
            cin>>b;
            tree.add_val(1,0,n-1,b,0,n-1);
        }else{
            cin>>b;
            cout<<tree.query(1,0,n-1,b-1,b-1)<<endl;
        }
    }
    
    return 0; 
}