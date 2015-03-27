using namespace std;
#include<bits/stdc++.h>
 
 
int main(){
    int num; cin>>num;
    
    int mmax = num/7;
   // cout<<mmax<<endl;
    for(int i = mmax; i >= 0;--i){
        //cout<<((num - i*7))<<endl;
        if((num - i*7)%4 == 0){
            for(int j = (num - i*7)/4; j>0; --j){
                cout<<"4";
            }
            for(int j = i; j>0; --j){
                cout<<"7";
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    
    
    return 0;
}