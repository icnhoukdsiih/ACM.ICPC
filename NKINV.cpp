// PREPARING ACM.ICPC 2018
// NKLINEUP - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <iostream>
#include <stdio.h>
#define Max 60000 //Gioi han so phan tu cua mang

using namespace std;

int n,a[Max+1]={0},res=0; //a la BIT dung de tinh so phan tu nam trong mot doan | ket qua bai toan la res

int Find(int val)
{
    int Count=0;
    while (val>0)
    {
        Count+=a[val];
        val=val-(val & -val);
    }
    return Count;
}

int main()
{
    //Doc so phan tu va gia tri cac phan tu
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int val;
        scanf("%d",&val);
        //Dem so luong cac so lon hon val, cung chinh la so cap nghich the co phan tu ket thuc tai i
        res+=i-1-Find(val);
        //Cap nhat BIT
        while (val<=Max)
        {
            a[val]++;
            val=val+(val & -val);
        }
    }
    printf("%d",res);
    return 0;
}
