// PREPARING ACM.ICPC 2018
// NKTEAM - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#define maxn 100000 //Gioi han so thi sinh

//a the hien xep hang cua moi nguoi, a[i][j] la xep hang cua nguoi co so hieu i trong ki thi thu j+1
//pos la mang ma pos[i] the hien chi so cua nguoi co xep hang i trong ki thi thu nhat
/*bit la cay BIT dung de cap nhat min a[][1] tren mang a[][2] (a[i][1] se cap nhat tren nut a[i][2])
sau khi sap xep a theo a[][0] (nho mang pos)*/
//res dung de dem so thi sinh khong phai la xuat sac
int pos[maxn+1],a[maxn+1][3],bit[maxn+1],res=0,n;
void Swap(int &v1, int &v2)
{
    int tmp=v1;
    v1=v2;
    v2=tmp;
}

int main()
{
    //Doc thong tin, xac dinh moi thi sinh se xep hang o vi tri nao
    scanf("%d",&n);
    for (int i=0;i<3;i++)
        for (int j=1;j<=n;j++)
        {
            int val;
            scanf("%d",&val);
            a[val][i]=j;
        }
    //Cap nhat thong tin pos[i] (la so hieu thi sinh co xep hang i)
    for (int i=1;i<=n;i++)
        pos[a[i][0]]=i;
    //Sap xep a theo a[][0]
    for (int i=1;i<=n;i++)
    {
        Swap(a[pos[i]][0],a[i][0]);
        Swap(a[pos[i]][1],a[i][1]);
        Swap(a[pos[i]][2],a[i][2]);
        pos[a[pos[i]][0]]=pos[i];
    }
    //Khoi tao BIT
    for (int i=1;i<=n;i++) bit[i]=n+1;
    //Cap nhat BIT tu thong tin a[][1] roi xac dinh thi sinh hien tai co ai gioi hon khong
    for (int i=1;i<=n;i++)
    {
        int place=a[i][2];
        while (place<=n)
        {
            if (bit[place]>a[i][1]) bit[place]=a[i][1];
            place=place+(place & -place);
        }
        place=a[i][2];
        while (place>0)
        {
            if (bit[place]<a[i][1])
            {
                res++;
                break;
            }
            place=place-(place & -place);
        }
    }
    printf("%d",n-res);
    return 0;
}

