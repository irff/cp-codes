#include <cstdio>

int n;

int fak(int n) {
    if(n==0) return 1;
    return fak(n-1)*n;
}

int main() {
    scanf("%d", &n);
    if(n<0 or n>10) printf("ditolak\n");
    else {
        printf("%d\n", fak(n));
    }

    return 0;
}
