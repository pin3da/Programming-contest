using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define MP 100010


int main (){ ___
    
    int n;
    while(cin>>n){
        vector<int> frec(10,0);
        int tmp;
        while(n--){
            cin>>tmp;
            frec[tmp]++;
        }
        
        if(frec[0]==0){
            cout<<-1<<endl;
            continue;
        }
        for(int i = 9; i >=1; --i){
            int veces = (frec[i]/3)*3;
            for(int j = 0; j < veces;++j)
                cout<<i;
        }
        if(frec[2]==0 and frec[1]==0){
            for(int i =0 ; i < (frec[3]%3); ++i)
                cout<<3;
        }

        for(int i =0 ; i < frec[0]; ++i){
            cout<<0;
        }
        cout<<endl;
        
    }
    return 0;
}
