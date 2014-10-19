#include <cstdio>

int n,repetitions=0;
int main() {
    scanf("%d", &n);
    while(n>1) {
        if(n%2==0) n/=2;
        else n=3*n+1;
        repetitions++;
    }
    printf("%d\n", repetitions);
    
    return 0;
}
