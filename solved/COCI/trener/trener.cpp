using namespace std;
#include<bits/stdc++.h>

int ans[27];

int main(){
    int n;cin>>n;
    
    for(int i = 0; i <n; ++i){
        string name;cin>>name;
        ans[name[0]- 'a']++;
    }
    
    string mio;
    for(int i = 0; i< 27; ++i){
        if(ans[i]>=5)mio+=(i+'a');
    }
    if(mio == "")cout<<"PREDAJA"<<endl;
    else cout<<mio<<endl;

    return 0;
}
