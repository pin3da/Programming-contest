using namespace std;
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#define D(x) cout<< #x " = "<<(x)<<endl

typedef long long int ll;

struct node{
    ll M, prefix, suffix, best;

    node(ll a,ll b,ll c,ll d): M(a), prefix(b),suffix(c),best(d){}
    node(){
        M = prefix = suffix = best = (1<<30);
    }
    
    bool is_null(){
        return M == prefix and prefix==suffix and suffix == best and best == (1<<30);
    }
    
};

struct segment_tree{
    vector<node> tree;
    vector<int> A;
    segment_tree(int n){
        tree.resize((n<<2)+4);
        A.resize(n);
    }
    
    node join(node a,node b){
        return node(a.M + b.M, max(a.prefix, a.M + b.prefix) , max(b.suffix, b.M + a.suffix ) , max(max(a.best,b.best),a.suffix+b.prefix));
    }
    
    void initialize(int _node, int b, int e){
        if (b == e){
              tree[_node] = node(A[b],A[b],A[b],A[b]);
        }else{
            initialize(_node<<1, b, (b + e)>>1);
            initialize((_node<<1) + 1, ((b + e)>>1) + 1, e);
            tree[_node] = join(tree[_node<<1],tree[(_node<<1)+1]);
        }
    } 
    
    node query(int _node,int b,int e,int i,int j){
        if(i>e or j<b)
            return node();
        if (b >= i && e <= j)
            return tree[_node];

        node p1 = query(_node<<1, b, (b + e)>>1, i, j);
        node p2 = query((_node<<1) + 1, ((b + e)>>1) + 1, e, i, j);

        if (p1.is_null()){
            return p2;
        }if (p2.is_null()){
            return p1;
        }
        
        return join(p1,p2);
    }
};


int main(){
    int n;
    scanf("%d",&n);
    segment_tree tree(n);
    for(int i=0;i<n;++i)
        scanf("%d",&tree.A[i]);
   
    tree.initialize(1,0,n-1);

    int q,i,j;
    scanf("%d",&q);
    for(int k=0;k<q;++k){
        scanf("%d%d",&i,&j);
        printf("%d\n",(int)tree.query(1,0,n-1,i-1,j-1).best);
    }

    return 0;
}


