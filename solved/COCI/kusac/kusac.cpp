using namespace std;
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<(x)<<endl

template<typename T>
struct Fraction {
    T p, q;

    Fraction() : p(0), q(1) {}
    Fraction(T P) : p(P), q(1) {}
    Fraction(T P, T Q) : p(P), q(Q) { simplify();}
    void simplify() {
        T g = __gcd(p, q);
        p /= g;
        q /= g;
    }
    Fraction operator+(const Fraction &f) const {
        return Fraction(p * f.q + q * f.p, q * f.q);
    }
    Fraction operator-(const Fraction &f) const {
        return Fraction(p * f.q - q * f.p, q * f.q);
    }
    Fraction operator*(const Fraction &f) const {
        return Fraction(p * f.p, q * f.q);
    }
    Fraction operator/(const Fraction &f) const {
        return Fraction(p * f.q, q * f.p);
    }
    Fraction operator%(int m) const {
        return Fraction(p % (m*q), q);
    }
    Fraction operator-() const { return Fraction(-p, q); }
    bool operator<(const Fraction &f) const { return p*f.q < q*f.p; }
    bool operator>(const Fraction &f) const { return p*f.q > q*f.p; }
    bool operator<=(const Fraction &f) const { return p*f.q <= q*f.p; }
    bool operator>=(const Fraction &f) const { return p*f.q >= q*f.p; }
    bool operator==(const Fraction &f) const { return p == f.p && q == f.q; }
};

typedef Fraction<int> fraction;

ostream &operator<<(ostream &os, const fraction &f) {
  os << "(" << f.p << "/" << f.q << ")"; 
}


int main(){
    int n,m;
    cin>>n>>m;
    
    /*if(n%m == 0){
        cout<<0<<endl;
        return 0;
    }*/
    fraction a(n),b(m);
    fraction target = a/b;
    int ans = 0;
    queue<fraction> Q;
    if(target >= fraction(1)){
        int sobra = n - m*(target.p/target.q);
        a = fraction(sobra);
        n = sobra;
        target = a/b;
    }
    fraction portion(1,target.q);
    fraction tengo(1);
    while(!(tengo==target)){
        tengo = tengo - portion;
        ans++;
    }
    ans*=n;
    cout<<ans<<endl;    
    return 0;
}
