using namespace std;
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#define foreach(x,c) for(typeof((c).begin()) x = (c).begin() ; x!= (c).end(); ++x)
#define D(x) cout<< #x " = "<<(x)<<endl

typedef long long int lint;

int main(){
    int t,n;cin>>t;
    map<lint,lint>::iterator m;
    while(t--){
        cin>>n;
        vector<map<lint,lint> > nums(n);
        int tam,tmp;
        for(int i=0 ;i<n;++i){
            cin>>tam;
            for(int j=0;j<tam;++j){
                cin>>tmp;
                nums[i][tmp];
            }
        }
        
        foreach(it,nums[0])
            nums[0][it->first] = (1LL<<60) ;
        
        int pin = 1;
        for(int i=n-2;i>=0;--i){
            foreach(it,nums[i]){
                m = nums[i+1].lower_bound(it->first);
                if(m == nums[i+1].end()){
                    if(it == nums[i].begin())pin=0;
                    break;
                }
                nums[i][it->first] = m->first - it->first + m->second;
            }
        }
        lint ans = (1LL<<60);
        foreach(it,nums[0])
            ans = min(ans,it->second);
        cout<<((pin)?ans:-1)<<endl;
    }
    return 0;
}


