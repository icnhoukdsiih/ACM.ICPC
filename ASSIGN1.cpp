// PREPARING ACM.ICPC 2018
// ASSIGN1 - CODED BY ICNHOUKDSIIH
// CONTACT ME: https://icnhoukdsiih.blogspot.com/

#include <bits/stdc++.h>

using namespace std;

//mx[i] là chỉ số công việc giao cho người i, my[i] là chỉ số người được giao công việc i
//pre[i] xác định chỉ số bên x duyệt tới i bên y trong quá trình tìm đường mở
//que là hàng đợi lưu các chỉ số bên x trong quá trình tìm đường mở
int n,a[201][201],mx[201],my[201],pre[201],res,q[201],head,tail,mid; 

//Tìm đường mở với các cạnh nối có trọng số <=value
int findpath(int value) {
    for (int i=1;i<=n;i++) pre[i]=0;
    bool fr[201]={0}; //Đánh dấu đỉnh nào đưa vào q
    int d=0, c=0;
    //Chọn các đỉnh bên x chưa ghép đưa vào q
    for (int i=1;i<=n;i++)
    if (mx[i]==0) {
        q[++c]=i;
        fr[i]=1;
    }
    while (d<c) {
        d++;
	//Xét các đỉnh bên y sao cho trọng số nối đỉnh x hiện tại <=value và kiểm tra 
        for (int i=1;i<=n;i++)
        if (a[q[d]][i]<=value)
            if (my[i]==0 || (my[i]!=0 && fr[my[i]]==0)) {
                pre[i]=q[d];
                if (my[i]==0) return i; //Nếu đỉnh bên y chưa ghép cạnh nào bên x thì tìm được đường mở
                q[++c]=my[i]; //Ngược lại đưa đỉnh bên x mà đỉnh bên y hiện tại nối với nó vào q
                fr[my[i]]=1; //Đánh dấu đỉnh đã đưa vào q
            }
    }
    return 0; //Không tìm được đường mở
}

//Tăng cặp ghép
void match(int nodey) {
    int next;
    do {
        next=mx[pre[nodey]];
        mx[pre[nodey]]=nodey;
        my[nodey]=pre[nodey];
        nodey=next;
    } while (nodey!=0);
}

//Kiểm tra với việc xây dựng cặp ghép với các cạnh có trọng số <=value có phân hết việc được không
bool matchok(int value) {
    for (int i=1;i<=n;i++) {
        mx[i]=0;
        my[i]=0;
    }
    int finish,cou=0;
    while (finish=findpath(value)) {
        match(finish);
        cou++;
    }
    if (cou==n) return 1;
    return 0;
}

int main() {
    //Đọc dữ liệu
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
    //Chặt nhị phân tìm trọng số nhỏ nhất mà phân hết việc
    head=1; tail=1e9;
    while (head<=tail) {
        mid=(head+tail)/2;
        if (matchok(mid)) {
            res=mid;
            tail=mid-1;
        }
        else head=mid+1;
    }
    printf("%d",res);
    return 0;
}
