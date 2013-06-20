using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <cstring>

#define all(c) (c).begin(),(c).end()
#define D(x) cout<< #x " = "<<(x)<<endl

template<class T> int to_int(T t){stringstream ss; ss<<t; int r;ss>>r; return r;}

int main(){
    int n,m;
    while(cin>>n>>m and (n+m)){
        int cinema[n+5][m+5];
        memset(cinema,0,sizeof(cinema));
        int r;cin>>r;
        for(int i = 0; i< r; ++i){
            string name;cin>>name;
            int a = name[0]- 'A';
            int b = to_int(name.substr(1));
            cin>>name;
            if(name == "-")b--;
            cinema[a][b] = 1;
        }
        cin>>r;
        vector<pair<int,int> > queries(r);
        for(int i = 0; i< r; ++i){
            string name;cin>>name;
            int a = name[0]- 'A';
            int b = to_int(name.substr(1));
            queries[i].first = a;
            queries[i].second = b;
        }

        sort(all(queries));
        int paila = 0;
        for(int i = 0; i< r and !paila; ++i){
            int x = queries[i].first;
            int y = queries[i].second;
            if(cinema[x][y-1] == 0) cinema[x][y-1] = 1;
            else if (cinema[x][y] == 0) cinema[x][y] = 1;
            else paila = 1;
        }
        if(paila)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}


