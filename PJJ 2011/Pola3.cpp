#include <cstdio>


int main(){
    int n,k;
    scanf("%d%d", &n,&k);
    for(int i=1; i<=n; i++){
        if(i%k==0) printf("*");
        else printf("%d", i);
        if(i!=n) printf(" ");
    }
    printf("\n");
    return 0;
}
