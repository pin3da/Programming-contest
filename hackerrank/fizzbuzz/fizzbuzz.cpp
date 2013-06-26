using namespace std;
#include<iostream>
#include<sstream>
#include<string>
template<class T> string a(T t){stringstream s; s<<t; return s.str();}
int main(){
    for(int i=1;i<101;++i)
        cout<<(((i%3)+(i%5))?(i%3)?(i%5)? a(i):"Buzz":"Fizz":"FizzBuzz")<<endl;    
}


