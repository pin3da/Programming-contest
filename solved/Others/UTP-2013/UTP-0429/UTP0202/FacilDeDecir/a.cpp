/*
Manuel Pineda
Carlos Gonzáles.
accepted.
*/

lusing namespace std;
#include<string>
#include<iostream>
#include<vector>

vector<char> vocals,cons;
int isVoc(char a);
int fun();
int fun2();

int main(){
    string cad;
    int i,a,b;
    while(cin>>cad){
          if(cad=="end")break;
          a=0;
          b=1;
          vocals.clear();
          cons.clear();  
          for(i=0;i<cad.size();i++){
              	if(a==0){
                 	a=isVoc(cad[i]);
              	}
              	if(isVoc(cad[i])){
                 	vocals.push_back(cad[i]);
                 	cons.clear();
              	}else{
                 	cons.push_back(cad[i]);
                 	vocals.clear();
              	}
           	if(fun()==0 || fun2()==0){
                 	b=0;
                 	break;        
              	}
              if(vocals.size()==3||cons.size()==3){
                 b=0;
                 break;
              } 
          }
          cout<<'<'<<cad<<'>'<<" is";
          if(a==0 || b ==0){
                  cout<<" not";
          }
          cout<<" acceptable."<<endl;
    }
}
int isVoc(char a){
    if(a == 'a'||a == 'e'||a == 'i'||a == 'o'||a == 'u')    
         return 1;
    else
        return 0;
}

int fun(){
    char a,b;
    for(int i=0;i+1<vocals.size();i++){
            a=vocals[i];
            b=vocals[i+1];
            if(a==b && a!='e' && a!='o')
                return 0;
    }
    return 1;
}

int fun2(){
    char a,b;
    for(int i=0;i+1<cons.size();i++){
            a=cons[i];
            b=cons[i+1];
            if(a==b)
               return 0;
    }
    return 1;
}
