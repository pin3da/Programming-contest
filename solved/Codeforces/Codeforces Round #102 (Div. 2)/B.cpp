// http://codeforces.com/contest/143/problem/B

using namespace std;
#include<bits/stdc++.h>


int main(){
    string cad;
    while(cin>>cad){
        int neg = 0;
        int index = 0;
        if(cad[0] == '-'){
            neg = 1;
            index++;
        }
        if(neg)cout<<"(";
        cout<<"$";
        string tales;
        while(index < cad.size() and cad[index]!='.'){
            tales = cad[index] + tales;
            index++;
        }
        index++;
        string tmp;
        for(int i = 1; i <= tales.size(); ++i){
            tmp+=tales[i-1];
            if((i%3)==0 and i!=tales.size())tmp+=",";
        }
        reverse(tmp.begin(),tmp.end());
        cout<<tmp;
        cout<<".";
        int impresos = 0;
        while(index < cad.size() and impresos < 2){
            cout<<cad[index++];
            impresos++;
        }
        while(impresos < 2){
            cout<<"0";
            impresos++;
        }
        
        if(neg)cout<<")";
        cout<<endl;

    }
    return 0;
}