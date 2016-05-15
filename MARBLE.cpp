// PREPARING ACM.ICPC 2018
// MARBLE - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/
//--------------------------------------------------

#include <stdio.h>
#define maxn 50000 //Gioi han kich thuoc ma tran

typedef long long ll;
typedef struct Element //Dinh nghia mot nut tron IT
{
    ll Min, Max; //GTLN, GTNN trong nut dang xet
    bool childupdate; //Kiem tra hai nut con da duoc cap nhat chua
} E;

//Left, Right, Top, Bottom la 4 IT dung de tim GTLN, GTNN cua cac doan trong moi nut ung voi bien trai, phai, tren va duoi
E Left[4*maxn+1],Right[4*maxn+1], Top[4*maxn+1], Bottom[4*maxn+1];
ll n,k,q;

//Khoi tao 1 IT
void init(E *a, ll value)
{
    for (ll i=1;i<=4*n;i++)
    {
        a[i].Max=value;
        a[i].Min=value;
        a[i].childupdate=true;
    }
}

//Cap nhat GTLN cua moi o trong doan [l..r] cua IT a
void updatemax(ll current, ll Front, ll Rear, ll l, ll r, ll value, E *a)
{
    if (Front>r || Rear<l || a[current].Min>=value) return;
    if (Front>=l && Rear<=r && a[current].Max<=value)
    {
        a[current].Max=value;
        a[current].Min=value;
        //Danh dau 2 nut con chua duoc cap nhat va return
        a[current].childupdate=false;
        return;
    }
    if (Front<Rear)
    {
        ll Mid=(Front+Rear)/2;
        //Neu hai nut con chua cap nhat thong tin tu nut cha thi cap nhat
        if (a[current].childupdate==false)
        {
            a[current*2].Max=a[current].Max;
            a[current*2].Min=a[current].Min;
            a[current*2].childupdate=false;
            a[current*2+1].Max=a[current].Max;
            a[current*2+1].Min=a[current].Min;
            a[current*2+1].childupdate=false;
            a[current].childupdate=true;
        }
        //Cap nhat lai hai nut con va cap nhat nut cha  tu hai nut con
        updatemax(current*2,Front,Mid,l,r,value,a);
        updatemax(current*2+1,Mid+1,Rear,l,r,value,a);
        a[current].Max=a[current*2].Max>a[current*2+1].Max?a[current*2].Max:a[current*2+1].Max;
        a[current].Min=a[current*2].Min<a[current*2+1].Min?a[current*2].Min:a[current*2+1].Min;
    }
}

//Cap nhat GTNN moi o trong doan [l..r] cua IT a
void updatemin(ll current, ll Front, ll Rear, ll l, ll r, ll value, E *a)
{
    if (Front>r || Rear<l || a[current].Max<=value) return;
    if (Front>=l && Rear<=r && a[current].Min>=value)
    {
        a[current].Max=value;
        a[current].Min=value;
        //Danh dau 2 nut con chua duoc cap nhat va return
        a[current].childupdate=false;
        return;
    }
    if (Front<Rear)
    {
        ll Mid=(Front+Rear)/2;
        //Neu nut con chua cap nhat tu cha thi cap nhat
        if (a[current].childupdate==false)
        {
            a[current*2].Max=a[current].Max;
            a[current*2].Min=a[current].Min;
            a[current*2].childupdate=false;
            a[current*2+1].Max=a[current].Max;
            a[current*2+1].Min=a[current].Min;
            a[current*2+1].childupdate=false;
            a[current].childupdate=true;
        }
        //Cap nhat thong tin nut con va nut cha cap nhat lai tu nut con
        updatemin(current*2,Front,Mid,l,r,value,a);
        updatemin(current*2+1,Mid+1,Rear,l,r,value,a);
        a[current].Max=a[current*2].Max>a[current*2+1].Max?a[current*2].Max:a[current*2+1].Max;
        a[current].Min=a[current*2].Min<a[current*2+1].Min?a[current*2].Min:a[current*2+1].Min;
    }
}

//Tim o gan bien nhat tai vi tri pos
ll Find(ll current, ll Front, ll Rear, ll pos, E *a)
{
    if (Front==Rear) return a[current].Max;
    ll Mid=(Front+Rear)/2;
    //Neu nut con chua cap nhat tu cha thi tien hanh cap nhat
    if (a[current].childupdate==false)
    {
        a[current*2].Max=a[current].Max;
        a[current*2].Min=a[current].Min;
        a[current*2].childupdate=false;
        a[current*2+1].Max=a[current].Max;
        a[current*2+1].Min=a[current].Min;
        a[current*2+1].childupdate=false;
        a[current].childupdate=true;
    }
    if (Mid>=pos) return Find(current*2,Front,Mid,pos,a);
    return Find(current*2+1,Mid+1,Rear,pos,a);
}

int main()
{
    //Doc thong tin du lieu vao
    scanf("%lld%lld%lld",&n,&k,&q);
    init(Left,n+1);
    init(Top,n+1);
    init(Right,0);
    init(Bottom,0);
    //Doc thong tin k o ban dau va cap nhat cac cay
    for (int i=0;i<k;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        updatemin(1,1,n,u,u,v,Left);
        updatemax(1,1,n,u,u,v,Right);
        updatemin(1,1,n,v,v,u,Top);
        updatemax(1,1,n,v,v,u,Bottom);
    }
    //Doc cac truy van va xu ly truy van tuong ung
    for (int i=0;i<q;i++)
    {
        char c='.';
        ll D,u,v,res=0,pos; //res la ket qua can tim
        do scanf("%c",&c); while ((c>='A' && c<='Z')==false);
        scanf("%lld%lld%lld",&D,&u,&v);
        switch (c)
        {
        case 'L':
            {
                pos=Find(1,1,n,u,Left);
                if (pos!=n+1)
                {
                    ll head=pos-D>0?pos-D:1;
                    res=(pos-1+head)*(pos-head)/2;
                    updatemin(1,1,n,u,u,head,Left);
                    if (head<pos)
                    {
                        updatemin(1,1,n,head,pos-1,u,Top);
                        updatemax(1,1,n,head,pos-1,u,Bottom);
                    }
                }
                else res=D*n;
                break;
            }
        case 'R':
            {
                pos=Find(1,1,n,u,Right);
                if (pos!=0)
                {
                    ll tail=pos+D<=n?pos+D:n;
                    res=(n-pos+n-tail+1)*(tail-pos)/2;
                    updatemax(1,1,n,u,u,tail,Right);
                    if (pos<tail)
                    {
                        updatemin(1,1,n,pos+1,tail,u,Top);
                        updatemax(1,1,n,pos+1,tail,u,Bottom);
                    }
                }
                else res=D*n;
                break;
            }
        case 'T':
            {
                pos=Find(1,1,n,v,Top);
                if (pos!=n+1)
                {
                    ll head=pos-D>0?pos-D:1;
                    res=(pos-1+head)*(pos-head)/2;
                    updatemin(1,1,n,v,v,head,Top);
                    if (head<pos)
                    {
                        updatemin(1,1,n,head,pos-1,v,Left);
                        updatemax(1,1,n,head,pos-1,v,Right);
                    }
                }
                else res=D*n;
                break;
            }
        case 'B':
            {
                pos=Find(1,1,n,v,Bottom);
                if (pos!=0)
                {
                    ll tail=pos+D<=n?pos+D:n;
                    res=(n-pos+n-tail+1)*(tail-pos)/2;
                    updatemax(1,1,n,v,v,tail,Bottom);
                    if (pos<tail)
                    {
                        updatemin(1,1,n,pos+1,tail,v,Left);
                        updatemax(1,1,n,pos+1,tail,v,Right);
                    }
                }
                else res=D*n;
                break;
            }
        default:break;
        }
        printf("%lld\n",res);
    }
    return 0;
}
