using namespace std;
#include<iostream>
#include<string>

int main(){
    int numcas,ind,vec;
    string cad;
    cin>>numcas;
    while(numcas--){
        cin>>ind;
        cin>>vec;
        cin>>cad;
        cout<<ind<<" ";
        for(int i=0;i<cad.size();i++)
            for(int j=0;j<vec;j++)
                cout<<cad[i];
        cout<<endl;
    }
    
    return 0;
}
