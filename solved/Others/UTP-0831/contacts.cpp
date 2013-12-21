using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it,x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)



int main(){
    
    int c;
    int tid = 0;
    while(cin>>c and c){
        map< pair<string,string>, pair<set<string>,set<string> > >  todos;
        For(kk,c){
            string a,b,c;
            cin>>a>>b>>c;
            if(c.find("@")!=string::npos){
                todos[make_pair(b,a)].second.insert(c);
            }else{
                todos[make_pair(b,a)].first.insert(c);
            }
        }
        cout<<"Contact list #"<<(tid+1)<<":"<<endl;
        tid++;
        foreach(person,todos){
            cout<<person->first.second<<" "<<person->first.first<<endl;
            cout<<"Phone:"<<endl;
            foreach(number,person->second.first){
                cout<<"(";
                For(i,3)cout<<(*number)[i];
                cout<<")";
                for(int i = 3; i< 6; ++i)
                    cout<<(*number)[i];
                cout<<"-";
                for(int i = 6; i< 10; ++i)
                    cout<<(*number)[i];
                cout<<endl;
            }
            cout<<"E-Mail:"<<endl;
            foreach(em,person->second.second){
                cout<<(*em)<<endl;
            }
            cout<<"###"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
