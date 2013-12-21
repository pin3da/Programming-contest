using namespace std;
#include<bits/stdc++.h>
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define D(x) cout<< #x " = "<<(x)<<endl


int main(){ ___
    int n;
    while(cin>>n){
        vector<int> quedan;
        for(int i = 0; i < 2*n; ++i){
            double r;cin>>r;
            int t = round(r*1000);
            t%=1000;
            if(t!=0)quedan.push_back(t);
        }
        
        int ans = -(quedan.size()/2)*1000;
        sort(quedan.begin(),quedan.end());
        if(quedan.size()%2){
            for(int i = 1; i < quedan.size(); ++i)
                ans += quedan[i];
                
            if(quedan.size()%2)
                ans = min(ans + quedan[0],ans + 1000 - quedan[0]);
        }else{
            for(int i = 0; i< quedan.size(); ++i)
                ans += quedan[i];
        }

        double mio = ans/1000.0;
        printf("%.3lf\n",mio);
    }
    return 0;
}
