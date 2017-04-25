// http://codeforces.com/contest/4/problem/C

using namespace std;
#include<iostream>
#include<map>
#include<string>

int main(){
    int cuantos;cin>>cuantos;
    map<string,int> mio;
    while(cuantos--){
        string tmp;cin>>tmp;
        if(mio.count(tmp)==0){
            cout<<"OK";
        }else{
            cout<<tmp<< (mio[tmp]);
        }
        cout<<endl;
        mio[tmp]++;
    }
    return 0;

}