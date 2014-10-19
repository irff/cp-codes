#include <cstdio>

int n, hasil;
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        if(n%i==0) hasil+=i;
    }
    printf("%d\n", hasil);
    return 0;
}
