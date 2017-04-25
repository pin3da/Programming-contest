// http://codeforces.com/contest/132/problem/A

using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<<#x " = "<<(x)<<endl
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);


int reverse(int a){
    int ans = 0;
    for(int i = 7; i>=0; --i){
        if((a>>i)&1)
            ans |= 1<<(7-i);
    }
    return ans;
}


int main(){ ___
    string cad;
    while(getline(cin,cad)){
        int ant = 0;
        
        for(int i = 0 ; i< cad.size() ; ++i){
            int act = reverse(cad[i]);
            int ans = ((ant - act)+256)%256;
            cout<<ans<<endl;
            ant = reverse(cad[i]);
        }
    }
    return 0;
}
            
                