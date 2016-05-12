// PREPARING ACM.ICPC 2018
// NKMOBILE - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#define maxs 1024 //Gioi han cua s

int s,val,bit[maxs+1][maxs+1]={0}; //val dung de xac dinh loai truy van | bit la cay BIT 2 chieu dung luu tru tong cac o trung mien no quan ly

//Cap nhat thong tin cay BIT
void solve1()
{
    int x,y,a;
    scanf("%d%d%d",&x,&y,&a);
    x++; y++;
    int posx=x;
    while (posx<=s)
    {
        int posy=y;
        while (posy<=s)
        {
            bit[posx][posy]+=a;
            posy=posy+(posy & -posy);
        }
        posx=posx+(posx & -posx);
    }
}

//Tinh tong cac o thuoc cac dong trong doan [1..row], cot trong doan [left..right] nho vao thong tin cua BIT
int sum(int row, int left, int right)
{
    int res=0;
    while (row>0)
    {
        int column=right;
        while (column>0)
        {
            res+=bit[row][column];
            column=column - (column & -column);
        }
        column=left-1;
        while (column>0)
        {
            res-=bit[row][column];
            column=column - (column & -column);
        }
        row=row - (row & -row);
    }
    return res;
}

//Xu ly ket qua mot truy van tren BIT
void solve2()
{
    int l,b,r,t;
    scanf("%d%d%d%d",&l,&b,&r,&t);
    //Ket qua cua doan [l..r]x[b..t] chinh la ket qua [1..r]x[b..t]-[1..l-1]x[b..t]
    printf("%d\n",sum(r+1,b+1,t+1)-sum(l,b+1,t+1));
}

int main()
{
    //Doc kich thuoc s va thuc hien cac truy van
    //Luu y toa do danh so tu 0 toi s-1 nen ta phai tang cac toa do len 1 de xu ly duoc tren BIT
    scanf("%d%d",&val,&s);
    while (val!=3)
    {
        scanf("%d",&val);
        if (val==3) break;
        if (val==1) solve1();
        else solve2();
    }
    return 0;
}
