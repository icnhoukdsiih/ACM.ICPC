// PREPARING ACM.ICPC 2018
// NKLINEUP - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <iostream>
#define Maxn 50000 //So phan tu toi da trong mang

//Cau truc bieu dien 1 nut trong cay IT gom hai thanh phan: GTLN va tong
typedef struct Element
{
    int Sum, Max;
} E;

using namespace std;

int n,m;
E a[Maxn*4+1]; //Cay IT dung de tinh tong va GTLN trong mot doan

//Khoi tao GTLN va tong ban dau cua cac doan trong cay
void init()
{
    for (int i=1;i<=4*n;i++)
    {
        a[i].Max=0;
        a[i].Sum=0;
    }
}

//Cap nhat GTLN va tong cua cac doan nam trong [left..right]
void update(int current, int Front, int Rear, int left, int right, int value)
{
    //Neu doan dang xet khong giao voi [left..right] thi return
    if (Front>right || Rear<left) return;
    //Neu doan dang xet nam trong [left..right] thi cap nhat Max, Sum cua no
    if (Front>=left && Rear<=right)
    {
        a[current].Max+=value;
        a[current].Sum+=value*(Rear-Front+1);
        return;
    }
    //Chia doan hien tai lam hai, cap nhat lai hai nut con tu thong tin nut cha
    int Mid=(Front+Rear)/2,sumchild=a[current*2].Sum+a[current*2+1].Sum;
    int incleft=(a[current].Sum-sumchild)/(Rear-Front+1)*(Mid-Front+1);
    int incright=a[current].Sum-sumchild-incleft;
    a[current*2].Sum+=incleft;
    a[current*2].Max+=incleft/(Mid-Front+1);
    a[current*2+1].Sum+=incright;
    a[current*2+1].Max+=incright/(Rear-Mid);
    //Cap nhat gia tri hai nut con khi moi phan tu trong [left..right] tang value
    update(current*2,Front,Mid,left,right,value);
    update(current*2+1,Mid+1,Rear,left,right,value);
    //Cap nhat nut cha sau khi cap nhat hai nut con
    a[current].Sum=a[current*2].Sum+a[current*2+1].Sum;
    a[current].Max=a[current*2].Max>a[current*2+1].Max?a[current*2].Max:a[current*2+1].Max;
}

//Tim GTLN trong doan [left..right]
void findmax(int current, int Front, int Rear, int left, int right, int &res)
{
    //Neu doan dang xet khong giao voi [left..right] thi return
    if (Front>right || Rear<left) return;
    //Neu doan dang xet nam trong [left..right] thi cap nhat res
    if (Front>=left && Rear<=right)
    {
        if (res<a[current].Max) res=a[current].Max;
        return;
    }
    //Chia doan hien tai thanh 2 nut con, cap nhat gia tri cua 2 nut tu nut cha
    int Mid=(Front+Rear)/2,sumchild=a[current*2].Sum+a[current*2+1].Sum;
    int incleft=(a[current].Sum-sumchild)/(Rear-Front+1)*(Mid-Front+1);
    int incright=a[current].Sum-sumchild-incleft;
    a[current*2].Sum+=incleft;
    a[current*2].Max+=incleft/(Mid-Front+1);
    a[current*2+1].Sum+=incright;
    a[current*2+1].Max+=incright/(Rear-Mid);
    //Tim GTLN cua cac phan tu thuoc [left..right] trong hai doan con
    findmax(current*2,Front,Mid,left,right,res);
    findmax(current*2+1,Mid+1,Rear,left,right,res);
}

int main()
{
    //Doc m,m; xet cac truy van va xu ly
    cin>>n>>m;
    init();
    for (int i=1;i<=m;i++)
    {
        int type,x,y,value;
        cin>>type>>x>>y;
        if (type==0)
        {
            cin>>value;
            update(1,1,n,x,y,value);
        }
        else
        {
            int res=0;
            findmax(1,1,n,x,y,res);
            cout<<res<<endl;
        }
    }
    return 0;
}
