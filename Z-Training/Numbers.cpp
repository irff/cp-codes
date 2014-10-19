#include <cstdio>

const int INF=2000111222;

int n,size,now;
int x[100111],c;
int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++) x[i]=INF;
    x[0]=-INF; int now=1,size=1;
    for(int i=0; i<n; i++){
        scanf("%d", &c);
        now=size;
        while(x[now-1]>c) now--;
        x[now]=c;
        if(now==size) size++;
    }
    printf("%d\n", size-1);
    return 0;
}
