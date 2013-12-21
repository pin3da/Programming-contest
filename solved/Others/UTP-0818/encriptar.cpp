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

    
    if(m == 1){
        for(int i = 0; i< n; ++i)
            cout<<(message[i]+key[0])%c<<" ";
    
        cout<<endl;
        return 0;    
    }

    int iz = 0;
    int der = 0;
    int j = 0;
    int tope = (((n%2)==0) ? n/2: (n/2)+1 );

    int f = 1;
    for(int i = 0; i< tope; ++i){
        if(f){
            iz += key[j];
            iz %= c;
            der += key[m-j-1];
            der %= c;
        }
        if(j==m-1)f=0;
        message[i] += iz;
        message[i] %= c;

        if(i == n-i-1) break;
        message[n-i-1] += der;
        message[n-i-1] %= c;
        
        if(j < m -1) j++;
    }
    
    for(int i = 0; i< n; ++i)
        cout<<message[i]<<" ";
    
    cout<<endl;
    
    return 0;
}


