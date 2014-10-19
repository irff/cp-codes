#include <cstdio>

const int MOD = 1000000;

int teskes,n;
int fib[10000111];

int main() {
    fib[0]=1; fib[1]=1;
    for(int i=2; i<10000001; i++) fib[i]=(fib[i-1] + fib[i-2]) % MOD;
    scanf("%d", &teskes);
    for(int i=0; i<teskes; i++) {
        scanf("%d", &n);
        printf("%d\n", fib[n]);
    }
    return 0;
}
