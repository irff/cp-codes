#include <cstdio>
int main(){
    int n; scanf("%d",&n);
    while(n!=0){
        printf("%I64d\n", (n*(n+1)*(2*n+1))/6);
        scanf("%d",&n);
    }
}
