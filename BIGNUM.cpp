// PREPARING ACM.ICPC 2018
// BIGNUM - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

struct bignum {
    int n;
    int a[2002];
};
void reset(bignum &num) {
    for (int i=0;i<=2000;i++) num.a[i]=0;
}
void read(bignum &num) {
    char s[1002];
    scanf("%s%*c",s);
    num.n=strlen(s);
    reset(num);
    for (int i=num.n-1;i>=0;i--) num.a[num.n-i-1]=s[i]-'0';
}
void cong(bignum A, bignum B, bignum &C) {
    reset(C);
    int nho=0,l=(A.n>B.n?A.n:B.n);
    C.n=l;
    for (int i=0;i<l;i++) {
        C.a[i]=(A.a[i]+B.a[i]+nho)%10;
        nho=(A.a[i]+B.a[i]+nho)/10;
    }
    if (nho>0) {
        C.a[C.n]=nho;
        C.n++;
    }
}
bool compare(bignum A, bignum B) {
    if (A.n>B.n) return 1;
    if (A.n<B.n) return 0;
    for (int i=A.n-1;i>=0;i--)
    if (A.a[i]!=B.a[i]) {
        if (A.a[i]>=B.a[i]) return 1;
        else return 0;
    }
}
void tru(bignum A, bignum B, bignum &C, int dau) {
    reset(C);
    int nho=0;
    for (int i=0;i<A.n;i++) {
    C.a[i]=A.a[i]-B.a[i]-nho;
    nho=0;
    while (C.a[i]<0) {
        nho++;
        C.a[i]+=10;
    }
    }
    C.n=A.n;
    while (C.n>1 && C.a[C.n-1]==0) C.n--;
    C.a[C.n-1]*=dau;
}
void nhan(bignum A, bignum B, bignum &C) {
    reset(C);
    for (int i=0;i<A.n;i++)
    for (int j=0;j<B.n;j++)
    C.a[i+j]+=A.a[i]*B.a[j];
    C.n=0;
    for (int i=0;i<A.n+B.n;i++) {
        C.a[i+1]+=C.a[i]/10;
        C.a[i]%=10;
    }
    C.n=A.n+B.n;
    while (C.n>1 && C.a[C.n-1]==0) C.n--;
}
void xuat(bignum C) {
    for (int i=C.n-1;i>=0;i--) printf("%d",C.a[i]);
    printf("\n");
}
int main()
{
    bignum A,B,C;
    read(A);
    read(B);
    cong(A,B,C);
    xuat(C);
    if (compare(A,B)) tru(A,B,C,1);
    else tru(B,A,C,-1);
    xuat(C);
    nhan(A,B,C);
    xuat(C);
    return 0;
}
