#include <cstdio>
#include <algorithm>
using namespace std;

int a[12], hasil=0, n;
int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) a[i]=i;
    
    while(next_permutation(a+1,a+n+1) ) {
        int x=0;
        for(int i=1; i<=n; i++) {
            if( a[i] != i) x++;
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("%d\n", x);
        if(x == n) {
            hasil++;
            for(int i=1; i<=n; i++) printf("%d ", a[i]);
            printf("\n");
        }
    }
    printf("%d\n", hasil);
    return 0;
}
