#include<stdio.h>
#include<stdlib.h>
#include<math.h>


    int b; 
    void mp_read() { b = getchar_unlocked(); }
    void mp_skip() { while (b >= 0 && b <= 32) mp_read(); }
    int mp_next_int() {
        int v = 0; int s = 0;
        mp_skip(); if (b == '-') { s = 1; mp_read(); }
        for (; b > 32; mp_read()) v = v*10 + b-48; return s ? -v : v; }
    int mp_has_next() { mp_skip(); return b > 0; }

/******** Big Int Library dev by Insilico UTP *******/

#define MAX(x,y) ( ((x)>(y)) ? (x) : (y) )
#define MIN(x,y) ( ((x)<(y)) ? (x) : (y) )

#define REP(i,N) for(i=0; i<(N); i++)
#define REPB(i,N) for(i=(N)-1; i>=0; i--)

typedef unsigned int bn_word;
typedef unsigned long long bn_dword;

void copyw(bn_word* res, bn_word* a, bn_word size) {
    int i;
    REP(i,size) {
        res[i] = a[i];
    }
}

void invStr(char* str, int n) {
    bn_word i=0;
    bn_word j=n-1;
    char tmp;
    while (i < j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++; j--;
    }
}

#define WBITS 32
#define BASE ( ((bn_dword)1) << WBITS )
#define WMASK ( BASE - 1 )
#define BN_NEG 0
#define BN_POS 1

/**
 * Structure that represents big integers, d[0] is the least significant
 * digit while d[size-1] is the most significant digit
 */
typedef struct {
    bn_word maxSize; /*Maximum number of digits that d can hold*/
    bn_word size; /*number of digits*/
    char sign; /*zero->negative, other->positive*/
    bn_word *d; /*value of each digits*/
} BigInt;

BigInt* bnNewBigInt(bn_word size, bn_word initVal);
void bnDelBigInt(BigInt *a);
int bnUCompareInt(BigInt *a, BigInt *b);
void bnNegInt(BigInt *a);
void bnShiftLBits(BigInt *res, BigInt *a, bn_word bits);
void bnShiftRBits(BigInt *res, BigInt *a, bn_word bits);
void bnAddInt(BigInt *res, BigInt *a, BigInt *b);
void bnSubInt(BigInt *res, BigInt *a, BigInt *b);
void bnMulInt(BigInt *res, BigInt *a, BigInt *b);
void bnMulIntWord(BigInt* res, BigInt *a, bn_word b);
void bnDivIntWord(BigInt *ans, BigInt *a, bn_word b, bn_word *res);
void bnDivInt(BigInt *ans, BigInt *a, BigInt *b, BigInt *res);
void bnPowInt(BigInt *ans, BigInt *a, int b);
void bnPowModInt(BigInt *ans, BigInt *a, BigInt* b, BigInt *mod);
void bnIntToStr(char *ans, BigInt *a);
void bnCopyInt(BigInt *res, BigInt *a);
void bnStrToInt(BigInt *ans, const char *input);
void bnMultIntK(BigInt *res, BigInt *a, BigInt *b);

/*Removes leading ceros*/
void bnRemCeros(BigInt *a) {
    while (a->size > 1 && a->d[ a->size-1 ] == 0)
        a->size--;
}

/*Suma a y b, independiente de que signos tenga; Se debe cumplir a>=b*/
void bnUAddInt(BigInt *res, BigInt *a, BigInt *b) {
    bn_word i,n,carry,tmp;
    bn_dword r;
    n = a->size;
    carry=0;
    REP(i,n) {
        tmp = (i < b->size) ? b->d[i] : 0;
        r = ((bn_dword)a->d[i]) + tmp;
        r += carry;
        res->d[i] = (bn_word)r;
        carry = (bn_word)(r>>WBITS);
    }
    if (carry != 0) {
        res->d[n++] = carry;
    }
    res->size=n;
}

/*resta a y b, independiente del signo; Se debe cumplir que a >= b*/
void bnUSubInt(BigInt *res, BigInt *a, BigInt *b) {
    bn_word borrow,i,n,tmp;
    bn_dword s,m,base;
    n = a->size;
    borrow=0;
    base = ((bn_dword)1 << WBITS);
    REP(i,n) {
        tmp = (i < b->size) ? b->d[i] : 0;
        s = a->d[i];
        m = ((bn_dword)tmp) + borrow;
        borrow=0;
        if (s < m) {
            s += base;
            borrow=1;
        }
        res->d[i] = (bn_word)(s-m);
    }
    res->size=n;
    bnRemCeros(res);
}

/**
 * Returns positive if a is greater than b, 0 if a is equal to b
 * or negative if a is less than b
 */
int bnUCompareInt(BigInt* a, BigInt* b) {
    if (a->size != b->size)
        return ((int)a->size) - ((int)b->size);
    int i;
    REPB(i,a->size) {
        if (a->d[i] > b->d[i]) return 1;
        else if (a->d[i] < b->d[i]) return -1;
    }
    return 0;
}

void bnShiftLBits(BigInt* res, BigInt* a, bn_word bits) {
    bn_word rdig[res->maxSize];
    bn_word carry, shdig, shbits, i;
    bn_dword lshift;
    carry = 0;
    shdig = bits/WBITS; shbits = bits%WBITS;
    REP(i,shdig) {
        rdig[i]=0;
    }
    REP(i,a->size) {
        lshift = a->d[i];
        lshift <<= shbits;
        lshift |= carry;
        rdig[i+shdig] = (bn_word)lshift;
        carry = (bn_word)(lshift >> WBITS);
    }
    rdig[i+shdig] = carry;
    res->size = a->size + shdig + 1;
    res->sign = a->sign;
    copyw(res->d, rdig, res->size);
    bnRemCeros(res);
}
/**
 * Computes res = sum1+sum2 for BigInts.
 */
void bnAddInt(BigInt* res, BigInt* sum1, BigInt* sum2) {
    BigInt *a, *b;
    if (bnUCompareInt(sum1, sum2) >= 0) {
        a=sum1; b=sum2;
    } else {
        a=sum2; b=sum1;
    }
    if (a->sign == b->sign) {
        bnUAddInt(res,a,b);
        res->sign = a->sign;
    } else {
        bnUSubInt(res,a,b);
        res->sign = a->sign;
    }
}


BigInt* bnNewBigInt(bn_word maxSize, bn_word initVal) {
    BigInt *a = (BigInt*) malloc(sizeof(BigInt));
    a->size=1;
    a->maxSize = maxSize;
    a->sign=BN_POS;
    a->d = 0;
    a->d = (bn_word*) malloc(maxSize * sizeof(bn_word));
    a->d[0] = initVal;
    return a;
}

void bnDelBigInt(BigInt* a) {
    bn_word *d = a->d;
    free(a);
    free(d);
}


void bnShiftLWords(BigInt *ans, BigInt *a, bn_word w) {
    int i;
    REPB(i,a->size) {
        ans->d[i+w] = a->d[i];
    }
    REP(i,w) ans->d[i]=0;
    ans->size = a->size + w;
}

/*ans = a / b ; res = a % b #División sin signo*/
void bnDivIntWord(BigInt* ans, BigInt* a, bn_word b, bn_word *res) {
    bn_dword num;
    bn_word carry; int i;
    carry = 0;
    REPB(i, a->size) {
        num = a->d[i] | ((bn_dword)carry)<<WBITS;
        ans->d[i] = (bn_word)(num / b);
        carry = (bn_word)(num % b);
    }
    ans->size = a->size; bnRemCeros(ans);
    ans->sign = a->sign;
    if (res != 0) *res = carry; 
}

void bnIntToStr(char* ans, BigInt* x) {
        char strres[15];
        int j;
    bn_word i=0, res;
    bnRemCeros(x);
    int k;
    while (x->size > 1 || x->d[0] >= 1000000000) {
        bnDivIntWord(x,x,1000000000,&res);
        for(j=8;j>=0;j--) {
                ans[i++] = (res % 10) + '0';
                res /= 10;
        }
    }
    bn_word lsw = x->d[0];
    while (lsw > 0) {
        ans[i++] = '0' + (lsw % 10);
        lsw /= 10;
    }    
    if(i == 0)
        ans[i++] = '0';
    ans[i] = '\0';
    invStr(ans, i);
}

void bnCopyInt(BigInt* res, BigInt* a) {
    copyw(res->d,a->d,a->size);
    res->size = a->size;
    res->sign = a->sign;
}

/******** End Big In Library *******/


int main(){
    mp_read();
    int n,k;
    char buffer[50];
    BigInt *a=bnNewBigInt(6,0);
    BigInt *ans=bnNewBigInt(6,0);
    BigInt *one = bnNewBigInt(6,1);
    while(mp_has_next()){
        n = mp_next_int();
        if(n==0)putc('0',stdout);
        else if( n==1)putc('1',stdout);
        else if(n==2)putc('3',stdout);
        else if(n==3)putc('5',stdout);
        else{
            k = (int)floor(sqrt(n<<1) + 0.5);
            a->d[0] =  ((n-2)<<1) - k*(k-3);
            bnShiftLBits(ans,a,k-2);
            ans->d[0]|=1;
            bnIntToStr(buffer,ans);
            fputs(buffer,stdout);
        }
        putc('\n',stdout);
    }
    bnDelBigInt(a);
    bnDelBigInt(ans);
    bnDelBigInt(one);
    return 0;
}
