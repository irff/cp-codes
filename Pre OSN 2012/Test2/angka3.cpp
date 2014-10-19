#include <cstdio>

int n, bas;
void rek(int n) {
    if(n==0) return ;
    if(n > 0) {
        rek(n/bas);
        printf("%d", n%bas);
    }
}
int main() {
    scanf("%d%d", &n, &bas);
    rek(n);
    printf("\n");
    return 0;
}
