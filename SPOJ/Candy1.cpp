#include <cstdio>

int n,a[10111],rat,jum,has;
int main(){
    scanf("%d", &n);
    while(n!=-1){
        jum=0;has=0;
        for(int i=0; i<n; i++) scanf("%d", &a[i]),jum+=a[i];
        rat=jum/n; 
        if(rat*n!=jum) printf("-1\n");
        else {
            for(int i=0; i<n; i++) if(a[i]<=rat) has+=rat-a[i];           
            printf("%d\n", has);
        }
        scanf("%d", &n);
    }

    return 0;
}
