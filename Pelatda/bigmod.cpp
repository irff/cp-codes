#include <cstdio>

int a, b, c;
int pangkat(int a, int b) {
    if(b==0) return 1;
    int x = pangkat(a,b/2)%c;
    if(b%2) return x*x%c*a%c;
    return x*x%c;
}
int main() {
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", pangkat(a,b)%c);
    return 0;    
}
