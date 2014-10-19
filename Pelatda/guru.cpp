#include <cstdio>
#include <cmath>


int num, n, hasil;
int main() {
    scanf("%d", &num);
    n = (int)sqrt(2*num);
    for(int i=n-1; i<=n+1; i++) {
        if(i*(i+1)/2 > num) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
