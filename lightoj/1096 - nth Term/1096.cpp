using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define matrix vector<vector<int> >
#define MP 4
#define new_matrix vector<vector<int> >(MP,vector<int>(MP,0))

void _print(matrix m){
    for(int i = 0 ; i< MP ; ++i){
        for(int j = 0; j< MP; ++j){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

const int MOD = 10007;

matrix multiply(const matrix &a,const matrix &b){
    matrix answer = new_matrix;
    for(int i = 0 ; i < MP ; ++i){
        for(int j = 0; j < MP; ++j){
            answer[i][j] = 0;
            for(int k = 0; k < MP; ++k){
                answer[i][j] += (a[i][k]*b[k][j])%MOD;
                answer[i][j] %= MOD;
            }
        }
    }
    return answer;
}

matrix mod_pow(matrix m, int n){
    matrix answer = new_matrix;
    for(int i = 0; i< MP; ++i)
        for(int j = 0; j < MP; ++j)
            if(i==j) answer[i][j] = 1;
            
    for(int i = n; i > 0; i>>=1){
        if(i&1)
            answer = multiply(answer,m);

        m = multiply(m,m);
    }
    
    return answer;
}


int main(){ ___
    int tc;cin>>tc;
    for(int tid = 1; tid <= tc ; ++tid){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
                
        int ans = 0;
        if(n > 2){
            matrix mat =  new_matrix;
            mat[0][0] = a;
            mat[0][2] = b;
            mat[0][3] = 1;
            mat[1][0] = 1;
            mat[2][1] = 1;
            mat[3][3] = 1;
            
            matrix answer = mod_pow(mat,n-2);
            
            ans = answer[0][3]*c;
            ans %= MOD;
            
        }
        printf("Case %d: %d\n",tid,ans);
    }

    return 0;
}
