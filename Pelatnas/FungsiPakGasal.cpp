#include <cstdio>

typedef long long LLD;

LLD n;
int a[100123];
int set[10000];
int main(){
    
    a[1]=1; a[2]=2; a[3]=3;
    for(int i=4; i<=100000; i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10000;
    }
    
    scanf("%d", &n);
    printf("%d\n", a[n]);
    return 0;
}
