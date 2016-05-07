// PREPARING ACM.ICPC 2018
// NKLINEUP - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <iostream>
#define MaxN 50000 //Gioi han cua N
#define Max_height 1000000

typedef struct height //Do cao lon nhat va nho nhat trong 1 doan
{
    int Max;
    int Min;
} h;
using namespace std;

int N,Q,A,B;
h a[4*MaxN+1]; //Cay IT

void init() //Khoi tao gia tri cay IT
{
    for (int i=1;i<=4*N;i++)
    {
        a[i].Min=Max_height+1;
        a[i].Max=0;
    }
}

void update(int current, int Front, int Rear, int pos, int value) //Cap nhat do cao cua mot con bo trong cay IT
{
    if (Front==Rear) //Neu doan dang xet chinh la pos thi cap nhat gia tri
    {
        a[current].Max=value;
        a[current].Min=value;
        return;
    }
    // Chia doan lam 2, tim doan chua pos va cap nhat
    int Mid=(Front+Rear)/2;
    if (Front<=pos && pos<=Mid)
    {
        update(current*2,Front, Mid, pos, value);
        if (a[current].Max<a[current*2].Max) a[current].Max=a[current*2].Max;
        if (a[current].Min>a[current*2].Min) a[current].Min=a[current*2].Min;
    }
    else
    {
        update(current*2+1, Mid+1, Rear, pos,value);
        if (a[current].Max<a[current*2+1].Max) a[current].Max=a[current*2+1].Max;
        if (a[current].Min>a[current*2+1].Min) a[current].Min=a[current*2+1].Min;
    }
}

//Tim do cao lon nhat cac con bo trong [Left..Right]
void find_max(int current, int Front, int Rear, int Left, int Right, int &result)
{
    //Kiem tra [Front..Rear] khong ton tai hoac khong giao voi [Left..Right] thi return
    if (Front>Right || Rear<Left || Front>Rear) return;
    if (Front>=Left && Rear<=Right) //Neu doan dang xet nam trong [Left..Right] thi cap nhat ket qua
    {
        if (result<a[current].Max) result=a[current].Max;
        return;
    }
    //Chia de tri de tim ket qua
    int Mid=(Front+Rear)/2;
    find_max(current*2,Front,Mid,Left,Right,result);
    find_max(current*2+1, Mid+1, Rear, Left, Right, result);
}

//Tuong tu nhu find_max
void find_min(int current, int Front, int Rear, int Left, int Right, int &result)
{
    if (Front>Right || Rear<Left || Front>Rear) return;
    if (Front>=Left && Rear<=Right)
    {
        if (result>a[current].Min) result=a[current].Min;
        return;
    }
    int Mid=(Front+Rear)/2;
    find_min(current*2,Front,Mid,Left,Right,result);
    find_min(current*2+1, Mid+1, Rear, Left, Right, result);
}

int main()
{
    cin>>N>>Q; //Doc du lieu
    init();
    for (int i=1;i<=N;i++)
    {
        int value;
        cin>>value;
        update(1,1,N,i,value);
    }
    //Doc cac truy van va xu ly
    for (int i=1;i<=Q;i++)
    {
        cin>>A>>B;
        int max_height=0;
        //Tim do cao lon nhat va nho nhat cua cac con bo trong [A..B]
        find_max(1,1,N,A,B,max_height);
        int min_height=Max_height+1;
        find_min(1,1,N,A,B,min_height);
        cout<<max_height-min_height<<endl;
    }
    return 0;
}
