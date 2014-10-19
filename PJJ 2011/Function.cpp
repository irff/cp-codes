#include <cstdio>

int n;
int main(){
    scanf("%d", &n);
    if(n>=0 and n<=10) {
        int x=1;
        for(int i=2; i<=n; i++) x*=i;
        printf("%d\n", x);
    }
    else printf("ditolak\n");
    return 0;
}
