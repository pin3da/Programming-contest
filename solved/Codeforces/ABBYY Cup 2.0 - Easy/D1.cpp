// http://codeforces.com/contest/177/problem/D1

using namespace std;
#include<bits/stdc++.h>
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl
#define MP 11


int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){ ___
   
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> message(n);
    vector<int> key(m);
    for(int i = 0; i <n; ++i)
        cin>>message[i];
    

    for(int i = 0; i <m; ++i)
        cin>>key[i];

    for(int i = 0; i< n-m+1; ++i){
        for(int j = 0; j < m; ++j){
            message[i+j] =  (message[i+j] + key[j]) %c;
        }
    }     
       
    for(int i = 0 ;i < n; ++i)
        cout<<message[i]<<" ";
    cout<<endl;
    
}