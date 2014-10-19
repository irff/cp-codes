#include <cstdio>

int n,x;
int main(){
    x=1;
    scanf("%d", &n);
    for(int i=2; i*i<=n; i++){
        if(n%i==0) { x=(n/i); break; }
    }
    printf("%d\n", n-x);
    scanf("\n");
    return 0;
}
