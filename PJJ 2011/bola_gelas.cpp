#include <cstdio>

int nkasus,npindah,ngelas;
int a[200000],b[200000],c[200000];
int main(){
    scanf("%d%d", &ngelas,&npindah);
    for(int i=1; i<=ngelas; i++) c[i]=i;
    for(int i=0; i<npindah; i++){
        int x,y;
        scanf("%d%d", &x,&y);
        int tmp=c[x];
        c[x]=c[y];
        c[y]=tmp;
        /*for(int j=1; j<=ngelas; j++) printf("%d ",j);
        puts("");
        for(int j=1; j<=ngelas; j++) printf("%d ", c[j]);
        */
    }
    scanf("%d", &nkasus);
    while(nkasus--){
        int x=0;
        scanf("%d", &x);
        /*
        for(int i=npindah-1; i>=0; i--){
            if(a[i]==x){
                x=b[i];
            } else
            if(b[i]==x){
                x=a[i];
            }
        }
        */
        printf("%d\n", c[x]);
    }
    return 0;
}
