// PREPARING ACM.ICPC 2018
// KINV - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define maxn 10000 //So phan tu toi da cua mang
#define maxk 10 //Do dai toi da day nghich the

typedef long long ll;
const ll mod=1e9;
using namespace std;
typedef struct element //Struct luu tru thong tin ve gia tri va vi tri cua phan tu
{
    ll value,pos;
} E;

//Place dung de xac dinh vi tri cac phan tu cua mang sau khi sap xep
//Head dung de xac dinh vi tri phan tu dau tien co gia tri bang phan tu hien tai sau khi sap xep
/*q[][i] (1<=i<=k) la BIT tinh so day nghich the do dai i trong cac doan ma no quan ly.
Moi doan [i..j] la so day nghich the trong doan [a[i]..a[j]] sau khi sap xep*/
ll n,k,place[maxn+1],q[maxn+1][maxk+1]={0},head[maxn+1];
E a[maxn+1]; //Luu tru thong tin cac phan tu trong mang

int compare(const void *a, const void *b)
{
    return ((*(E*)a).value<(*(E*)b).value);
}

//Cap nhat thong tin nut pos cua day nghich the do dai length, gia tri tang len la val
void update(ll pos, ll length, ll val)
{
    while (pos<=n)
    {
        q[pos][length]=(q[pos][length]+val)%mod;
        pos=pos+(pos & -pos);
    }
}

//Tim so day nghich the co do dai length trong doan tu [1..pos] cua day da sap xep
void Find(ll pos, ll length, ll &res)
{
    while (pos>0)
    {
        res=(res+q[pos][length])%mod;
        pos=pos-(pos & -pos);
    }
}

int main()
{
    //Doc thong tin cua cac phan tu
    scanf("%I64d%I64d",&n,&k);
    for (ll i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i].value);
        a[i].pos=i;
    }
    //Sap xep mang, cap nhat head va place
    qsort(a+1,n,sizeof(E),compare);
    head[1]=1;
    for (ll i=2;i<=n;i++)
        if (a[i].value==a[i-1].value) head[i]=head[i-1];
        else head[i]=i;
    for (ll i=1;i<=n;i++) place[a[i].pos]=i;
    //Cap nhat thong tin BIT theo thu tu cac phan tu nhap vao
    for (ll i=1;i<=n;i++)
    {
        //Neu co phan tu bang a[place[i]] thi chi can cap nhat tai nut head[place[i]]
        update(head[place[i]],1,1); //Cap nhat day nghich the do dai 1
        for (ll j=2;j<=k;j++)
        {
            ll Count=0;
            Find(head[place[i]]-1,j-1,Count); //Dem so day nghich the do dai j-1 trong doan [1..head[place[i]]-1]
            update(head[place[i]],j,Count); //Cap nhat day nghich the do dai j
        }
    }
    ll Count=0;
    Find(n,k,Count); //Dem so day nghich the do dai k trong doan tu [a[1]..a[k]]
    printf("%I64d",Count%mod);
    return 0;
}
