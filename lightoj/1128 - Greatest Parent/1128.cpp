using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MAXNODES 100010
#define LOGMAXN 20


int T[MAXNODES];
int S[MAXNODES];
int P[MAXNODES][LOGMAXN];
int L[MAXNODES];
int N;

void process3(){
    
    for (int i = 0; i < N; i++)
        for (int j = 0; (1 << j) < N; j++)
            P[i][j] = -1;

    for (int i = 0; i < N; i++)
        P[i][0] = T[i];

    for (int j = 1; 1 << j < N; j++)
        for (int i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
            
            
}

int query(int node, int value){
    int log, i;
    int ant = node;
    
    for (log = 1; (1 << log) <= L[node]; log++);
    log--;
    
    for (i = log; i >= 0; i--)
        if (P[node][i] != -1 and S[P[node][i]] >= value)
            node = P[node][i];

    return node;
}

int main(){ ___
    int t;cin>>t;
    for(int tid = 1; tid <= t; ++tid){
        int q;cin>>N>>q;
        L[0] = 0;
        S[0] = 1;
        for(int i = 1; i< N ; ++i){
            cin>>T[i]>>S[i];
            L[i] = L[T[i]] + 1;
        }
        
        process3();
        
        printf("Case %d:\n",tid);
                
        int k,v;
        for(int i = 0; i < q; ++i){
            cin>>k>>v;
            printf("%d\n",query(k,v));
        }    
    
    }
    
    return 0;

}

