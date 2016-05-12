// PREPARING ACM.ICPC 2018
// CRATE - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#define maxpoint 100001 //Gioi ham diem
#define maxn 300000 //Gioi han so coders

typedef struct coder //Kieu cau truc luu tru thong tin coder
{
    int p1, p2, pos,res;
    //p1, p2 la diem hai giai dau | pos la thu tu thong tin vao cua coders | res la ket qua can tim
} c;

int n,q[maxpoint+1]={0},place[maxn+1]; //q la cay BIT, place dung de danh dau coders o vi tri ban dau sau khi sap xep nam o dau
c a[maxn+1]; //Luu thong tin nhap vao cua cac coders
int compare (const void * a, const void * b)
{
  return ((*(c*)a).p1 > (*(c*)b).p1 || ((*(c*)a).p1 == (*(c*)b).p1 && (*(c*)a).p2 > (*(c*)b).p2));
}

void update(int pos, int num) //Cap nhat so coder trong cac nut chua pos
{
    q[pos]+=num;
    while (pos+(pos & -pos)<=maxpoint)
    {
        pos=pos+(pos & -pos);
        q[pos]+=num;
    }
}

void Find(int pos, int &res) //Tim so coder co diem p2 tu 1 den pos
{
    while (pos>0)
    {
        res+=q[pos];
        pos=pos-(pos & -pos);
    }
}

int main()
{
    //Doc thong tin cac coder
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].p1,&a[i].p2);
        a[i].p1+=1;
        a[i].p2+=1;
        a[i].pos=i+1;
    }
    qsort(a,n,sizeof(c),compare);
    int i=0;
    while (i<n)
    {
        int j=i,res=0;
        while (j<n-1 && a[j].p1==a[j+1].p1 && a[j].p2==a[j+1].p2) j++; //Dem so coder cung diem p1 va p2
        Find(a[i].p2,res);
        for (int k=i;k<=j;k++) a[k].res=res;
        update(a[i].p2,j-i+1);
        i=j+1;
    }
    for (int i=0;i<n;i++) place[a[i].pos]=i;
    for (int i=1;i<=n;i++) printf("%d\n",a[place[i]].res);
    return 0;
}
