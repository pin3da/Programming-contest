#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#define D(x) cout<< #x " = "<<(x)<<endl

using namespace std;

struct anagram{
    string ident;
    multiset<string> todas;    
    bool operator < (const anagram &o) const {
        if(todas.size() == o.todas.size())
            return *todas.begin() < *(o.todas.begin());
        return todas.size() > o.todas.size();
    }
};

int main(){
    string word;
    map<string,multiset<string> >anagrams;
    while(cin>>word){
        string p = word;
        sort(p.begin(),p.end());
        anagrams[p].insert(word);
    }
    vector<anagram> todos(anagrams.size());
    int i = 0;
    for(map<string,multiset<string> >::iterator it = anagrams.begin(); it != anagrams.end(); ++it){
        todos[i].ident = it->first;
        todos[i++].todas = it->second;
    }
    
    sort(todos.begin(), todos.end());
    for(int i = 0; i < min(5,(int)todos.size()); ++i){
        cout<<"Group of size "<<todos[i].todas.size()<<":";
        set<string> tmp;
        for(multiset<string>::iterator word = todos[i].todas.begin(); word != todos[i].todas.end(); ++word){
            //cout<<" "<<*word;
            tmp.insert(*word);
        }
        for(set<string>::iterator word = tmp.begin(); word != tmp.end(); ++word){
            cout<<" "<<*word;
        }
        
        cout<<" ."<<endl;
    }
    
    return 0;
}
