/*
ManuelPineda, accepted.
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include <cassert>

vector<int> vec;
string tfun;
int pos;

int eval_exp() {
    assert(pos<tfun.length());
    if(tfun.at(pos)=='(') {
        pos=pos+1;
        int rand1=eval_exp();
        assert(pos<tfun.length());
        char oper=tfun.at(pos);
        
        pos++;
        int rand2=eval_exp();
        
        pos++;
        
        switch(oper) {
            case '+': return rand1+rand2;
            case '-': return rand1-rand2;
            case '*': return rand1*rand2;
        }
        assert(false);
        return 0;
    }
    else {
        char var=tfun.at(pos);
        pos++;
        return var-'0';

        assert(false);
        return 0;
    }
}

int main(){
    int numterm,tmp,resp,val;
    string fun;
    while(1){
        cin>>numterm;
        if(numterm==0)break;
        vec.clear();
        while(numterm--){
            cin>>tmp;
            vec.push_back(tmp);
        }
        cin>>resp;
        sort(vec.begin(),vec.end());
        cin>>fun;
        val=0;
        do{
             int k=0;
             tfun=fun;
             
             for(int i=0;i<tfun.size();i++){
                     if(tfun[i]!='(' && tfun[i]!=')' && tfun[i]!='+' && tfun[i]!='-' && tfun[i]!='*'){
                                tfun[i]= vec[k++]+'0';             
                     }                       
             }
            pos=0;
            if(eval_exp()==resp){
                val=1;
                break;    
            }
        }while(next_permutation(vec.begin(),vec.end()));
        
        if(val==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;       
    }
    return 0;
}




