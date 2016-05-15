// PREPARING ACM.ICPC 2018
// HEAP1 - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#define maxn 20000 //So thanh go toi da

typedef long long ll;

ll t,n, heap[maxn+1], nheap,res; //heap dung de luu do dai cac thanh go voi do uu tien cua cac thanh nho hon la lon hon

//Day mot thanh go vao heap
void push(ll value)
{
    ll child=++nheap,father;
    while (child>=1)
    {
        father=child/2;
        if (father==0 || heap[father]<=value) break;
        heap[child]=heap[father];
        child=father;
    }
    heap[child]=value;
}

//Lay thanh go ngan nhat ra khoi heap
ll pop()
{
    ll result=heap[1], value=heap[nheap--];
    ll father=1,child;
    while (father<=nheap)
    {
        child=father*2;
        if (child<nheap && heap[child]>heap[child+1]) child++;
        if (child>nheap || heap[child]>=value) break;
        heap[father]=heap[child];
        father=child;
    }
    heap[father]=value;
    return result;
}

int main()
{
    //Doc du lieu dau vao va xu ly
    scanf("%lld",&t);
    for (ll c=0;c<t;c++)
    {
        nheap=0;
        res=0;
        scanf("%lld",&n);
        //Doc va day tung thanh go vao heap
        for (ll i=0;i<n;i++)
        {
            ll value;
            scanf("%lld",&value);
            push(value);
        }
        //Moi buoc lay hai thanh ngan nhat va cap nhat ket qua, ghep hai thanh lai va day vao heap
        for (ll i=0;i<n-1;i++)
        {
            ll value=pop()+pop();
            res+=value;
            push(value);
        }
        printf("%lld\n",res);
    }
    return 0;
}
