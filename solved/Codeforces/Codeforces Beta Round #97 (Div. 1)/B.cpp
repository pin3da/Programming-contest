// http://codeforces.com/contest/135/problem/B

using namespace std;
#include<bits/stdc++.h>
#define For(i,n) for(int i = 0; i< (n); ++i)
#define foreach(it,n) for(typeof ((n).begin()) it = n.begin();  it != (n).end(); ++it )
#define D(x) cout<<#x " = "<<(x)<<endl
#define all(x) x.begin(),x.end()

struct point{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
};

int compare(point a,point b){
    return (a.x == b.x) and (a.y==b.y);
}

pair<int,int> resta(pair<int,int> a,pair<int,int> b){
    return make_pair(a.first-b.first,a.second -b.second);
}

pair<int,int> suma(pair<int,int> a,pair<int,int> b){
    return make_pair(a.first+b.first, a.second +b.second);
}

int _distance(pair<int,int> a,pair<int,int> b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    return x*x  + y*y;

}

int cross(pair<int,int> a,pair<int,int> b){
   return a.first * b.first + a.second*b.second;

}

int main(){
    
    vector<pair<int,int> > todos(8);
    map<pair<int,int>, int> cod;
    For(i,8){
        cin>>todos[i].first>>todos[i].second;
        cod[todos[i]] = i+1;
    }
    
    sort(all(todos));
    
    do{
        if(cross(resta(todos[1],todos[0]), resta(todos[2],todos[0]) ) == 0 and 
           cross(resta(todos[1],todos[3]), resta(todos[2],todos[3]) ) == 0 and
           cross(resta(todos[5],todos[4]), resta(todos[6],todos[4]) ) == 0 and  
           cross(resta(todos[5],todos[7]), resta(todos[6],todos[7]) ) == 0 )
           
           {
                int target = _distance(todos[1],todos[0]);
                
                if(target==0)continue;
                if( target == _distance(todos[3],todos[2]) and 
                    target == _distance(todos[2],todos[0]) and 
                    target == _distance(todos[3],todos[1])  )
                    
                    
                    {

                        cout<<"YES"<<endl;
                        For(kk,4){
                            cout<<cod[todos[kk]]<<" ";
                        }
                        cout<<endl;
                        For(kk,4){
                            cout<<cod[todos[kk+4]]<<" ";
                        }
                        cout<<endl;
                        return 0;
                        
                        
                    }
           }
           
           
    }while(next_permutation(all(todos)));
    
    cout<<"NO"<<endl;

    return 0;
}