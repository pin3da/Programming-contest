using namespace std;
#include<iostream>
#include<string>
#include<map>
#include<set>
#define For(i,n) for(int i =0;i<(n);++i)
#define foreach(it,x) for(typeof((x).begin()) it  = (x).begin(); it != (x).end(); ++it)
#define mit(it,x) typeof (x).begin() it = (x).begin()
#define D(x) cout<< #x " = "<<(x)<<endl

int main(){
    int m,ini,tar,pasos;
    while(cin>>m>>ini>>tar>>pasos and m+ini+tar+pasos){
        map<string,string> mutation;
        map<string,int> initial;
        map<string,int> target;

        string cad,cad2;
        int deterministic = 1;
        For(i,m){
            cin>>cad>>cad2;
            if(mutation.count(cad) > 0){
                deterministic &= cad2 == mutation[cad];
            }
            mutation[cad] = cad2;
        }
        int veces;
        For(i,ini){
            cin>>cad>>veces;
            initial[cad]+=veces;
        }
        For(i,tar){
            cin>>cad>>veces;
            target[cad]+=veces;
        }
        if(!deterministic){
            cout<<"Protein mutations are not deterministic"<<endl;
            continue;
        }
        int cura=-1;
        For(i,pasos+1){
           /* foreach(x,initial){
                cout<<"cad "<<x->first<<" : "<<x->second<<endl;
            }*/
            mit(x,initial);
            mit(y,target);
            while(x != initial.end() and y != target.end()){
                if(x->first != y->first or x->second != y->second)break;
                x++;y++;
            }
            if(x==initial.end() and y==target.end()){
                cura=i;
                break;
            }
            map<string,int > tmp;
            foreach(x,initial){
                if(mutation.count(x->first)>0)
                    tmp[mutation[x->first]]+=x->second;
                else
                    tmp[x->first]+=x->second;
            }
            initial = tmp;
        }
        
        if(cura != -1)
            cout<<"Cure found in "<<cura<<" mutation(s)"<<endl;
        else
            cout<<"Nostalgia for Infinity is doomed"<<endl;
    }
    return 0;
}
