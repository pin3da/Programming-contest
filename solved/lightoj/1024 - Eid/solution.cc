#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,n) for(int i=0; i<=(n); i++)
#define repf(i,a,b) for(int i=(a); i<=(b); i++)
#define repb(i,a,b) for (int i=(a); i>=b; i--)

#define MAX(x,y) ( ((x)>(y)) ? (x) : (y) )
#define MIN(x,y) ( ((x)<(y)) ? (x) : (y) )

#define REP(i,N) for((i)=0; (i)<(N); (i)++)
#define REPB(i,N) for((i)=(N)-1; (i)>=0; (i)--)

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
void bnDivIntF(BigInt *ans, BigInt *a, BigInt *b, BigInt *res);
void bnPowInt(BigInt *ans, BigInt *a, int b);
void bnPowModInt(BigInt *ans, BigInt *a, BigInt* b, BigInt *mod);
void bnIntToStr(char *ans, BigInt *a);
void bnCopyInt(BigInt *res, BigInt *a);
void bnStrToInt(BigInt *ans, const char *input);

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

void bnNegInt(BigInt* a) {
  if (a->sign == BN_NEG)
    a->sign=BN_POS;
  else
    a->sign=BN_NEG;
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

void bnShiftRBits(BigInt* res, BigInt* a, bn_word bits) {
  bn_word rdig[res->maxSize];
  bn_word carry, shdig, shbits, otbits, i, temp;
  bn_dword rshift;
  carry = 0;
  shdig = bits/WBITS; shbits = bits%WBITS; otbits = (WBITS-shbits);
  if(shdig>res->maxSize) {
    shdig = res->maxSize;
  }
  REP(i,shdig) {
    rdig[i]=0;
  }
  for(i = shdig; i < a->size-1; i++) {
    rshift = a->d[i+1];
    rshift = rshift << otbits;
    rdig[i-shdig] = (a->d[i] >> shbits) | ((bn_word) rshift);
  }
  if(a->size<shdig+1) {
    rdig[0] = 0;
    res->size = 1;
    res->sign = a->sign;
  }
  else {
    rdig[a->size-shdig-1] = (a->d[a->size-1] >> shbits);
    res->size = a->size-shdig;
    res->sign = a->sign;
  }
  copyw(res->d, rdig, res->size);
  bnRemCeros(res);
}

/**
 * Computes res = sum1+sum2 for BigInts.
 */
void bnAddInt(BigInt* res, BigInt* sum1, BigInt* sum2) {
  BigInt *a, *b;
  if (bnUCompareInt(sum1, sum2) > 0) {
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

/**
 * Computes res = a-b for BigInts
 */
void bnSubInt(BigInt* res, BigInt* a, BigInt* b) {
  bnNegInt(b);
  bnAddInt(res,a,b);
  bnNegInt(b);
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

void bnMulIntWord(BigInt* res, BigInt *a, bn_word b) {
  bn_word j, carry = 0;
  bn_dword m;
  REP(j, a->size) {
    m = ((bn_dword)b)*a->d[j];
    m += carry;
    res->d[j] = (bn_word)m;
    carry = (bn_word)(m >> WBITS);
  }
  res->d[j] = carry;
  res->size = a->size+1;
  res->sign = a->sign;
  bnRemCeros(res);
}

void bnMulInt(BigInt* res, BigInt* a, BigInt* b) {
  bn_word d1[res->maxSize]; d1[0]=0;
  BigInt tmp1; tmp1.size=1; tmp1.maxSize=res->maxSize; tmp1.sign=BN_POS; tmp1.d=d1;
  bn_word d2[res->maxSize]; d2[0]=0;
  BigInt tmp2; tmp2.size=1; tmp2.maxSize=res->maxSize; tmp2.sign=BN_POS; tmp2.d=d2;

  BigInt *tmp= &tmp1, *sum = &tmp2;
  bn_word i, j, carry;
  bn_dword m;
  //tmp = bnNewBigInt(res->maxSize,0); sum = bnNewBigInt(res->maxSize,0);

  REP(i, b->size) {
    bnMulIntWord(tmp,a,b->d[i]);
    bnShiftLBits(tmp,tmp,WBITS*i);
    bnAddInt(sum,sum,tmp);
  }
  //bn_word *swap=res->d; res->d=sum->d; sum->d=swap;
  //res->size = sum->size;
  //bnDelBigInt(tmp); bnDelBigInt(sum);
  bnCopyInt(res, sum);
  res->sign = (a->sign == b->sign) ? BN_POS : BN_NEG;
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
  BigInt *a = bnNewBigInt(x->size, 0);
  bnRemCeros(x);
  int k;
  bnCopyInt(a,x);
  while (a->size > 1 || a->d[0] >= 1000000000) {
    bnDivIntWord(a,a,1000000000,&res);
    for(j=8;j>=0;j--) {
      ans[i++] = (res % 10) + '0';
      res /= 10;
    }
  }
  bn_word lsw = a->d[0];
  while (lsw > 0) {
    ans[i++] = '0' + (lsw % 10);
    lsw /= 10;
  }
  if (x->sign==BN_NEG)
    ans[i++]='-';
  if(i == 0)
    ans[i++] = '0';
  ans[i] = '\0';
  invStr(ans, i);
  bnDelBigInt(a);
}

void bnCopyInt(BigInt* res, BigInt* a) {
  copyw(res->d,a->d,a->size);
  res->size = a->size;
  res->sign = a->sign;
}


void bnDivInt(BigInt* ans, BigInt* a, BigInt* b, BigInt* res) {
  BigInt *tmp=0, *cos=0;
  int i,j,bit;
  char sign = (a->sign == b->sign) ? BN_POS : BN_NEG;

  bn_word d1[res->maxSize]; d1[0]=0;
  BigInt tmp1; tmp1.size=1; tmp1.maxSize=res->maxSize; tmp1.sign=BN_POS; tmp1.d=d1;
  tmp = &tmp1;
  bn_word d2[ans->maxSize]; d2[0]=0;
  BigInt tmp2; tmp2.size=1; tmp2.maxSize=ans->maxSize; tmp2.sign=BN_POS; tmp2.d=d2;
  cos = &tmp2;

  tmp->sign=sign;  cos->sign = sign;

  if (b->size == 1) {
    bnDivIntWord(cos,a,b->d[0],&(tmp->d[0]));
    tmp->size=1;
  } else {
    if (bnUCompareInt(a,b) < 0) {
      cos->d[0]=0; cos->size=1; tmp->size=a->size;
      copyw(tmp->d,a->d,a->size);
    } else {
      bn_word opt1 = b->size-1;
      REP(i,opt1) {
        tmp->d[i] = a->d[a->size + i - opt1];
      }
      tmp->size = b->size-1; cos->d[0]=0; cos->size=1;
      REPB(i,(a->size-tmp->size)) {
        REPB(j,WBITS) {
          bit = (a->d[i]>>j) & 1;
          bnShiftLBits(tmp,tmp,1);
          tmp->d[0] |= bit;
          bnShiftLBits(cos,cos,1);
          if (bnUCompareInt(tmp,b) >= 0) {
            cos->d[0] |= 1;
            bnSubInt(tmp,tmp,b);
          }
        }
      }
      bnRemCeros(tmp); bnRemCeros(cos);
    }
  }
  if (ans != 0) bnCopyInt(ans, cos);
  if (res != 0) bnCopyInt(res, tmp);
}

bn_word numberOfLeadingZeros(bn_word i) {
  if (i == 0)
    return 32;
  bn_word n = 1;
  if (i >> 16 == 0) { n += 16; i <<= 16; }
  if (i >> 24 == 0) { n +=  8; i <<=  8; }
  if (i >> 28 == 0) { n +=  4; i <<=  4; }
  if (i >> 30 == 0) { n +=  2; i <<=  2; }
  n -= i >> 31;
  return n;
}


inline char stepD3(bn_dword v2, bn_word qs, bn_dword uj, bn_dword uj1, bn_dword v1, bn_dword uj2)
{
  /*      char a = ( (((double) v2) * qs - uj2) / BASE ) > ( (long long int) uj * BASE + uj1 - qs * v1 );
          char b; */
  bn_dword temp = (uj << WBITS) | uj1;
  bn_dword temp1 = qs * v1;
  bn_dword temp2 = v2 * qs;
  char sright = (temp >= temp1) ? 1 : 0;
  char sleft = (temp2 >= uj2) ? 1 : 0;
  if(sleft != sright)
    return sleft == 1;
  else if(sleft == 0) {
    bn_dword temp4 = (uj2 - temp2);
    bn_dword temp5 = temp4 >> WBITS;
    temp4 = temp1 - temp;
    return (temp5 < temp4);
  }
  else {
    bn_dword temp4 = (temp2 - uj2);
    bn_dword temp5 = temp4 >> WBITS;
    bn_dword temp6 = temp4 & WMASK;
    temp4 = temp - temp1;
    return (temp5 > temp4) || ((temp5 == temp4) && (temp6 != 0));
  }
}

void bnDivIntF(BigInt *ans, BigInt *a, BigInt *b, BigInt *res) {
  ans->sign = (a->sign == b->sign) ? BN_POS : BN_NEG;
  if(b->size == 1)
  {
    bnDivIntWord(ans, a, b->d[0], res == 0 ? 0 : &res->d[0]);
    if(res != 0) res->size = 1;
    return;
  }
  int resComp = bnUCompareInt(a, b);
  if(resComp < 0)
  {
    if(res != 0) bnCopyInt(res, a);
    ans->d[0] = 0;
    ans->size = 1;
    return;
  }
  if(resComp == 0)
  {
    ans->d[0] = 1;
    ans->size = 1;
    if(res != 0){
      res->d[0] = 0;
      res->size = 1;
    }
    return;
  }
  bn_word d1[a->size + 1]; d1[0] = 0;
  bn_word d2[b->size + 1]; d2[0] = 0;
  BigInt ud; ud.size=1; ud.sign=BN_POS; ud.d = d1;
  BigInt vd; vd.size=1; vd.sign=BN_POS; vd.d = d2;
  BigInt* u = &ud;
  BigInt* v = &vd;
#define V(i) ((bn_dword)v->d[v->size - (i)])
#define U(i) ((bn_dword)u->d[u->size - (i) - 1])
  bnCopyInt(u, a);
  bnCopyInt(v, b);
  bn_word m = u->size - v->size;
  bn_word n = v->size;
  bn_word shift = numberOfLeadingZeros(v->d[0]);
  bn_word d = BASE / (V(1) + 1);
  //    bnShiftRBits(u, u, shift);
  //    bnShiftRBits(v, v, shift);
  bnMulIntWord(u, u, d); bnMulIntWord(v, v, d);
  if(u->size == a->size) u->d[u->size++] = 0;
  bn_word j = 0, qs;
  bn_word d3[v->size + 2]; d3[0]=0;
  BigInt tmpd; tmpd.size=1; tmpd.sign=BN_POS; tmpd.d = d3;
  BigInt* tmp = &tmpd;
  ans->size = m + 1;
  BigInt uPrima;
  uPrima.d = &u->d[u->size - n - 1];
  uPrima.sign = BN_POS;
  uPrima.size = n + 1;
  uPrima.maxSize = uPrima.size;
  do {
    if (U(j) == V(1)) qs = WMASK;
    else qs = (U(j)*BASE + U(j+1)) / V(1);
    while (stepD3(V(2), qs, U(j), U(j+1), V(1), U(j+2))) qs--;
    bnMulIntWord(tmp, v, qs);
    bnRemCeros(&uPrima);
    if(bnUCompareInt(&uPrima, tmp) < 0)
    {
      qs--;
      bnSubInt(tmp, tmp, v);
    }
    bnSubInt(&uPrima, &uPrima, tmp);
    ans->d[m - j] = qs;
    uPrima.d--;
    uPrima.size = n + 1;
    j++;
  } while (j <= m);
  bnRemCeros(ans);
  BigInt uRes;
  uRes.d = u->d;
  uRes.sign = BN_POS;
  uRes.size = n;
  uRes.maxSize = uRes.size;
  bnRemCeros(&uRes);
  if(res != 0) bnDivIntWord(res, &uRes, d, 0);
  //bnDelBigInt(u); bnDelBigInt(v); bnDelBigInt(tmp);
#undef V
#undef U
}

void bnPowInt(BigInt* ans, BigInt* a, int b) {
  if (b==0) {
    ans->d[0]=1; ans->size=1; ans->sign=BN_POS;
  } else {
    BigInt* tmp = bnNewBigInt(a->size * b, 0);
    bnPowInt(tmp, a, b/2);
    bnMulInt(tmp, tmp, tmp);
    if ( (b & 1) == 1 ) {
      bnMulInt(tmp, tmp, a);
    }
    bnCopyInt(ans, tmp);
    bnDelBigInt(tmp);
  }
}

void bnPowModInt(BigInt *ans, BigInt *a, BigInt* b, BigInt *mod) {
  ans->d[0]=1; ans->size=1;
  BigInt *exponent = bnNewBigInt(b->size+1, 0);
  BigInt *base = bnNewBigInt(MAX(mod->size,a->size) + 1, 0);
  BigInt *tmp1 = bnNewBigInt(2*MAX(mod->size,a->size) + 1, 0);
  bnCopyInt(exponent, b); bnCopyInt(base, a);
  while (exponent->size > 1 || exponent->d[0]>0) {
    if ((exponent->d[0] & 1) == 1) {
      bnMulInt(tmp1, ans, base);
      bnDivIntF(tmp1, tmp1, mod, ans);
    }
    bnShiftRBits(exponent, exponent, 1);
    bnMulInt(tmp1, base, base);
    bnDivIntF(tmp1, tmp1, mod, base);
  }
  bnDelBigInt(exponent); bnDelBigInt(base); bnDelBigInt(tmp1);
}

void bnStrToInt(BigInt *ans, const char *input) {
  BigInt *tmp = bnNewBigInt(1,0);
  ans->size = 1; ans->d[0] = 0;
  int i=0,j; bn_word w;
  int pow10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
  char sign = BN_POS;
  if (input[0]=='-') {
    i++;
    sign = BN_NEG;
  }
  while (input[i] != '\0') {
    for (j=0, w=0; j<9; j++, i++) {
      if(input[i] == '\0') break;
      w *= 10; w += input[i]-0x30;
    }
    tmp->d[0]=pow10[j];
    bnMulInt(ans, ans, tmp);
    tmp->d[0]=w;
    bnAddInt(ans, ans, tmp);
  }
  ans->sign = sign;
  bnDelBigInt(tmp);
}

void gcd(BigInt *ans, BigInt *a, BigInt *b) {
  if (b->size<=1 && b->d[0]==0) {
    bnCopyInt(ans,a);
    return;
  }
  BigInt *tmp = bnNewBigInt(b->size,0);
  BigInt *tmp2 = bnNewBigInt(a->size,0);
  bnDivIntF(tmp2,a,b,tmp);
  gcd(tmp2,b,tmp);
  bnCopyInt(ans,tmp2);
  bnDelBigInt(tmp); bnDelBigInt(tmp2);
}

void lcm(BigInt *ans, BigInt *a, BigInt *b) {
  BigInt *tmp = bnNewBigInt(max(a->size,b->size),0);
  gcd(tmp,a,b);
  bnDivIntF(tmp,a,tmp,0);
  bnMulInt(ans,tmp,b);
  bnDelBigInt( tmp );
}

int m;
int a[1000];
char buf[100000];

void multilcm() {
  BigInt *b = bnNewBigInt(1000, a[0]);
  BigInt *tmp = bnNewBigInt(1,0);
  repf(i,1,m-1) {
    tmp->d[0] = a[i];
    lcm(b,b,tmp);
  }
  bnIntToStr(buf,b);
  printf("%s\n",buf);
  bnDelBigInt(b); bnDelBigInt(tmp);
}

int main(int argc, char **argv) {
  int n;
  scanf("%d",&n);
  rep(i,n) {
    scanf("%d", &m);
    rep(j,m) scanf("%d",&a[j]);
    /*int x = a[0];
      repf(j,1,m-1) {
      x = mcd(x,a[j]);
      }*/
    printf("Case %d: ",i+1);
    multilcm();
  }
}
