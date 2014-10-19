#include <cstdio>

int n,lis[1222],lisa[1222],a[1222],x[1222],y[1222];
int main(){
    x[0]=-2000111222;
    scanf("%d", &n);
    int now=1,size=1;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        now=size;
        while(x[now-1]>=a[i]) now--;
        x[now]=a[i];
        if(now==size) size++;
        lis[i]=now;
    }
    y[0]=-2000111222;
    now=1;size=1;
    int ma=-1,mb;
    for(int i=n-1; i>=0; i--){
        now=size;
        while(y[now-1]>=a[i]) now--;
        y[now]=a[i];
        if(now==size) size++;
        if(lis[i]+now>ma) { ma=lis[i]+now; mb=a[i]; }
    }
    printf("%d %d\n", mb, ma-1);
}
