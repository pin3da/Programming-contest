using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)

template<class t> 
int to_int(t r){stringstream ss; ss<<r; int k; ss>>k; return k;}

int main(){
    int tc;
    string line;
    getline(cin,line);
    tc = to_int(line);
    For(tid,tc){
        cout<<"Brett Log #"<<tid+1<<":"<<endl;
        int names;
        getline(cin,line);
        names = to_int(line);
        vector<string> cities(names);
        For(i,names){
            getline(cin,line);
            cities[i] = line;
        }
        string anterior = "";
        int queries;
        getline(cin,line);
        queries = to_int(line);
        For(i,queries){
            getline(cin,line);
            For(j,names){
                if(line.find(cities[j])!=string::npos and anterior != cities[j] ){
                    cout<<"   "<<line<<endl;
                    anterior = cities[j];
                    break;
                }
            }
        }
        cout<<endl;
    
    }
    return 0;

}
