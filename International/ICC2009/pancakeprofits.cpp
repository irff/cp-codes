#include <cstdio>

int teskes,n,hasil;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        hasil=0;
        
        scanf("%d", &n);
        while(n>0) {
            hasil+=(n/5);
            n/=5;
        }
        printf("%d\n", hasil);
    }
    return 0;
}
