using namespace std;
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#define For(i,n) for(int i=0;i<(n);++i)

vector<int> colors;
int total;

double dp[1<<16];

double solve(int state,int turnos = 0){
    if(dp[state]!= -1) return dp[state];
    double ans = 0.0;
    For(i,colors.size()){
        if(state & 1<<i){
            ans+= ((colors[i]-1)/(double)(total - __builtin_popcount(state)))* (turnos +1);
        }else{
            ans+= (colors[i]/(double)(total - __builtin_popcount(state)))*solve(state | (1<<i),turnos +1);
        }
    }
    return dp[state] = ans;
}

int main(){
    int numc;cin>>numc;
    For(tid,numc){
        int k;cin>>k;
        colors = vector<int>(k);
        total = 0;
        For(i,k){
            cin>>colors[i];
            total += colors[i];
        }
        For(i,1<<16)dp[i]=-1;
        //cout<<"Caso "<<(tid+1)<<": "<<solve(0)<<endl;
        printf("Caso %d: %.3lf\n",(tid+1),solve(0));

    }


    return 0;
}
