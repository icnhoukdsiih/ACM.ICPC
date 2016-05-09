// PREPARING ACM.ICPC 2018
// NKLINEUP - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <iostream>
#include <stdio.h>
#define Maxmn 100000 //So con bo va so truy van toi da
//Kieu cau truc bieu dien 1 nut cua cay IT
typedef struct element
{
    int Count; //Dem so bong den sang
    bool childupdate; //Kiem tra cac nut con duoc cap nhat hay chua
} E;
using namespace std;

int n,m;
E a[4*Maxmn+1];//a la cay IT
//Khoi tao cay IT, ban dau so den sang moi nut bang 0
void init()
{
    for (int i=1;i<=4*n;i++)
    {
        a[i].Count=0;
        a[i].childupdate=true;
    }
}

//Cap nhat so bong den sang trong cac doan thuoc [left..right] khi cac
void update(int current, int Front, int Rear, int left, int right)
{
    //Neu doan dang xet khong giao voi [left..right] thi return
    if (Front>right || Rear<left) return;
    //Neu doan dang xet nam trong [left..right] thi cap nhat so den sang
    if (Front>=left && Rear<=right)
    {
        a[current].Count=Rear-Front+1-a[current].Count;
        a[current].childupdate=1-a[current].childupdate;
        return;
    }
    int Mid=(Front+Rear)/2;
    //Cap nhat hai nut con tu thong tin nut cha
    if (a[current].childupdate==false)
    {
        a[current*2].Count=Mid-Front+1-a[current*2].Count;
        a[current*2].childupdate=1-a[current*2].childupdate;
        a[current*2+1].Count=Rear-Mid-a[current*2+1].Count;
        a[current*2+1].childupdate=1-a[current*2+1].childupdate;
        a[current].childupdate=true;
    }
    //Cap nhat so den sang o 2 doan con
    update(current*2,Front,Mid,left,right);
    update(current*2+1,Mid+1,Rear,left,right);
    //Cap nhat lai so den sang o doan cha
    a[current].Count=a[current*2].Count+a[current*2+1].Count;
}

//Dem so den sang trong doan [left..right]
int res(int current, int Front, int Rear, int left, int right)
{
    //Neu doan dang xet khong giao voi [left..right] thi ket qua la 0
    if (Front>right || Rear<left) return 0;
    //Neu doan dang xet nam trong [left..right] thi ket qua chinh la so den sang trong doan do
    if (Front>=left && Rear<=right) return a[current].Count;
    int Mid=(Front+Rear)/2;
    //Cap nhat hai nut con tu thong tin nut cha
    if (a[current].childupdate==false)
    {
        a[current*2].Count=Mid-Front+1-a[current*2].Count;
        a[current*2].childupdate=1-a[current*2].childupdate;
        a[current*2+1].Count=Rear-Mid-a[current*2+1].Count;
        a[current*2+1].childupdate=1-a[current*2+1].childupdate;
        a[current].childupdate=true;
    }
    //Ket qua la tong so den sang cua 2 phan co cac den thuoc [left..right]
    return res(current*2,Front,Mid,left,right)+res(current*2+1,Mid+1,Rear,left,right);
}
int main()
{
    //Doc so con bo, so truy van va xu ly
    scanf("%d%d",&n,&m);
    init();
    for (int i=1;i<=m;i++)
    {
        int type,s,e;
        scanf("%d%d%d",&type,&s,&e);
        if (type==0) update(1,1,n,s,e);
        else printf("%d\n",res(1,1,n,s,e));
    }
    return 0;
}
