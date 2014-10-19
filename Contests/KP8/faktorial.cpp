#include <cstdio>

int teskes,n;
long long faktorial;
int main () {
    
    while(scanf("%d", &teskes) and teskes!=0) {
        for(int i=0; i<teskes; i++) {
            scanf("%d", &n);
            for(int i=1,faktorial=1; i<=n; i++) faktorial*=i;
            printf("%lld\n", faktorial);
        }
    }
    
    return 0;
}
