#include <cstdio>

long long n;
int a[100111];
int map[10000];
int main() {
    a[1]=1; a[2]=2; a[3]=3;
    for(int i=4; i<=100000; i++) {
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10000;
        printf("%d %d\n", i, a[i]);
        if(map[a[i]]>1) {
            printf("XXX %d\n", i);
            break;
        }
        map[a[i]]++;
    }
    for(int i=1; i<=20; i++) printf("%d %d\n", i, a[i]);

    return 0;
}
