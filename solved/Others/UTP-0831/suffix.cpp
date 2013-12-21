using namespace std;
#include<bits/stdc++.h>


int main(){
    int n;cin>>n;
    for(int ii = 1; ii<= n; ++ii){
        string a,b;cin>>a>>b;
        string pp=a,qq=b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i = 0;
        for(; i < a.size() - 1 and i < b.size() -1 and a[i]==b[i]; ++i);
        cout<<"Game #"<<ii<<":"<<endl;
        
        cout<<"   The input words are "<<pp<<" and "<<qq<<"."<<endl;

        cout<<"   The words entered in the notebook are ";
        for(int j = a.size() -1; j >= i; --j)
            cout<<a[j];
        cout<<" and ";
        for(int j = b.size() -1; j >= i; --j)
            cout<<b[j];
        cout<<"."<<endl<<endl;
        
    }
    return 0;
}
