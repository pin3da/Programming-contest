using namespace std;
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>


struct segment_tree{
    vector<int> M;
    vector<int> A;
    segment_tree(int n){
        M.resize((n<<2)+4);
        A.resize(n);
    }

    void initialize(int node, int b, int e){
        if (b == e)
            M[node] = b;
        else{
            initialize(node<<1, b, (b + e)>>1);
            initialize((node<<1) + 1, ((b + e)>>1) + 1, e);
            if (A[M[node<<1]] <= A[M[(node<<1) + 1]])
                M[node] = M[node<<1];
            else
                M[node] = M[(node<<1) + 1]; 
        }
    } 
    
    int query(int node,int b,int e,int i,int j){
        if(i>e or j<b)
            return -1;
        if (b >= i && e <= j)
            return M[node];

        int p1 = query(node<<1, b, (b + e)>>1, i, j);
        int p2 = query((node<<1) + 1, ((b + e)>>1) + 1, e, i, j);

        if (p1 == -1)
            return p2;
        if (p2 == -1)
            return p1;
        if (A[p1] <= A[p2])
            return p1;
        return p2;
    }
};


int main(){
    int tc;cin>>tc;
    for(int id = 1;id<=tc;++id){
        int n,q;
        scanf("%d%d",&n,&q);
        segment_tree tree(n);
        for(int i=0;i<n;++i)
            scanf("%d",&tree.A[i]);
            
        tree.initialize(1,0,n-1);
        
        int i,j;
        printf("Case %d:\n",id);
        for(int k=0;k<q;++k){
            scanf("%d%d",&i,&j);
            printf("%d\n",tree.A[tree.query(1,0,n-1,i-1,j-1)]);
        }
    
    
    }

    return 0;
}

