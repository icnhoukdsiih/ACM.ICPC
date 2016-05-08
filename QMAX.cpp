// PREPARING ACM.ICPC 2018
// NKLINEUP - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <iostream>
#define Maxn 50000

using namespace std;

//a bieu dien cay IT the hien tong cac doan, b la cay IT bieu dien GTLN trong cac doan
int n,m,a[4*Maxn+1],b[4*Maxn+1],p;
//Khoi tao cay IT voi cac phan tu ban dau co gia tri bang 0

void init_a()
{
    for (int i=1;i<=4*n;i++) a[i]=0;
}

//Cap nhat cac doan thuoc [u..v] sau khi cac phan tu trong doan nay co gia tri tang len k
void update_a(int current, int Front, int Rear, int u, int v, int k)
{
    //Neu doan dang xet khong giao voi doan can cap nhat thi return
    if (Front>v || Rear<u) return;
    if (Front>=u && Rear<=v)
    {
        a[current]+=k*(Rear-Front+1);
        return;
    }
    //Chia ra lam 2 doan con va cap nhat gia tri
    int Mid=(Front+Rear)/2,sum_child=a[current*2]+a[current*2+1]; //Cap nhat gia tri nut con truoc khi tang
    a[current*2]+=(a[current]-sum_child)/(Rear-Front+1)*(Mid-Front+1);
    a[current*2+1]=a[current]-a[current*2];
    update_a(current*2,Front,Mid,u,v,k);
    update_a(current*2+1,Mid+1,Rear,u,v,k);
    a[current]=a[current*2]+a[current*2+1];
}

// Tim gia tri phan tu vi tri pos cua mang
int get_value(int current, int Front, int Rear, int pos)
{
    //Neu doan dang xet co do dai 1 thi xuat ra gia tri phan tu vi tri pos
    if (Front==Rear) return a[current];
    //Cap nhat gia tri 2 nut con
    int Mid=(Front+Rear)/2;
    int sum_child=a[current*2]+a[current*2+1];
    a[current*2]+=(a[current]-sum_child)/(Rear-Front+1)*(Mid-Front+1);
    a[current*2+1]=a[current]-a[current*2];
    //Duyet nut con chua pos
    if (Mid>=pos) return get_value(current*2,Front,Mid,pos);
    return get_value(current*2+1,Mid+1,Rear,pos);
}

//Khoi tao gia tri lon nhat cua cac doan trong cay IT
void init_b()
{
    for (int i=1;i<=4*n;i++) b[i]=0;
}
void update_b(int current, int Front, int Rear, int pos, int value)
{
    //Neu nut dang xet co mot phan tu thi cap nhat GTLN
    if (Front==Rear)
    {
        b[current]=value;
        return;
    }
    //Chia lam 2 nut con va cap nhat nut co chua pos, cuoi cung cap nhat lai nut cha
    int Mid=(Front+Rear)/2;
    if (Mid>=pos) update_b(current*2,Front,Mid,pos,value);
    else update_b(current*2+1,Mid+1,Rear,pos,value);
    b[current]=b[current*2]>b[current*2+1]?b[current*2]:b[current*2+1];
}

void findmax(int current, int Front, int Rear, int u, int v, int &res)
{
    //Neu nut dang xet khong giao voi [u..v] thi return
    if (Front>v || Rear<u) return;
    //Neu nut dang xet nam trong [u..v] thi cap nhat res
    if (Front>=u && Rear<=v)
    {
        if (res<b[current]) res=b[current];
        return;
    }
    //Chia lam 2 nut con va cap nhat ket qua
    int Mid=(Front+Rear)/2;
    findmax(current*2,Front, Mid, u,v,res);
    findmax(current*2+1,Mid+1,Rear,u,v,res);
}

int main()
{
    //Doc so phan tu va m truy van
    cin>>n>>m;
    init_a();
    for (int i=1;i<=m;i++)
    {
        int u,v,k;
        cin>>u>>v>>k;
        update_a(1,1,n,u,v,k);
    }
    //Khoi tao va tim gia tri cac phan tu, cap nhat vao IT
    init_b();
    for (int i=1;i<=n;i++) update_b(1,1,n,i,get_value(1,1,n,i));
    //Doc p yeu cau va xuat ket qua
    cin>>p;
    for (int i=1;i<=p;i++)
    {
        int u,v,res=0;
        cin>>u>>v;
        findmax(1,1,n,u,v,res);
        cout<<res<<endl;
    }
    return 0;
}
